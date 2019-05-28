#ifndef __DVDACCESS_H__
#define __DVDACCESS_H__

#include "dvdInfo.h"
#include "DVDLinkedList.h"

/*
	��� : dvdInfo ������� �Ҵ� �� ����ü 
			�迭�� ����
	��ȯ : ���� �� ��ϵ� ������ ��,
	        ���� �� 0�� ��ȯ.
*/
void AddDVDInfo(DVDList *dvdList, char * ISBN, char * title, int genre);

/*
	��� : �ش� ISBN�� ������ ��� �ִ� ������
			�����͸� ��ȯ.
	��ȯ : ��ϵ��� ���� ISBN�� ��� NULL 
			�����͸� ��ȯ.
*/
//dvdInfo * GetDVDPtrByISBN(dvdInfo *DVD_Head, char * ISBN);

/*
	��� : �� ��ϵ� ISBN���� üũ.
	��ȯ : ��ϵǾ����� 1, �ƴϸ� 0�� ��ȯ.
*/
int IsRegistISBN(DVDList *dvdList, char * ISBN);


dvdInfo *MakeDVDNode(char *ISBN, char *title, int genre);


#endif