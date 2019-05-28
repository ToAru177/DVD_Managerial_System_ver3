
#ifndef __CUSACCESS_H__
#define __CUSACCESS_H__

#include "cusInfo.h"


cusInfo *MakeCusNode(void);

/*
	기능 : cusInfo 할당 및 저장
	반환 : 성공 시 등록된 정보의 개수,
	       실패 시 0을 반환.
*/
void AddCusInfo(cusInfo **Head,char * ID, char * name, char * num);

/*
	기능 : 해당 고객 ID의 정보를 가지고 있는
			포인터를 반환
	반환 : 등록 안된 ID의 경우 NULL 포인터 반환.
*/
cusInfo * GetCusPtrByID(cusInfo *Head,char * ID);

/*
	기능 : 가입된 ID인지 체크
	반환 : 가입되었으면 1, 아니면 0을 반환.
*/
int IsregistID(cusInfo *Head,char * ID);

#endif // !__CUSACCESS_H__