#include "common.h"
#include "cusInfoAccess.h"
#include "dvdInfoAccess.h"
#include "RentInfoAccess.h"
#include "screenOut.h"
#include "CusLinkedList.h"
#include "DVDLinkedList.h"
#include "RentLinkedList.h"

void RegisterCustomer(CusList *cusList)
{
	char ID[ID_LEN];
	char name[NAME_LEN];
	char phoneNum[PHONE_LEN];

	system("cls");
	printf("\t\t========= ȸ�� ���� =========\n");
	printf("\t\tID �Է� : ");
	gets(ID);

	if (cusList->numOfData != 0)
	{
		if (!IsregistID(cusList, ID)) {

			puts("\t\t�ش� ID�� ������Դϴ�.");
			printf("\t\t=============================\n");
			getchar();
			return;
		}
	}
	
	printf("\t\t�̸� �Է� : ");
	gets(name);

	printf("\t\t��ȭ��ȣ �Է� : ");
	gets(phoneNum);

	AddCusInfo(cusList, ID, name, phoneNum);

	puts("\t\tȸ�� ������ �Ǿ����ϴ�.");
	printf("\t\t=============================\n");
	getchar();
}

void SearchCusInfo(CusList *cusList)
{
	char ID[ID_LEN];
	cusInfo *cus;

	system("cls");

	printf("\t\t========= ȸ�� ��ȸ =========\n");
	printf("\t\tã�� ID �Է� : ");
	gets(ID);


	if (CusLFirst(cusList, &cus)) {
		if (!IDCompare(cus, ID)) {
			ShowCustomerInfo(cus);
			return;
		}

		while (CusLNext(cusList, &cus))
			if (!IDCompare(cus, ID)) {
				ShowCustomerInfo(cus);
				return;
			}
	}
	
	printf("\t\t=============================\n");
	printf("\t\t�������� �ʴ� ID �Դϴ�.\n");
	printf("\t\t=============================\n");	
	getchar();
	
}

void RegistDVD(DVDList *dvdList)
{
	char ISBN[ISBN_LEN];
	char title[TITLE_LEN];
	int genre;

	system("cls");

	printf("\t\t================== DVD ��� ================\n");

	printf("\t\tISBN �Է� : ");
	gets(ISBN);

	if (dvdList->numOfData != 0)
	{
		if (!IsRegistISBN(dvdList, ISBN)) {

			puts("\t\t�ش� ISBN�� �̹� ��ϵǾ����ϴ�.");
			printf("\t\t============================================\n");
			getchar();
			return;
		}
	}

	printf("\t\t���� �Է� : ");
	gets(title);

	printf("\t\t�帣 �Է� (�׼� : 1, �ڹ� : 2, SF : 3, �θ�ƽ : 4) : ");
	scanf("%d", &genre);
	getchar();

	AddDVDInfo(dvdList, ISBN, title, genre);

	puts("\t\t����� �Ϸ�Ǿ����ϴ�.");
	printf("\t\t============================================\n");
	getchar();
}

void SearchDVDInfo(DVDList *dvdList)
{
	char ISBN[ISBN_LEN];
	dvdInfo *dvdPtr;

	system("cls");

	printf("\t\t================== DVD ��ȸ ================\n");


	printf("\t\tã�� ISBN �Է� : ");
	gets(ISBN);

	if (DVDLFirst(dvdList, &dvdPtr)) {
		if (!ISBNCompare(dvdPtr, ISBN)) {
			ShowDVDInfo(dvdPtr);
			return;
		}

		while (DVDLNext(dvdList, &dvdPtr))
			if (!ISBNCompare(dvdPtr, ISBN)) {
				ShowDVDInfo(dvdPtr);
				return;
			}
	}

	printf("\t\t============================================\n");
	puts("\t\t��ϵ��� ���� ISBN�Դϴ�.");
	printf("\t\t============================================\n");
	getchar();
}

