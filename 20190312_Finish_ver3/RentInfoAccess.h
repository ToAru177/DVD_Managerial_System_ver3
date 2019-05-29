#ifndef _RENTACCESS_H_
#define _RENTACCESS_H_

#include "RentInfo.h"
#include "dvdInfo.h"
#include "RentLinkedList.h"

/*
	��� : DVD�� �뿩 ���� üũ
	��ȯ : �뿩��(RENTED)�� ��� 1 ��ȯ, �ƴҰ�� 0 ��ȯ
*/
int RentDVDState(dvdInfo *dvdPtr);

/*
	��� : �뿩 ����Ʈ�� �����͸� �ø�
	��ȯ : void
*/
void AddRentListInfo(RentList *rentList, dvdInfo *dvdPtr, cusInfo *cusPtr, int day);

/*
	��� : �뿩 ����Ʈ�� ISBN�� �Է��� ISBN�� ������ ISBN���� Ȯ��
	��ȯ : ������ ISBN�� ��� 0, �ƴҰ�� 0�̿��� ���� ��ȯ
*/
int RentISBNCompare(RentInfo *prent, char *ISBN);

/*
	��� : DVD�� �뿩�� ȸ���� ���� ���
	��ȯ : void
*/
void SearchRentInfo(RentList *rentList, char *ISBN);

/*
	��� : �Է��� ��¥ ���̿��� ȸ���� ���� DVD�� ISBN ���
	��ȯ : void
*/
void SearchRentUserInfoByDays(RentList *rentList, char *ID, int day1, int day2);

/*
	��� : �Ű������� �����͸� ���� RentInfo ���� ����
	��ȯ : ���� �޸� �Ҵ��� RentInfo* �ڷ����� ���� ��ȯ
*/
RentInfo *MakeRentNode(dvdInfo *dvdPtr, cusInfo *cusPtr, int day);

#endif // !_RENTACCESS_H_

