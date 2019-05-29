#ifndef __DVDACCESS_H__
#define __DVDACCESS_H__

#include "dvdInfo.h"
#include "DVDLinkedList.h"

/*
	��� : DVD ����Ʈ�� �����͸� �ø�
	��ȯ : void
*/
void AddDVDInfo(DVDList *dvdList, char * ISBN, char * title, int genre);

/*
	��� : ��ϵ� ISBN���� üũ.
	��ȯ : ��ϵǾ����� FALSE(0), �ƴϸ� TURE(1)�� ��ȯ.
*/
int IsRegistISBN(DVDList *dvdList, char * ISBN);

/*
	��� : DVD ����Ʈ�� ISBN�� �Է��� ISBN�� ������ ISBN���� Ȯ��
	��ȯ : ������ ISBN�� ��� 0, �ƴҰ�� 0�̿��� ���� ��ȯ
*/
int ISBNCompare(dvdInfo *pdvd, char *ISBN);

/*
	��� : �Ű������� �����͸� ���� dvdInfo ���� ����
	��ȯ : ���� �޸� �Ҵ��� dvdInfo* �ڷ����� ���� ��ȯ
*/
dvdInfo *MakeDVDNode(char *ISBN, char *title, int genre);

#endif