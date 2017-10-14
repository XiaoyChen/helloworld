#include <stdlib.h>
#include <stdio.h>
#include "linktable.h"

tLinkTable *CreateLinkTable()
{
	tLinkTable *pLinkTable = (tLinkTable*)malloc(sizeof(tLinkTable));
	if(pLinkTable == NULL)
	{
		return NULL;
	}
	pLinkTable->pHead = NULL;
	pLinkTable->pTail = NULL;
	pLinkTable->SumOfNode = 0;
	return pLinkTable;
}

int DeleteLinkTable(tLinkTable *pLinkTable)
{
	if(pLinkTable == NULL)
	{
		return FAILURE;
	}
	while(pLinkTable->pHead != NULL)
	{
		tLinkTableNode* pNode = pLinkTable->pHead;
		pLinkTable->pHead = pLinkTable->pHead->pNext;
		free(pNode);
	}
	pLinkTable->pHead = NULL;
	pLinkTable->pTail = NULL;
	pLinkTable->SumOfNode = -1;
	free(pLinkTable);
	return SUCCESS;
}
//Add a LinkTableNode
int AddLinkTableNode(tLinkTable *pLinkTable, tLinkTableNode *pNode)
{
	if(pLinkTable == NULL || pNode == NULL)
	{
		return FAILURE;
	}
	if(pLinkTable->pHead == NULL && pLinkTable->pTail == NULL)
	{
		pLinkTable->pHead = pNode;
		pLinkTable->pTail = pNode;
		pLinkTable->SumOfNode = 1; 
	}
	else
	{
		pLinkTable->pTail->pNext = pNode;
		pLinkTable->pTail = pNode;
		pLinkTable->pTail->pNext = NULL;
		pLinkTable->SumOfNode ++;
	}
	return SUCCESS;
}
//Delete a LinkTableNode
int DelLinkTableNode(tLinkTable *pLinkTable, tLinkTableNode *pNode)
{
	tLinkTableNode* tmp = pLinkTable->pHead;
	if(pLinkTable == NULL || pNode == NULL)
	{
		return FAILURE;
	}
	if(pLinkTable->SumOfNode == 0)
	{
		pLinkTable->pTail = NULL;
		return FAILURE;
	}
	if(pLinkTable->pHead == pNode)
	{
		pLinkTable->pHead = pLinkTable->pHead->pNext;
		free(tmp);
		pLinkTable->SumOfNode --;
	}
	

	while( tmp != NULL)
	{
		if(tmp->pNext == pNode)
		{
			tmp->pNext = pNode->pNext;
			pLinkTable->SumOfNode --;
		}
		if(pLinkTable->SumOfNode == 0)
		{
			pLinkTable->pTail = NULL;
		}
		return SUCCESS;
		tmp = tmp->pNext;
	}
	return FAILURE;
}
//Get LinkTableHead
tLinkTableNode *GetLinkTableHead(tLinkTable *pLinkTable)
{
	if(pLinkTable == NULL || pLinkTable->pHead == NULL)
	{
		return NULL;
	}
	return pLinkTable->pHead;
}
//Get next LinkTableNode
tLinkTableNode *GetNextLinkTableNode(tLinkTable *pLinkTable, tLinkTableNode *pNode)
{
	if(pLinkTable == NULL || pNode == NULL)
	{
		return NULL;
	}
	tLinkTableNode* tmp = pLinkTable->pHead;
	while(tmp != NULL)
	{
		if(tmp == pNode)
		{
			return tmp->pNext;
		}
		tmp = tmp->pNext;
	}
	return NULL;
}
