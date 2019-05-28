#ifndef __CUSACCESS_H__
#define __CUSACCESS_H__

#include "cusInfo.h"
#include "CusLinkedList.h"

cusInfo *MakeCusNode(char *ID, char *name, char *phone);

/*
	기능 : cusInfo 할당 및 저장
	반환 : 성공 시 등록된 정보의 개수,
	       실패 시 0을 반환.
*/
void AddCusInfo(CusList *cusList, char *ID, char *name, char *phone);

/*
	기능 : 
	반환 : 등록 안된 ID의 경우 NULL 포인터 반환.
*/
int IDCompare(cusInfo *pcus, char *ID);

/*
	기능 : 가입된 ID인지 체크
	반환 : 가입되었으면 1, 아니면 0을 반환.
*/
int IsregistID(CusList *Head,char * ID);

#endif // !__CUSACCESS_H__