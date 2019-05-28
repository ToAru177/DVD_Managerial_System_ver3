#ifndef __DVDACCESS_H__
#define __DVDACCESS_H__

#include "dvdInfo.h"

/*
	��� : dvdInfo ������� �Ҵ� �� ����ü 
			�迭�� ����
	��ȯ : ���� �� ��ϵ� ������ ��,
	        ���� �� 0�� ��ȯ.
*/
void AddDVDInfo(dvdInfo **DVD_Head, char * ISBN, char * title, int genre);

/*
	��� : �ش� ISBN�� ������ ��� �ִ� ������
			�����͸� ��ȯ.
	��ȯ : ��ϵ��� ���� ISBN�� ��� NULL 
			�����͸� ��ȯ.
*/
dvdInfo * GetDVDPtrByISBN(dvdInfo *DVD_Head, char * ISBN);

/*
	��� : �� ��ϵ� ISBN���� üũ.
	��ȯ : ��ϵǾ����� 1, �ƴϸ� 0�� ��ȯ.
*/
int IsRegistISBN(dvdInfo *DVD_Head, char * ISBN);

int RentDVDState(dvdInfo *dvdPtr);

void AddRentListInfo(dvdRentInfo **Rent_Head, dvdInfo *dvdPtr, cusInfo *cusPtr, int day);

void SearchRentInfo(dvdRentInfo *Rent_Head, char *ISBN);

void SearchRentUserInfoByDays(dvdRentInfo *Rent_Head, char *ID, int day1, int day2);

dvdInfo *MakeDVDNode(void);

dvdRentInfo *MakeRentNode(void);

#endif