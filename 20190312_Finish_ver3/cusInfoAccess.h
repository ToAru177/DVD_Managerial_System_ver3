#ifndef __CUSACCESS_H__
#define __CUSACCESS_H__

#include "cusInfo.h"
#include "CusLinkedList.h"

cusInfo *MakeCusNode(char *ID, char *name, char *phone);

/*
	��� : cusInfo �Ҵ� �� ����
	��ȯ : ���� �� ��ϵ� ������ ����,
	       ���� �� 0�� ��ȯ.
*/
void AddCusInfo(CusList *cusList, char *ID, char *name, char *phone);

/*
	��� : 
	��ȯ : ��� �ȵ� ID�� ��� NULL ������ ��ȯ.
*/
int IDCompare(cusInfo *pcus, char *ID);

/*
	��� : ���Ե� ID���� üũ
	��ȯ : ���ԵǾ����� 1, �ƴϸ� 0�� ��ȯ.
*/
int IsregistID(CusList *Head,char * ID);

#endif // !__CUSACCESS_H__