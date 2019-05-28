
#ifndef __SCREENOUT_H__
#define __SCREENOUT_H__

#include "cusInfo.h"
#include "dvdInfo.h"

/*
	��� : ���α׷��� ����ϱ� ���� �޴� ���
	��ȯ : void
*/
void ShowMenu(void);
void ShowCusMenu(void);
void ShowDVDMenu(void);
void ShowDVDRentMenu(void);
void ShowSearchMenu(void);

/*
	��� : �� ������ ���
	��ȯ : void
*/
void ShowCustomerInfo(cusInfo * pCus);

void ShowDVDInfo(dvdInfo * pDVD);

void ShowGenre(int gen);

void ShowRentState(int rentState);

void ShowRentInfo(dvdRentInfo *pDVD);

void ShowRentInfoUser(dvdRentInfo *pDVD);

#endif // !__SCREENOUT_H__


