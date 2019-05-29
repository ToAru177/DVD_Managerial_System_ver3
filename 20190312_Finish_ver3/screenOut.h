#ifndef __SCREENOUT_H__
#define __SCREENOUT_H__

#include "cusInfo.h"
#include "dvdInfo.h"
#include "CusLinkedList.h"
#include "DVDLinkedList.h"
#include "RentLinkedList.h"

/*
	기능 : 프로그램을 사용하기 위한 메뉴 출력
	반환 : void
*/
void ShowMenu(void);

/*
	기능 : 고객 관리를 위한 메뉴 출력
	반환 : void
*/
void ShowCusMenu(CusList *cusList);

/*
	기능 : DVD 관리를 위한 메뉴 출력
	반환 : void
*/
void ShowDVDMenu(DVDList *dvdList);

/*
	기능 : DVD 대여/반남을 위한 메뉴 출력
	반환 : void
*/
void ShowDVDRentMenu(RentList *rentList, DVDList *dvdList, CusList *cusList);

/*
	기능 : 대여 정보 조회를 위한 메뉴 출력
	반환 : void
*/
void ShowSearchMenu(RentList *rentList, DVDList *dvdList, CusList *cusList);

/*
	기능 : 고객 정보를 출력
	반환 : void
*/
void ShowCustomerInfo(cusInfo *pcus);

/*
	기능 : DVD 정보 출력
	반환 : void
*/
void ShowDVDInfo(dvdInfo * pDVD);

/*
	기능 : DVD 장르 출력
	반환 : void
*/
void ShowGenre(int gen);

/*
	기능 : DVD 대여 상태 출력
	반환 : void
*/
void ShowRentState(int rentState);

/*
	기능 : DVD를 대여한 고객 정보 출력
	반환 : void
*/
void ShowRentInfo(RentInfo *pDVD);

/*
	기능 : 고객이 대여한 DVD의 ISBN 출력
	반환 : void
*/
void ShowRentInfoUser(RentInfo *pDVD);

#endif // !__SCREENOUT_H__


