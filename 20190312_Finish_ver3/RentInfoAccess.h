#ifndef _RENTACCESS_H_
#define _RENTACCESS_H_

#include "RentInfo.h"
#include "dvdInfo.h"
#include "RentLinkedList.h"

/*
	기능 : DVD의 대여 상태 체크
	반환 : 대여중(RENTED)일 경우 1 반환, 아닐경우 0 반환
*/
int RentDVDState(dvdInfo *dvdPtr);

/*
	기능 : 대여 리스트에 데이터를 올림
	반환 : void
*/
void AddRentListInfo(RentList *rentList, dvdInfo *dvdPtr, cusInfo *cusPtr, int day);

/*
	기능 : 대여 리스트의 ISBN과 입력한 ISBN이 동일한 ISBN인지 확인
	반환 : 동일한 ISBN인 경우 0, 아닐경우 0이외의 값을 반환
*/
int RentISBNCompare(RentInfo *prent, char *ISBN);

/*
	기능 : DVD를 대여한 회원의 정보 출력
	반환 : void
*/
void SearchRentInfo(RentList *rentList, char *ISBN);

/*
	기능 : 입력한 날짜 사이에서 회원이 빌린 DVD의 ISBN 출력
	반환 : void
*/
void SearchRentUserInfoByDays(RentList *rentList, char *ID, int day1, int day2);

/*
	기능 : 매개변수의 데이터를 갖는 RentInfo 변수 생성
	반환 : 동적 메모리 할당한 RentInfo* 자료형의 변수 반환
*/
RentInfo *MakeRentNode(dvdInfo *dvdPtr, cusInfo *cusPtr, int day);

#endif // !_RENTACCESS_H_

