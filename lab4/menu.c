#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include "linktable.h"


/* cmd functions*/
void help();
void printTime();
void printPath();
void sayHello();
void sayBye();
void quit();

tLinkTable* head = NULL;

#define cmd_max_len 128
#define time_max 255

//static tDataNode head[] =
//{
//    {"help", "This is help cmd.", help, &head[1]},
//    {"printTime", "It can tell you time.", printTime, &head[2]},
//    {"printPath", "It can tell you where are you.", printPath, &head[3]},
//    {"sayHello", "say hello to u.", sayHello, &head[4]},
//    {"sayBye", "say byebye to u.", sayBye, &head[5]},
//    {"quit", "This is exit cmd.", quit, NULL}
//};
typedef struct DataNode
{
    char* cmd;
    char* desc;
    void (*handler)();
    struct DataNode *next;
} tDataNode;

tDataNode* FindCmd(tLinkTable * head, char * cmd)
{
	tDataNode * pNode = (tDataNode*)GetLinkTableHead(head);
	while(pNode != NULL)
	{
		if(strcmp(pNode->cmd, cmd) == 0)
		{
			return pNode;
		}
		pNode = (tDataNode*)GetNextLinkTableNode(head,(tLinkTableNode*)pNode);	
	}	
	return 0;
}



int InitMenuData(tLinkTable ** ppLinkTable)
{
	*ppLinkTable = CreateLinkTable();
	tDataNode * pNode = (tDataNode*)malloc(sizeof(tDataNode));
	pNode->cmd = "help";
	pNode->desc = "Menu List:";
	pNode->handler = help;
	AddLinkTableNode(*ppLinkTable, (tLinkTableNode *)pNode);
	pNode = (tDataNode *)malloc(sizeof(tDataNode));
	pNode->cmd = "version";
	pNode->desc = "Menu Program v1.0";
	pNode->handler = NULL;
	AddLinkTableNode(*ppLinkTable, (tLinkTableNode *)pNode);
	pNode = (tDataNode *)malloc(sizeof(tDataNode));
	pNode->cmd = "quit";
	pNode->desc = "Quit from Menu Program v1.0";
	pNode->handler = quit;
	AddLinkTableNode(*ppLinkTable, (tLinkTableNode *)pNode);
	
	return 0;
}

void ShowAllCmd(tLinkTable* head)
{
    tDataNode* p = (tDataNode *)GetLinkTableHead(head);
    printf("Menu List:\n");
    while(p != NULL)
    {
        printf("%s-%s\n", p->cmd, p->desc);
        p = (tDataNode *)GetNextLinkTableNode(head, (tLinkTableNode *)p);
    }
}


int main(int argc, char *argv[])
{
	InitMenuData(&head);
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

void version()
{
	printf("v1.0");
}










