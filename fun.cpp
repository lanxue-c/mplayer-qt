#include "fun.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int filelrc(LRC **head,char *filename)//打开文件，读取文件内容，并有序链表插入
{
    int i = 0;
    //打开文件读取内容
    FILE *fp = fopen(filename,"r");
    if(!fp)
    {
        perror("lrc_fopen");
        *head = NULL;
        return -1;
    }
    fseek(fp,0,SEEK_END);
    int len = ftell(fp);
    rewind(fp);
    char *buf = (char *)calloc(1,len+1);
    fread(buf,len,1,fp);
    fclose(fp);
    //格式化读取文件前4行
    char *p_buf = strtok(buf,"\r\n");
    if(!p_buf)
    {
        perror("strtok");
        return -2;
    }
    LRC *new_lrc = (LRC *)calloc(1,sizeof(LRC));
    sscanf(p_buf,"%*[^:]:%[^]]",new_lrc->buf);
    insert_link(head,new_lrc);
    for(i = 1; i < 4; i++)
    {
        p_buf = strtok(NULL,"\r\n");
        if(!p_buf)
        {
            perror("strtok");
            return -2;
        }
        new_lrc = (LRC *)calloc(1,sizeof(LRC));
        sscanf(p_buf,"%*[^:]:%[^]]",new_lrc->buf);
        insert_link(head,new_lrc);
    }
    //格式化读取后面歌词
    while(1)
    {
        char strbuf[256] = "";
        p_buf = strtok(NULL,"\r\n");
        if(!p_buf)
        {
            break;
        }
        char *str = strrchr(p_buf,']');
        if(!str)
        {
            break;
        }
        new_lrc = (LRC *)calloc(1,sizeof(LRC));
        strcpy(new_lrc->buf,(str+1));
        strcpy(strbuf,(str+1));
        str = strchr(p_buf,'[');
        sscanf(str,"[%d:%d.%d]",&new_lrc->time_min,&new_lrc->time_sec,&new_lrc->time_ms);
        insert_link(head,new_lrc);
        str = strchr(str+1,'[');
        while(str)
        {
            new_lrc = (LRC *)calloc(1,sizeof(LRC));
            strcpy(new_lrc->buf,strbuf);
            sscanf(str,"[%d:%d.%d]",&new_lrc->time_min,&new_lrc->time_sec,&new_lrc->time_ms);
            insert_link(head,new_lrc);
            str = strchr(str+1,'[');
        }
    }
    free(buf);
    return 0;
}

int insert_link(LRC **head,LRC *new_lrc)//链表的有序插入
{
    if(*head == NULL)
    {
        *head = new_lrc;
        return 0;
    }
    LRC *move = *head;
    LRC *formove = NULL;
    while(move)
    {
        if(move->time_min > new_lrc->time_min)
        {
            if(!formove)
            {
                new_lrc->next = *head;
                *head = new_lrc;
            }
            else
            {
                formove->next = new_lrc;
                new_lrc->next = move;
            }
            return 0;
        }
        else if(move->time_min == new_lrc->time_min)
        {
            if(move->time_sec > new_lrc->time_sec)
            {
                if(!formove)
                    {
                        new_lrc->next = *head;
                        *head = new_lrc;
                    }
                    else
                    {
                        formove->next = new_lrc;
                        new_lrc->next = move;
                    }
                    return 0;
            }
            else if(move->time_sec == new_lrc->time_sec)
            {
                if(move->time_ms > new_lrc->time_ms)
                {
                    if(!formove)
                    {
                        new_lrc->next = *head;
                        *head = new_lrc;
                    }
                    else
                    {
                        formove->next = new_lrc;
                        new_lrc->next = move;
                    }
                    return 0;
                }
            }
        }
        formove = move;
        move = move->next;
    }
    formove->next = new_lrc;
    return 0;
}

int free_link(LRC **head)//链表的释放
{
    LRC *move = *head;
    while(move)
    {
        *head = move->next;
        free(move);
        move = *head;
    }
    *head = NULL;
    return 0;
}

LRC *myprint(LRC *head,int num)//输出屏幕链表的内容
{
    int i = 0;
    LRC *move = head;

    for(i = 0; i < num; i++)
    {
        if(!move)
            return NULL;
        move = move->next;
    }
    return move;
}
