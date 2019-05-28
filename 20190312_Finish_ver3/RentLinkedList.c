#include <stdarg.h>
#include "RentLinkedList.h"

void RentListInit(RentList * plist)
{
	plist->head = (RentNode *)malloc(sizeof(RentNode));	// 더미 노드 생성
	plist->head->next = NULL;
	plist->cur = NULL;
	//plist->comp = NULL;		// 정렬 기준이 정해지지 않았다.

	plist->numOfData = 0;
}

void RentLInsert(RentList * plist, RentLData data)
{
	RentNode *newNode = (RentNode *)malloc(sizeof(RentNode));
	RentNode *prev = plist->head;	// 더미 노드를 가리킴

	newNode->data = data;

	while (prev->next != NULL)
		prev = prev->next;

	//// 노드 prev가 가리키는 주소가 NULL 값이 아니고,
	//// 삽입하는 데이터(data)값이 노드 prev가 가리키는 주소의 data 값 보다 뒤질 경우
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
