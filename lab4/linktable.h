#ifndef LINKTABLE_H
#define LINKTABLE_H

#include<pthread.h>

#define SUCESS 0
#define FAILURE (-1)


typedef struct LinkTableNode
{
    struct LinkTableNode * pNext;
}tLinkTableNode;


typedef struct LinkTable
{
    tLinkTableNode *pHead;
    tLinkTableNode *pTail;
    int SumOFNode;
    pthread_mutex_t mutex;
}tLinkTable;


tLinkTable * CreateLinkTable();

int DeleteLinkTable(tLinkTable * pLinkTable);

int AddLinkTableNode(tLinkTable * pLinkTable,tLinkTableNode * pNode);

int DeLinkTableNode(tLinkTable * pLinkTable,tLinkTableNode *pNode);

tLinkTableNode * GetLinkTableHead(tLinkTable *pLinkTable);

tLinkTableNode * GetNextLinkTableNode(tLinkTable *pLinkTable,tLinkTableNode *pNode);

#endif
