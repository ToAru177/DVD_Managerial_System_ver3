#ifndef __SCREENOUT_H__
#define __SCREENOUT_H__

#include "cusInfo.h"
#include "dvdInfo.h"
#include "CusLinkedList.h"
#include "DVDLinkedList.h"
#include "RentLinkedList.h"

/*
	��� : ���α׷��� ����ϱ� ���� �޴� ���
	��ȯ : void
*/
void ShowMenu(void);

/*
	��� : �� ������ ���� �޴� ���
	��ȯ : void
*/
void ShowCusMenu(CusList *cusList);

/*
	��� : DVD ������ ���� �޴� ���
	��ȯ : void
*/
void ShowDVDMenu(DVDList *dvdList);

/*
	��� : DVD �뿩/�ݳ��� ���� �޴� ���
	��ȯ : void
*/
void ShowDVDRentMenu(RentList *rentList, DVDList *dvdList, CusList *cusList);

/*
	��� : �뿩 ���� ��ȸ�� ���� �޴� ���
	��ȯ : void
*/
void ShowSearchMenu(RentList *rentList, DVDList *dvdList, CusList *cusList);

/*
	��� : �� ������ ���
	��ȯ : void
*/
void ShowCustomerInfo(cusInfo *pcus);

/*
	��� : DVD ���� ���
	��ȯ : void
*/
void ShowDVDInfo(dvdInfo * pDVD);

/*
	��� : DVD �帣 ���
	��ȯ : void
*/
void ShowGenre(int gen);

/*
	��� : DVD �뿩 ���� ���
	��ȯ : void
*/
void ShowRentState(int rentState);

/*
	��� : DVD�� �뿩�� �� ���� ���
	��ȯ : void
*/
void ShowRentInfo(RentInfo *pDVD);

/*
	��� : ���� �뿩�� DVD�� ISBN ���
	��ȯ : void
*/
void ShowRentInfoUser(RentInfo *pDVD);

#endif // !__SCREENOUT_H__


