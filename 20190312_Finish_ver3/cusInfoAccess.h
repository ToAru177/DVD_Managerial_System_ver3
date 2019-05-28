
#ifndef __CUSACCESS_H__
#define __CUSACCESS_H__

#include "cusInfo.h"


cusInfo *MakeCusNode(void);

/*
	��� : cusInfo �Ҵ� �� ����
	��ȯ : ���� �� ��ϵ� ������ ����,
	       ���� �� 0�� ��ȯ.
*/
void AddCusInfo(cusInfo **Head,char * ID, char * name, char * num);

/*
	��� : �ش� �� ID�� ������ ������ �ִ�
			�����͸� ��ȯ
	��ȯ : ��� �ȵ� ID�� ��� NULL ������ ��ȯ.
*/
cusInfo * GetCusPtrByID(cusInfo *Head,char * ID);

/*
	��� : ���Ե� ID���� üũ
	��ȯ : ���ԵǾ����� 1, �ƴϸ� 0�� ��ȯ.
*/
int IsregistID(cusInfo *Head,char * ID);

#endif // !__CUSACCESS_H__