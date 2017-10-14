#ifndef LINKTABLE_H
#define LINKTABLE_H
#include <pthread.h>

#define SUCCESS 0
#define FAILURE (-1)

//LinkTable Node Type
typedef struct LinkTableNode
{
	struct LinkTableNode * pNext;
}tLinkTableNode;

//LinkTable Type
typedef struct LinkTable
{
	tLinkTableNode *pHead;
	tLinkTableNode *pTail;
	int SumOfNode;
	pthread_mutex_t mutex; 
}tLinkTable;

//Creat a LinkTable
tLinkTable *CreateLinkTable();
//Delete a LinkTable
int DeleteLinkTable(tLinkTable *pLinkTable);
//Add a LinkTableNode
int AddLinkTableNode(tLinkTable *pLinkTable, tLinkTableNode *pNode);
//Delete a LinkTableNode
int DelLinkTableNode(tLinkTable *pLinkTable, tLinkTableNode *pNode);
//Get LinkTableHead
tLinkTableNode *GetLinkTableHead(tLinkTable *pLinkTable);
//Get next LinkTableNode
tLinkTableNode *GetNextLinkTableNode(tLinkTable *pLinkTable, tLinkTableNode *pNode);

#endif
