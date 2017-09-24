#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

void printTime();
void printPath();
void sayHello();
void printASCII();
void sayBye();

int main()
{
    char cmd[128];
    while(1)
    {
        printf("请输入您想要执行的菜单命令\n");
        scanf("%s", cmd);    
        printf("您输入的命令是：%s\n", cmd);
        if(strcmp(cmd, "help") == 0)
        {
            printf("This is help cmd!\n");
        }
        else if(strcmp(cmd, "exit") == 0)
        {
            exit(0);
        }
        else if(strcmp(cmd, "time") == 0)
        {
            printTime();
        }
        else if(strcmp(cmd, "path") == 0)
        {
            printPath();
        }
        else if(strcmp(cmd, "hello") == 0)
        {
            sayHello();
        }
        else if(strcmp(cmd, "getASCII") == 0)
        {
            printASCII();
        }
        else if(strcmp(cmd, "bye") == 0)
        {
            sayBye();
        }
        else
        {
            printf("Wrong cmd!\n");
        }
    }
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

void printASCII()
{
    char ch;
    printf("请输入一个字符\n");
    scanf("%c", &ch);
    printf("字符%c的码是%d\n", ch, ch);
}

