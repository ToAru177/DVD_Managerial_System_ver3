
#ifndef __SCREENOUT_H__
#define __SCREENOUT_H__

#include "cusInfo.h"
#include "dvdInfo.h"

/*
	기능 : 프로그램을 사용하기 위한 메뉴 출력
	반환 : void
*/
void ShowMenu(void);
void ShowCusMenu(void);
void ShowDVDMenu(void);
void ShowDVDRentMenu(void);
void ShowSearchMenu(void);

/*
	기능 : 고객 정보를 출력
	반환 : void
*/
void ShowCustomerInfo(cusInfo * pCus);

void ShowDVDInfo(dvdInfo * pDVD);

void ShowGenre(int gen);

void ShowRentState(int rentState);

void ShowRentInfo(dvdRentInfo *pDVD);

void ShowRentInfoUser(dvdRentInfo *pDVD);

#endif // !__SCREENOUT_H__


