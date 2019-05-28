
#ifndef __SCREENOUT_H__
#define __SCREENOUT_H__

#include "cusInfo.h"
#include "dvdInfo.h"
#include "CusLinkedList.h"
#include "DVDLinkedList.h"

/*
	��� : ���α׷��� ����ϱ� ���� �޴� ���
	��ȯ : void
*/
void ShowMenu(void);
void ShowCusMenu(CusList *cusList);
void ShowDVDMenu(DVDList *dvdList);
void ShowDVDRentMenu(void);
void ShowSearchMenu(void);

/*
	��� : �� ������ ���
	��ȯ : void
*/
void ShowCustomerInfo(cusInfo *pcus);

void ShowDVDInfo(dvdInfo * pDVD);

void ShowGenre(int gen);

void ShowRentState(int rentState);

void ShowRentInfo(RentInfo *pDVD);

void ShowRentInfoUser(RentInfo *pDVD);

#endif // !__SCREENOUT_H__


