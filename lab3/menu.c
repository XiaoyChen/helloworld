#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include "linklist.h"

/* cmd functions*/
void help();
void printTime();
void printPath();
void sayHello();
void sayBye();
void quit();

#define cmd_max_len 128
#define time_max 255

static tDataNode head[] =
{
    {"help", "This is help cmd.", help, &head[1]},
    {"printTime", "It can tell you time.", printTime, &head[2]},
    {"printPath", "It can tell you where are you.", printPath, &head[3]},
    {"sayHello", "say hello to u.", sayHello, &head[4]},
    {"sayBye", "say byebye to u.", sayBye, &head[5]},
    {"quit", "This is exit cmd.", quit, NULL}
};

int main(int argc, char *argv[])
{
    while (1)
    {
        char cmd[cmd_max_len];
        printf("Input a cmd :");
        scanf("%s", cmd);
        tDataNode *p = FindCmd(head, cmd);
        if(p == NULL)
        {
            printf("This is a wrong cmd!\n");
            ShowAllCmd(head);
            continue;
        }

        printf("%s - %s\n", p->cmd, p->desc);
        if(p->handler != NULL)
        {
            p->handler();
        }
    }
    return 0;
}

//cmd functions

void help()
{
    printf("This is help cmd!\n");
}

void quit()
{
    exit(0);
}

void printTime()
{
    time_t t = time(0);
    char tmp[255];
    strftime(tmp, 255, "%Y-%m-%d %H:%M:%S", localtime(&t));
    printf("time is %s\n", tmp);
}

void printPath()
{
    char tmp[255];
    getcwd(tmp, sizeof(tmp));
    printf("current working directory: %s\n", tmp);
}

void sayHello()
{
    printf("Hello world!\n");
}

void sayBye()
{
    printf("See you next time!\n");
}









