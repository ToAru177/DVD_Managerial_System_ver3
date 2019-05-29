#ifndef __DVDACCESS_H__
#define __DVDACCESS_H__

#include "dvdInfo.h"
#include "DVDLinkedList.h"

/*
	기능 : DVD 리스트에 데이터를 올림
	반환 : void
*/
void AddDVDInfo(DVDList *dvdList, char * ISBN, char * title, int genre);

/*
	기능 : 등록된 ISBN인지 체크.
	반환 : 등록되었으면 FALSE(0), 아니면 TURE(1)을 반환.
*/
int IsRegistISBN(DVDList *dvdList, char * ISBN);

/*
	기능 : DVD 리스트의 ISBN과 입력한 ISBN이 동일한 ISBN인지 확인
	반환 : 동일한 ISBN인 경우 0, 아닐경우 0이외의 값을 반환
*/
int ISBNCompare(dvdInfo *pdvd, char *ISBN);

/*
	기능 : 매개변수의 데이터를 갖는 dvdInfo 변수 생성
	반환 : 동적 메모리 할당한 dvdInfo* 자료형의 변수 반환
*/
dvdInfo *MakeDVDNode(char *ISBN, char *title, int genre);

#endif