#include "common.h"
#include "cusInfo.h"

#define MAX_CUSTOMER 100

//���������Ͽ��� �������� ����� 
// extern -> ���� , static -> �������� �ʰڴ�.
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
		*Head = MakeCusNode();	// ���ο� ��� �߰�

		// ���� �߰��� ��忡 �Է� ���� ���� ����
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