void RentDVD(RentList *rentList, DVDList *dvdList, CusList *cusList) {
	char ISBN[ISBN_LEN];
	char ID[ID_LEN];
	int day;
	int state;
	dvdInfo *dvdPtr;
	cusInfo *cusPtr;

	system("cls");

	printf("\t\t================== DVD �뿩 ================\n");

	printf("\t\tID�� �Է� : ");
	gets(ID);

	if (IsregistID(cusList, ID) != 0) {
		puts("\t\t�Էµ� ID�� ���Ե� ���� �����ϴ�.");
		printf("\t\t============================================\n");
		getchar();
		return;
	}
	cusPtr = cusList->cur->data;

	printf("\t\t�뿩�� ISBN �Է� : ");
	gets(ISBN);

	if (IsRegistISBN(dvdList, ISBN) != 0) {
		puts("\t\t��ϵ��� ���� DVD ISBN�Դϴ�.");
		printf("\t\t============================================\n");
		getchar();
		return;
	}
	dvdPtr = dvdList->cur->data;

	state = RentDVDState(dvdPtr);

	if (state) {
		puts("\t\t�뿩 ���� DVD�̹Ƿ�, �뿩�� �Ұ����մϴ�.");
		printf("\t\t============================================\n");
		getchar();
		return;
	}

	printf("\t\t�뿩�� �Է�(yyyymmdd) : ");
	scanf("%d", &day);
	getchar();

	AddRentListInfo(rentList, dvdPtr, cusPtr, day);

	puts("\t\t���� �뿩 �Ǿ����ϴ�.");
	printf("\t\t============================================\n");
	getchar();

}

void ReturnDVD(RentList *rentList, DVDList *dvdList) {
	char ISBN[ISBN_LEN];
	dvdInfo *dvdPtr;
	int state;

	system("cls");

	printf("\t\t================== DVD �ݳ� ================\n");


	printf("\t\t�ݳ� �� ISBN �Է� : ");
	gets(ISBN);

	if (IsRegistISBN(dvdList, ISBN) != 0) {
		puts("\t\t��ϵ��� ���� DVD ISBN�Դϴ�.");
		printf("\t\t============================================\n");
		getchar();
		return;
	}
	dvdPtr = dvdList->cur->data;

	state = RentDVDState(dvdPtr);

	if (state == 0) {
		dvdPtr->rentState = RETURNED;
		puts("\t\t�뿩���� ���� DVD�Դϴ�.");
		printf("\t\t============================================\n");
		getchar();
		return;
	}

	dvdPtr->rentState = RETURNED;

	puts("\t\t�ݳ� �Ǿ����ϴ�.");
	printf("\t\t============================================\n");
	getchar();

}

void SearchRentDVDInfo(RentList *rentList, DVDList *dvdList) {
	char ISBN[ISBN_LEN];
	dvdInfo *dvdPtr;
	RentInfo *rentPtr;

	system("cls");

	printf("\t\t============= DVD �뿩���� ��ȸ ============\n");

	printf("\t\t��ȸ �� ISBN �Է� : ");
	gets(ISBN);
	
	if (IsRegistISBN(dvdList, ISBN) != 0) {
		puts("\t\t��ϵ��� ���� DVD ISBN�Դϴ�.");
		printf("\t\t============================================\n");
		getchar();
		return;
	}
	//dvdPtr = dvdList->cur->data;

	printf("\t\t============================================\n");

	SearchRentInfo(rentList, ISBN);

	getchar();

}

void SearchRentUserInfo(RentList *rentList, CusList *cusList) {
	char ID[ID_LEN];
	int day1, day2;
	cusInfo *cusPtr;

	system("cls");

	printf("\t\t============ User �뿩���� ��ȸ ============\n");

	printf("\t\tID �Է� : ");
	gets(ID);

	if (IsregistID(cusList, ID) != 0) {
		puts("\t\t�Էµ� ID�� ���Ե� ���� �����ϴ�.");
		printf("\t\t============================================\n");
		getchar();
		return;
	}
	cusPtr = cusList->cur->data;

	printf("\t\t�뿩 �Ⱓ �Է�(ex>> 20190315 20190320) : ");
	scanf("%d %d", &day1, &day2);
	getchar();

	printf("\t\t============================================\n");

	SearchRentUserInfoByDays(rentList, ID, day1, day2);

	getchar();

}

