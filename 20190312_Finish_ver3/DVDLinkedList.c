#include <stdio.h>
#include <stdlib.h>
#include "DVDLinkedList.h"

void DVDListInit(DVDList * plist)
{
	plist->head = (DVDNode *)malloc(sizeof(DVDNode));	// ���� ��� ����
	plist->head->next = NULL;
	plist->cur = NULL;
	//plist->comp = NULL;		// ���� ������ �������� �ʾҴ�.

	plist->numOfData = 0;
}

void DVDLInsert(DVDList * plist, DVDLData data)
{
	DVDNode *newNode = (DVDNode *)malloc(sizeof(DVDNode));
	DVDNode *prev = plist->head;	// ���� ��带 ����Ŵ

	newNode->data = data;

	while (prev->next != NULL)
		prev = prev->next;

	//// ��� prev�� ����Ű�� �ּҰ� NULL ���� �ƴϰ�,
	//// �����ϴ� ������(data)���� ��� prev�� ����Ű�� �ּ��� data �� ���� ���� ���
	//while ((prev->next != NULL) && (plist->comp(data, prev->next->data)))
	//	prev = prev->next;

	newNode->next = prev->next;

	prev->next = newNode;

	(plist->numOfData)++;

}

int DVDLFirst(DVDList * plist, DVDLData * pdata)
{
	if (plist->numOfData == 0)
		return FALSE;

	plist->before = plist->head;

	plist->cur = plist->head->next;
	*pdata = plist->cur->data;
	return TRUE;
}

int DVDLNext(DVDList * plist, DVDLData * pdata)
{
	if (plist->cur->next == NULL)
		return FALSE;

	plist->before = plist->cur;

	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;
	return TRUE;
}

DVDLData DVDLRemove(DVDList * plist)
{
	DVDNode *delNode = plist->cur;
	DVDLData delData = delNode->data;

	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	free(delNode);
	(plist->numOfData)--;

	return delData;
}

int DVDLCount(DVDList * plist)
{
	return plist->numOfData;
}

//void SetSortRule(List * plist, int(*comp)(LData d1, LData d2))
//{
//	plist->comp = comp;
//}
