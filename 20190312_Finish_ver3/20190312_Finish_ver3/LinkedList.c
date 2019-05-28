#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

void ListInit(List * plist)
{
	plist->head = (Node *)malloc(sizeof(Node));	// ���� ��� ����
	plist->head->next = NULL;
	plist->cur = NULL;
	plist->comp = NULL;		// ���� ������ �������� �ʾҴ�.

	plist->numOfData = 0;
}

void LInsert(List * plist, LData data)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	Node *prev = plist->head;	// ���� ��带 ����Ŵ

	newNode->data = data;

	/*while (prev->next != NULL)
		prev = prev->next;*/

	// ��� prev�� ����Ű�� �ּҰ� NULL ���� �ƴϰ�,
	// �����ϴ� ������(data)���� ��� prev�� ����Ű�� �ּ��� data �� ���� ���� ���
	while ((prev->next != NULL) && (plist->comp(data,prev->next->data)))
		prev = prev->next;

	newNode->next = prev->next;

	prev->next = newNode;

	(plist->numOfData)++;

}

int LFirst(List * plist, LData * pdata)
{
	if (plist->numOfData == 0)
		return FALSE;

	plist->before = plist->head;

	plist->cur = plist->head->next;
	*pdata = plist->cur->data;
	return TRUE;
}

int LNext(List * plist, LData * pdata)
{
	if (plist->cur->next == NULL)
		return FALSE;
	
	plist->before = plist->cur;

	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;
	return TRUE;
}

LData LRemove(List * plist)
{
	Node *delNode = plist->cur;
	LData delData = delNode->data;

	plist->before->next = plist->cur->next;
	plist->cur = plist->before;
	
	free(delNode);
	(plist->numOfData)--;

	return delData;
}

int LCount(List * plist)
{
	return plist->numOfData;
}

void SetSortRule(List * plist, int(*comp)(LData d1, LData d2))
{
	plist->comp = comp;
}
