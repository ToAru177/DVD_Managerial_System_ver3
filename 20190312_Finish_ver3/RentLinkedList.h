#ifndef _RENT_LINKED_LIST_H_
#define _RENT_LINKED_LIST_H_

#include "RentInfo.h"

#define TRUE 1
#define FALSE 0

typedef RentInfo* RentLData;

typedef struct _rentnode {
	RentLData data;
	struct _rentnode *next;
}RentNode;

typedef struct _rentlinkedlist {
	RentNode *head;		// ���� ��带 ����Ű�� ���
	RentNode *cur;		// ���� �� ������ ���� ���	
	RentNode *before;	// ������ ���� ���
	int numOfData;	// ����� �������� ���� ����ϱ� ���� ���
	//int(*comp)(LData d1, LData d2);	// ������ ������ ����ϱ� ���� ���

}RentLinkedList;

typedef RentLinkedList RentList;

void RentListInit(RentList *plist);
void RentLInsert(RentList *plist, RentLData data);

int RentLFirst(RentList *plist, RentLData *pdata);
int RentLNext(RentList *plist, RentLData *pdata);

RentLData RentLRemove(RentList *plist);
int RentLCount(RentList *plist);
//void SetSortRule(List *plist, int(*comp)(LData d1, LData d2));


#endif // !_RENT_LINKED_LIST_H_

