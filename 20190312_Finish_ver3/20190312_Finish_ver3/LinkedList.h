#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#define TRUE 1
#define FALSE 0

typedef int LData;

typedef struct _node {
	LData data;
	struct _node *next;
}Node;

typedef struct _linkedlist {
	Node *head;		// 더미 노드를 가리키는 멤버
	Node *cur;		// 참조 및 삭제를 돕는 멤버	
	Node *before;	// 삭제를 돕는 멤버
	int numOfData;	// 저장된 데이터의 수를 기록하기 위한 멤버
	int(*comp)(LData d1, LData d2);	// 정렬의 기준을 등록하기 위한 멤버

}LinkedList;

/*
	
	정렬 기능 추가된 연결 리스트의 ADT

	void ListInit(List * plist);
		-	초기화할 리스트의 주소 값을 인자로 전달한다.
		-	리스트 생성 후 제일 먼저 호출되어야 하는 함수이다.

	void LInsert(List &plist, LData data);
		-	리스트에 데이터를 저장한다. 매개변수 data에 전달된 값을 저장한다.

	int LFirst(List *plist, LData *pdata);
		- 첫 번째 데이터가 pdata가 가리키는 메모리에 저장된다.
		-	데이터의 참조를 위한 초기화가 진행된다.
		-	참조 성공 시 TRUE(1), 실패 시 FALSE(0) 반환

	int LNext(List *plist, LData *pdata);
		-	참조된 데이터의 다음 데이터가 pdata가 가리키는 메모리에 저장된다.
		-	순차적인 참조를 위해서 반복 호출이 가능한다.
		-	참조를 새로 시작하려면 먼저 LFirst 함수를 호출해야 한다.
		-	참조 성공 시 TRUE(1), 실패 시 FALSE(0) 반환

	LData LRemove(List *plist);
		-	LFirst 또는 LNext 함수의 마지막 반환 데이터를 삭제한다.
		-	삭제된 데이터는 반환된다.
		-	마지막 반환 데이터를 삭제하므로 연이은 반복 호출을 허용하지 않는다.

	int LCount(List *plist);
		-	리스트에 저장되어 있는 데이터의 수 반환한다.

	void SetSortRule(List *plist, int (*comp)(LData d1, LData d2));
		-	리스트에 정렬의 기준이 되는 함수를 등록한다.

*/

typedef LinkedList List;

void ListInit(List *plist);
void LInsert(List *plist, LData data);

int LFirst(List *plist, LData *pdata);
int LNext(List *plist, LData *pdata);

LData LRemove(List *plist);
int LCount(List *plist);
void SetSortRule(List *plist, int (*comp)(LData d1, LData d2));

#endif // !_LINKED_LIST_H_

