#ifndef FUN_H
#define FUN_H

typedef struct lrc{
        int time_min;
        int time_sec;
        int time_ms;
        char buf[256];
        struct lrc *next;
    }LRC;

extern int filelrc(LRC **head,char *filename);

extern int insert_link(LRC **head,LRC *new_lrc);

extern int free_link(LRC **head);

extern LRC *myprint(LRC *head,int num);

#endif // FUN_H
