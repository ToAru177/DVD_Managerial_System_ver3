#ifndef _DVD_LINKED_LIST_H_
#define _DVD_LINKED_LIST_H_

#include "dvdInfo.h"

#define TRUE 1
#define FALSE 0

typedef dvdInfo* DVDLData;

typedef struct _dvdnode {
	DVDLData data;
	struct _node *next;
}DVDNode;

typedef struct _dvdlinkedlist {
	DVDNode *head;		// 더미 노드를 가리키는 멤버
	DVDNode *cur;		// 참조 및 삭제를 돕는 멤버	
	DVDNode *before;	// 삭제를 돕는 멤버
	int numOfData;	// 저장된 데이터의 수를 기록하기 위한 멤버
	//int(*comp)(LData d1, LData d2);	// 정렬의 기준을 등록하기 위한 멤버

}DVDLinkedList;

typedef DVDLinkedList DVDList;

void DVDListInit(DVDList *plist);
void DVDLInsert(DVDList *plist, DVDLData data);

int DVDLFirst(DVDList *plist, DVDLData *pdata);
int DVDLNext(DVDList *plist, DVDLData *pdata);

DVDLData DVDLRemove(DVDList *plist);
int DVDLCount(DVDList *plist);
//void SetSortRule(List *plist, int(*comp)(LData d1, LData d2));


#endif // !_DVD_LINKED_LIST_H_
