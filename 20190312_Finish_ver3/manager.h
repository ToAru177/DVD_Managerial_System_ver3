#ifndef __MANAGER_H
#define __MANAGER_H

#include "CusLinkedList.h"
#include "DVDLinkedList.h"
#include "RentLinkedList.h"

/*
	기능 : 회원 가입
	반환 : void
*/
void RegisterCustomer(CusList *cusList);

/*
	기능 : 회원 조회
	반환 : void
*/
void SearchCusInfo(CusList *cusList);


/*
	기능 : DVD 등록
	반환 : void
*/
void RegistDVD(DVDList *dvdList);

/*
	기능 : DVD 조회
	반환 : void
*/
void SearchDVDInfo(DVDList *dvdList);

/*
	기능 : DVD 대여
	반환 : void
*/
void RentDVD(RentList *rentList, DVDList *dvdList, CusList *cusList);

/*
	기능 : DVD 반납
	반환 : void
*/
void ReturnDVD(RentList *rentList, DVDList *dvdList);

/*
	기능 : 특정 DVD를 빌린 회원들의 정보 조회
	반환 : void
*/
void SearchRentDVDInfo(RentList *rentList, DVDList *dvdList);

/*
	기능 : 특정 기간 동안 회원이 대여한 DVD의 ISBN 조회
	반환 : void
*/
void SearchRentUserInfo(RentList *rentList, CusList *cusList);

/*
	기능 : 파일(.txt)을 입력 받아 회원 리스트 정보 갱신
	반환 : void
*/
void Txtload_CusList(CusList *cusList);

/*
	기능 : 파일(.txt)을 입력 받아 DVD 리스트 정보 갱신
	반환 : void
*/
void Txtload_DVDList(DVDList *dvdList);

/*
	기능 : 파일(.txt)을 입력 받아 대여 리스트 정보 갱신
	반환 : void
*/
void Txtload_RentList(RentList *rentList);

/*
	기능 : 회원 리스트 정보를 파일(.txt)로 출력
	반환 : void
*/
void Txtupload_CusList(CusList *cusList);

/*
	기능 : DVD 리스트 정보를 파일(.txt)로 출력
	반환 : void
*/
void Txtupload_DVDList(DVDList *dvdList	);

/*
	기능 : 대여 리스트 정보를 파일(.txt)로 출력
	반환 : void
*/
void Txtupload_RentList(RentList *rentList);

#endif // __MANAGER_H

