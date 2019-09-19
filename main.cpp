#include "widget.h"
#include <QApplication>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <pthread.h>

struct MyTyep{
   int fifo_fd;
   int fd[2];
}Mytype;
int main(int argc, char *argv[])
{
    //创建一个无名管道 获取mplayer回应
        pipe(Mytype.fd);
        pid_t pid = fork();
        if(pid == 0)//子进程
        {
            //创建一个管道s
            mkfifo("fifo_cmd",0666);
            //将1号设备重定向到fd[1]
            dup2(Mytype.fd[1],1);
            //使用execlp启动mplayer
            execlp("mplayer","mplayer","-idle","-slave","-quiet","-input","file=./fifo_cmd","2518.mp3",NULL);
        }
        else//父进程一些规律
        {
            //创建一个管道
            mkfifo("fifo_cmd",0666);
            Mytype.fifo_fd = open("fifo_cmd",O_WRONLY);
            QApplication a(argc, argv);
            Widget w;
            w.show();
            a.exec();
            close(Mytype.fifo_fd);
            system("rm fifo_cmd");
        }
    return 0;
}
