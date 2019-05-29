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

	printf("\t\t=========== �� �� ===========\n");
	printf("\t\t 1. �� ���� \n");
	printf("\t\t 2. DVD ���� \n");
	printf("\t\t 3. DVD �뿩/�ݳ� \n");
	printf("\t\t 4. �뿩 ���� ��ȸ \n");
	printf("\t\t 5. ���� \n");
	printf("\t\t=============================\n");
	printf("\t\t ���� >> ");
}

void ShowCusMenu(CusList *cusList)
{
	int sel;

	system("cls"); //stdlib.h

	printf("\t\t====== �� ���� �޴� =======\n");
	printf("\t\t 1. ȸ�� ���� \n");
	printf("\t\t 2. ID ��ȸ \n");
	printf("\t\t 3. �������� \n");
	printf("\t\t=============================\n");
	printf("\t\t ���� >> ");
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

	printf("\t\t======= DVD ���� �޴� =======\n");
	printf("\t\t 1. DVD ��� \n");
	printf("\t\t 2. DVD ��ȸ \n");
	printf("\t\t 3. �������� \n");
	printf("\t\t=============================\n");
	printf("\t\t ���� >> ");
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

	printf("\t\t====== DVD �뿩 / �ݳ� ======\n");
	printf("\t\t 1. DVD �뿩 \n");
	printf("\t\t 2. DVD �ݳ� \n");
	printf("\t\t 3. �������� \n");
	printf("\t\t=============================\n");
	printf("\t\t ���� >> ");
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

	printf("\t\t======= �뿩 ���� ��ȸ ======\n");
	printf("\t\t 1. ISBN �뿩 ��� \n");
	printf("\t\t 2. User �뿩 ��� \n");
	printf("\t\t 3. �������� \n");
	printf("\t\t=============================\n");
	printf("\t\t ���� >> ");
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
	printf("\t\t �帣 : "); ShowGenre(pDVD->genre);
	printf("\n");
	printf("\t\t �뿩 ���� : "); ShowRentState(pDVD->rentState);
	printf("\t\t============================================\n");

	getchar();
}

void ShowGenre(int gen)
{
	switch (gen)
	{
	case ACTION:
		printf("�׼�");
		break;
	case COMIC:
		printf("�ڹ�");
		break;
	case SF:
		printf("SF");
		break;
	case ROMANTIC:
		printf("�θǽ�");
		break;
	}
}

void ShowRentState(int rentState) {
	if (rentState == RENTED)
		printf("�뿩 ��(�뿩 �Ұ�)\n");
	else
		printf("�뿩 ����\n");
}

void ShowRentInfo(RentInfo *pDVD) {
	printf("\t\t �� ID : %s\n", pDVD->cusID);
	printf("\t\t �� �̸� : %s\n", pDVD->cusName);
	printf("\t\t �� �� ��ȣ : %s\n", pDVD->cusPhoneNum);
	printf("\t\t �뿩�� : %d\n", pDVD->rentDay);
	printf("\t\t============================================\n");
}

void ShowRentInfoUser(RentInfo *pDVD) {
	printf("\t\t ISBN : %s\n", pDVD->ISBN_NUM);
}