#ifndef __CUSACCESS_H__
#define __CUSACCESS_H__

#include "cusInfo.h"
#include "CusLinkedList.h"

/*
	��� : �Ű������� �����͸� ���� cusInfo ���� ����
	��ȯ : ���� �޸� �Ҵ��� cusInfo* �ڷ����� ���� ��ȯ
*/
cusInfo *MakeCusNode(char *ID, char *name, char *phone);

/*
	��� : ȸ�� ����Ʈ�� �����͸� �ø�
	��ȯ : void
*/
void AddCusInfo(CusList *cusList, char *ID, char *name, char *phone);

/*
	��� : ȸ�� ����Ʈ�� ID�� �Է��� ID�� ������ ID���� Ȯ��
	��ȯ : ������ ID�� ��� 0, �ƴҰ�� 0�̿��� ���� ��ȯ
*/
int IDCompare(cusInfo *pcus, char *ID);

/*
	��� : ���Ե� ID���� üũ
	��ȯ : ���ԵǾ����� FALSE(0), �ƴϸ� TURE(1)�� ��ȯ.
*/
int IsregistID(CusList *Head,char * ID);

#endif // !__CUSACCESS_H__