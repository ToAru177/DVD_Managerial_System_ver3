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
	RentNode *head;		// 더미 노드를 가리키는 멤버
	RentNode *cur;		// 참조 및 삭제를 돕는 멤버	
	RentNode *before;	// 삭제를 돕는 멤버
	int numOfData;	// 저장된 데이터의 수를 기록하기 위한 멤버
	//int(*comp)(LData d1, LData d2);	// 정렬의 기준을 등록하기 위한 멤버

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

