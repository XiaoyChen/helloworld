#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include "menu.h"

int ls(int argc, char *argv[])
{
    const char *optString = "ustc";
    opterr = 0;
    int opt;
    while ((opt = getopt(argc, argv, optString)) != -1)
    {
        switch (opt)
        {
            case 'u':
                printf("university.\n");
                break;            
            case 's':
                printf("science.\n");
                break;
            case 't':
                printf("technology.\n");
                break;
            case 'c':
                printf("in this cmd, you have 4 option can use:\n");
                printf("-u\n");
                printf("-s\n");
                printf("-t\n");
                printf("-c\n");
                break;
            default:
                break;
        }
    }
    // reset global valuable optind
    optind = 0;
    return 0;
}

void quit(int argc, char *argv[])
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

int main(int argc,char* argv[])
{
    MenuConfig("quit","quit from cmd",quit);
    MenuConfig("printtime","tell you time", printTime);
    MenuConfig("printpath","tell you where you are now", printPath);
    MenuConfig("sayhello","greet", sayHello);
    MenuConfig("ls","test arg option", ls);
    ExecuteMenu();
    return 0;
}
