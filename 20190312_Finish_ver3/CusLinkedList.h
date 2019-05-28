#ifndef _CUS_LINKED_LIST_H
#define _CUS_LINKED_LIST_H

#include "cusInfo.h"

#define TRUE 1
#define FALSE 0

typedef cusInfo* CusLData;

typedef struct _node {
	CusLData data;
	struct _node *next;
}CusNode;

typedef struct _cuslinkedlist {
	CusNode *head;		// 더미 노드를 가리키는 멤버
	CusNode *cur;		// 참조 및 삭제를 돕는 멤버	
	CusNode *before;	// 삭제를 돕는 멤버
	int numOfData;	// 저장된 데이터의 수를 기록하기 위한 멤버
	//int(*comp)(LData d1, LData d2);	// 정렬의 기준을 등록하기 위한 멤버

}CusLinkedList;

typedef CusLinkedList CusList;

void CusListInit(CusList *plist);
void CusLInsert(CusList *plist, CusLData data);

int CusLFirst(CusList *plist, CusLData *pdata);
int CusLNext(CusList *plist, CusLData *pdata);

CusLData CusLRemove(CusList *plist);
int CusLCount(CusList *plist);
//void SetSortRule(List *plist, int(*comp)(LData d1, LData d2));

#endif // !_CUS_LINKED_LIST_H
