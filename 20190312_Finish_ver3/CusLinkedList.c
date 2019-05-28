#include <stdio.h>
#include <stdlib.h>
#include "CusLinkedList.h"

void CusListInit(CusList * plist)
{
	plist->head = (CusNode *)malloc(sizeof(CusNode));	// ���� ��� ����
	plist->head->next = NULL;
	plist->cur = NULL;
	//plist->comp = NULL;		// ���� ������ �������� �ʾҴ�.

	plist->numOfData = 0;
}

void CusLInsert(CusList * plist, CusLData data)
{
	CusNode *newNode = (CusNode *)malloc(sizeof(CusNode));
	CusNode *prev = plist->head;	// ���� ��带 ����Ŵ

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

int CusLFirst(CusList * plist, CusLData * pdata)
{
	if (plist->numOfData == 0)
		return FALSE;

	plist->before = plist->head;

	plist->cur = plist->head->next;
	*pdata = plist->cur->data;
	return TRUE;
}

int CusLNext(CusList * plist, CusLData * pdata)
{
	if (plist->cur->next == NULL)
		return FALSE;

	plist->before = plist->cur;

	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;
	return TRUE;
}

CusLData CusLRemove(CusList * plist)
{
	CusNode *delNode = plist->cur;
	CusLData delData = delNode->data;

	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	free(delNode);
	(plist->numOfData)--;

	return delData;
}

int CusLCount(CusList * plist)
{
	return plist->numOfData;
}

//void SetSortRule(List * plist, int(*comp)(LData d1, LData d2))
//{
//	plist->comp = comp;
//}
