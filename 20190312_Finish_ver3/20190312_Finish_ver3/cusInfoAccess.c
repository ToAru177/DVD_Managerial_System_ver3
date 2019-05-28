#include "common.h"
#include "cusInfo.h"

#define MAX_CUSTOMER 100

//분할컴파일에서 전역변수 선언시 
// extern -> 공유 , static -> 공유하지 않겠다.
//cusInfo *Head = NULL;
static int numOfCustomer = 0;

cusInfo *MakeCusNode(void) {
	cusInfo *tmp = (cusInfo *)malloc(sizeof(cusInfo));
	tmp->next = NULL;

	return tmp;
}

void AddCusInfo(cusInfo **Head,char * ID, char * name, char * num)
{
	if ((*Head) == NULL) {
		*Head = MakeCusNode();	// 새로운 노드 추가

		// 새로 추가한 노드에 입력 받은 정보 저장
		strcpy((*Head)->ID, ID);
		strcpy((*Head)->name, name);
		strcpy((*Head)->phoneNum, num);

		return;
	}

	else {
		AddCusInfo(&(*Head)->next, ID, name, num);
	}

}

cusInfo * GetCusPtrByID(cusInfo *Head, char * ID)
{	
	cusInfo *temp = (cusInfo *)malloc(sizeof(cusInfo));

	temp = Head;

	while (temp != NULL){
		if (strcmp(temp->ID, ID) == 0) {
			return temp;
		}
		temp = temp->next;
	}

	return (cusInfo *)0;
}

int IsregistID(cusInfo *Head,char * ID)
{
	cusInfo * pCus = GetCusPtrByID(Head, ID);

	if (pCus == 0)
		return 0;
	else
		return 1;
}

