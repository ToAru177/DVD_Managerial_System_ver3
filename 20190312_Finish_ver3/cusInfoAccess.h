#ifndef __CUSACCESS_H__
#define __CUSACCESS_H__

#include "cusInfo.h"
#include "CusLinkedList.h"

/*
	기능 : 매개변수의 데이터를 갖는 cusInfo 변수 생성
	반환 : 동적 메모리 할당한 cusInfo* 자료형의 변수 반환
*/
cusInfo *MakeCusNode(char *ID, char *name, char *phone);

/*
	기능 : 회원 리스트에 데이터를 올림
	반환 : void
*/
void AddCusInfo(CusList *cusList, char *ID, char *name, char *phone);

/*
	기능 : 회원 리스트의 ID와 입력한 ID가 동일한 ID인지 확인
	반환 : 동일한 ID인 경우 0, 아닐경우 0이외의 값을 반환
*/
int IDCompare(cusInfo *pcus, char *ID);

/*
	기능 : 가입된 ID인지 체크
	반환 : 가입되었으면 FALSE(0), 아니면 TURE(1)을 반환.
*/
int IsregistID(CusList *Head,char * ID);

#endif // !__CUSACCESS_H__