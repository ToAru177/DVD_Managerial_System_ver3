#include "common.h"
#include "cusInfo.h"
#include "dvdInfo.h"
#include "RentInfo.h"
#include "screenOut.h"
#include "CusLinkedList.h"
#include "DVDLinkedList.h"
#include "RentLinkedList.h"

void ShowMenu(void)
{
	system("cls"); //stdlib.h

	printf("\t\t=========== 메 뉴 ===========\n");
	printf("\t\t 1. 고객 관리 \n");
	printf("\t\t 2. DVD 관리 \n");
	printf("\t\t 3. DVD 대여/반납 \n");
	printf("\t\t 4. 대여 정보 조회 \n");
	printf("\t\t 5. 종료 \n");
	printf("\t\t=============================\n");
	printf("\t\t 선택 >> ");
}

void ShowCusMenu(CusList *cusList)
{
	int sel;

	system("cls"); //stdlib.h

	printf("\t\t====== 고객 관리 메뉴 =======\n");
	printf("\t\t 1. 회원 가입 \n");
	printf("\t\t 2. ID 조회 \n");
	printf("\t\t 3. 이전으로 \n");
	printf("\t\t=============================\n");
	printf("\t\t 선택 >> ");
	scanf("%d", &sel);
	getchar();
	switch (sel) {
	case 1:
		RegisterCustomer(cusList);
		break;

	case 2:
		SearchCusInfo(cusList);
		break;

	case 3:
		return;
		break;
	}
}

void ShowDVDMenu(DVDList *dvdList)
{
	int sel;

	system("cls"); //stdlib.h

	printf("\t\t======= DVD 관리 메뉴 =======\n");
	printf("\t\t 1. DVD 등록 \n");
	printf("\t\t 2. DVD 조회 \n");
	printf("\t\t 3. 이전으로 \n");
	printf("\t\t=============================\n");
	printf("\t\t 선택 >> ");
	scanf("%d", &sel);
	getchar();
	switch (sel) {
	case 1:
		RegistDVD(dvdList);
		break;

	case 2:
		SearchDVDInfo(dvdList);
		break;

	case 3:
		return;
		break;
	}
}

void ShowDVDRentMenu(RentList *rentList, DVDList *dvdList, CusList *cusList)
{
	int sel;

	system("cls"); //stdlib.h

	printf("\t\t====== DVD 대여 / 반납 ======\n");
	printf("\t\t 1. DVD 대여 \n");
	printf("\t\t 2. DVD 반납 \n");
	printf("\t\t 3. 이전으로 \n");
	printf("\t\t=============================\n");
	printf("\t\t 선택 >> ");
	scanf("%d", &sel);
	getchar();
	switch(sel) {
	case 1:
		RentDVD(rentList, dvdList, cusList);
		break;

	case 2:
		ReturnDVD(rentList, dvdList);
		break;

	case 3:
		return;
		break;
	}
}

void ShowSearchMenu(RentList *rentList, DVDList *dvdList, CusList *cusList)
{
	int sel;
	system("cls"); //stdlib.h

	printf("\t\t======= 대여 정보 조회 ======\n");
	printf("\t\t 1. ISBN 대여 기록 \n");
	printf("\t\t 2. User 대여 기록 \n");
	printf("\t\t 3. 이전으로 \n");
	printf("\t\t=============================\n");
	printf("\t\t 선택 >> ");
	scanf("%d", &sel);
	getchar();
	switch (sel) {
	case 1:
		SearchRentDVDInfo(rentList, dvdList);
		break;

	case 2:
		SearchRentUserInfo(rentList, cusList);
		break;

	case 3:
		return;
		break;
	}
}

void ShowCustomerInfo(cusInfo *pcus)
{
	printf("\t\t=============================\n");
	printf("\t\t ID : %s \n", pcus->ID);
	printf("\t\t Name : %s \n", pcus->name);
	printf("\t\t Phone : %s \n", pcus->phoneNum);
	printf("\t\t=============================\n");

	getchar();
}

void ShowDVDInfo(dvdInfo * pDVD)
{
	printf("\t\t============================================\n");
	printf("\t\t ISBN : %s \n", pDVD->ISBN);
	printf("\t\t TITLE : %s", pDVD->title);
	printf("\t\t 장르 : "); ShowGenre(pDVD->genre);
	printf("\n");
	printf("\t\t 대여 상태 : "); ShowRentState(pDVD->rentState);
	printf("\t\t============================================\n");

	getchar();
}

void ShowGenre(int gen)
{
	switch (gen)
	{
	case ACTION:
		printf("액션");
		break;
	case COMIC:
		printf("코믹");
		break;
	case SF:
		printf("SF");
		break;
	case ROMANTIC:
		printf("로맨스");
		break;
	}
}

void ShowRentState(int rentState) {
	if (rentState == RENTED)
		printf("대여 중(대여 불가)\n");
	else
		printf("대여 가능\n");
}

void ShowRentInfo(RentInfo *pDVD) {
	printf("\t\t 고객 ID : %s\n", pDVD->cusID);
	printf("\t\t 고객 이름 : %s\n", pDVD->cusName);
	printf("\t\t 고객 폰 번호 : %s\n", pDVD->cusPhoneNum);
	printf("\t\t 대여일 : %d\n", pDVD->rentDay);
	printf("\t\t============================================\n");
}

void ShowRentInfoUser(RentInfo *pDVD) {
	printf("\t\t ISBN : %s\n", pDVD->ISBN_NUM);
}