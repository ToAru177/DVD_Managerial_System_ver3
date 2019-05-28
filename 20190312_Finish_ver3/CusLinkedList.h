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
	CusNode *head;		// ���� ��带 ����Ű�� ���
	CusNode *cur;		// ���� �� ������ ���� ���	
	CusNode *before;	// ������ ���� ���
	int numOfData;	// ����� �������� ���� ����ϱ� ���� ���
	//int(*comp)(LData d1, LData d2);	// ������ ������ ����ϱ� ���� ���

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