void Txtload_CusList(CusList *cusList) {
	int res;
	FILE *load = fopen("CusList.txt", "rt");

	if (load == NULL) {
		printf("CusList ���� �б� ����\n");
		return;
	}

	cusInfo *loadNode;

	while (1) {
		loadNode = (cusInfo *)malloc(sizeof(cusInfo));

		res = fscanf(load, "%s %s %s\n", &loadNode->ID, &loadNode->name, &loadNode->phoneNum);

		if (res == EOF) {
			break;
		}
		CusLInsert(cusList, loadNode);
	}
}

void Txtload_DVDList(DVDList *dvdList) {

	int res;
	dvdInfo *loadNode;
	FILE *load = fopen("DVDList.txt", "rt");
	if (load == NULL) {
		printf("DVDList ���� �б� ����\n");
		return;
	}

	while (1) {
		loadNode = (dvdInfo *)malloc(sizeof(dvdInfo));

		// DVDList.txt
		// ISBN genre rentstate title ������ ����Ǿ� ����
		res = fscanf(load, "%s %d %d", &loadNode->ISBN, &loadNode->genre, &loadNode->rentState);

		if (res == EOF) {
			break;
		}
		fgets(&loadNode->title, TITLE_LEN, load);

		DVDLInsert(dvdList, loadNode);
	}

	return;
}

void Txtload_RentList(RentList *rentList) {

	int res;
	RentInfo *loadNode;
	FILE *load = fopen("RentList.txt", "rt");

	if (load == NULL) {
		printf("RentList ���� �б� ����\n");
		return;
	}

	while (1) {
		loadNode = (RentInfo *)malloc(sizeof(RentInfo));

		res = fscanf(load, "%s %s %s %s %d\n", &loadNode->cusID, &loadNode->cusName, &loadNode->cusPhoneNum, &loadNode->ISBN_NUM, &loadNode->rentDay);
		if (res == EOF) {
			break;
		}
		RentLInsert(rentList, loadNode);
	}
	return;
}

void Txtupload_CusList(CusList *cusList) {

	// ���� ����
	FILE *upload = fopen("CusList.txt", "w");
	cusInfo *uploadNode;

	if (upload == NULL) {
		printf("CusList ���� ���� ����\n");
		return;
	}

	if (CusLFirst(cusList, &uploadNode)) {
		fprintf(upload, "%s %s %s\n", uploadNode->ID, uploadNode->name, uploadNode->phoneNum);

		while(CusLNext(cusList, &uploadNode))
			fprintf(upload, "%s %s %s\n", uploadNode->ID, uploadNode->name, uploadNode->phoneNum);
	}
	fclose(upload);
	free(uploadNode);
	return;
}

void Txtupload_DVDList(DVDList *dvdList) {

	dvdInfo *uploadNode;
	FILE *upload = fopen("DVDList.txt", "w");
	if (upload == NULL) {
		printf("DVDList ���� ���� ����\n");
		return;
	}

	if (DVDLFirst(dvdList, &uploadNode)) {
		fprintf(upload, "%s %d %d %s\n", uploadNode->ISBN, uploadNode->genre, uploadNode->rentState, uploadNode->title);

		while(DVDLNext(dvdList, &uploadNode))
			fprintf(upload, "%s %d %d %s\n", uploadNode->ISBN, uploadNode->genre, uploadNode->rentState, uploadNode->title);
	}
	fclose(upload);
	free(uploadNode);
	return;
}

void Txtupload_RentList(RentList *rentList) {

	RentInfo *uploadNode;
	FILE *upload = fopen("RentList.txt", "w");

	if (upload == NULL) {
		printf("RentList ���� ���� ����\n");
		return;
	}

	if (RentLFirst(rentList, &uploadNode)) {
		fprintf(upload, "%s %s %s %s %d\n", uploadNode->cusID, uploadNode->cusName, uploadNode->cusPhoneNum, uploadNode->ISBN_NUM, uploadNode->rentDay);

		while(RentLNext(rentList, &uploadNode))
			fprintf(upload, "%s %s %s %s %d\n", uploadNode->cusID, uploadNode->cusName, uploadNode->cusPhoneNum, uploadNode->ISBN_NUM, uploadNode->rentDay);
	}
	fclose(upload);
	free(uploadNode);
	return;
}
