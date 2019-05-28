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
	DVDNode *head;		// ���� ��带 ����Ű�� ���
	DVDNode *cur;		// ���� �� ������ ���� ���	
	DVDNode *before;	// ������ ���� ���
	int numOfData;	// ����� �������� ���� ����ϱ� ���� ���
	//int(*comp)(LData d1, LData d2);	// ������ ������ ����ϱ� ���� ���

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
