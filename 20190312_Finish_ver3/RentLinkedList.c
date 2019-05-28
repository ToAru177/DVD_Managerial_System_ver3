#include <stdarg.h>
#include "RentLinkedList.h"

void RentListInit(RentList * plist)
{
	plist->head = (RentNode *)malloc(sizeof(RentNode));	// ���� ��� ����
	plist->head->next = NULL;
	plist->cur = NULL;
	//plist->comp = NULL;		// ���� ������ �������� �ʾҴ�.

	plist->numOfData = 0;
}

void RentLInsert(RentList * plist, RentLData data)
{
	RentNode *newNode = (RentNode *)malloc(sizeof(RentNode));
	RentNode *prev = plist->head;	// ���� ��带 ����Ŵ

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

int RentLFirst(RentList * plist, RentLData * pdata)
{
	if (plist->numOfData == 0)
		return FALSE;

	plist->before = plist->head;

	plist->cur = plist->head->next;
	*pdata = plist->cur->data;
	return TRUE;
}

int RentLNext(RentList * plist, RentLData * pdata)
{
	if (plist->cur->next == NULL)
		return FALSE;

	plist->before = plist->cur;

	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;
	return TRUE;
}

RentLData RentLRemove(RentList * plist)
{
	RentNode *delNode = plist->cur;
	RentLData delData = delNode->data;

	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	free(delNode);
	(plist->numOfData)--;

	return delData;
}

int RentLCount(RentList * plist)
{
	return plist->numOfData;
}

//void SetSortRule(List * plist, int(*comp)(LData d1, LData d2))
//{
//	plist->comp = comp;
//}
