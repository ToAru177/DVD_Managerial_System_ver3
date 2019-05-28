#include "common.h"
#include "cusInfoAccess.h"
#include "dvdInfoAccess.h"
#include "screenOut.h"
#include "CusLinkedList.h"
#include "DVDLinkedList.h"
#include "RentLinkedList.h"

// ȸ�� ���� 
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


// ȸ�� ��ȸ
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


// DVD ���
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

// DVD ��ȸ
void SearchDVDInfo(DVDList *dvdList)
{
	char ISBN[ISBN_LEN];
	dvdInfo *dvdPtr;

	system("cls");

	printf("\t\t================== DVD ��ȸ ================\n");


	printf("\t\tã�� ISBN �Է� : ");
	gets(ISBN);


	if (DVDLFirst(dvdList, &dvdPtr)) {
		if (!IDCompare(dvdPtr, ISBN)) {
			ShowDVDInfo(dvdPtr);
			return;
		}

		while (DVDLNext(dvdList, &dvdPtr))
			if (!IDCompare(dvdPtr, ISBN)) {
				ShowDVDInfo(dvdPtr);
				return;
			}
	}

	printf("\t\t============================================\n");
	puts("\t\t��ϵ��� ���� ISBN�Դϴ�.");
	printf("\t\t============================================\n");
	getchar();
}


// DVD �뿩
void RentDVD(RentList *rentList) {
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

	cusPtr = GetCusPtrByID(Head, ID);

	if (cusPtr == NULL) {
		puts("\t\t�Էµ� ID�� ���Ե� ���� �����ϴ�.");
		printf("\t\t============================================\n");
		getchar();
		return;
	}

	printf("\t\t�뿩�� ISBN �Է� : ");
	gets(ISBN);

	dvdPtr = GetDVDPtrByISBN(DVD_Head, ISBN);

	if (dvdPtr == NULL) {
		puts("\t\t��ϵ��� ���� DVD ISBN�Դϴ�.");
		printf("\t\t============================================\n");
		getchar();
		return;
	}

	state = RentDVDState(dvdPtr);

	if (state) {
		puts("\t\t�뿩 ���� DVD�̹Ƿ�, �뿩�� �Ұ����մϴ�.");
		printf("\t\t============================================\n");
		getchar();
		return;
	}

	printf("\t\t�뿩�� �Է�(yyyymmmdd) : ");
	scanf("%d", &day);
	getchar();

	AddRentListInfo(&Rent_Head, dvdPtr, cusPtr, day);

	puts("\t\t���� �뿩 �Ǿ����ϴ�.");
	printf("\t\t============================================\n");
	getchar();

}

// DVD �ݳ�
void ReturnDVD(RentList *rentList) {
	char ISBN[ISBN_LEN];
	dvdInfo *dvdPtr;
	int state;

	system("cls");

	printf("\t\t================== DVD �ݳ� ================\n");


	printf("\t\t�ݳ� �� ISBN �Է� : ");
	gets(ISBN);

	dvdPtr = GetDVDPtrByISBN(DVD_Head, ISBN);

	if (dvdPtr == NULL) {
		puts("\t\t��ϵ��� ���� DVD ISBN�Դϴ�.");
		printf("\t\t============================================\n");
		getchar();
		return;
	}

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

/*
// �뿪���� ��ȸ - ISBN
void SearchRentDVDInfo(void) {
	char ISBN[ISBN_LEN];
	dvdInfo *dvdPtr;

	system("cls");

	printf("\t\t============= DVD �뿩���� ��ȸ ============\n");

	printf("\t\t��ȸ �� ISBN �Է� : ");
	gets(ISBN);
	dvdPtr = GetDVDPtrByISBN(DVD_Head, ISBN);

	if (dvdPtr == NULL) {
		puts("\t\t��ϵ��� ���� DVD ISBN�Դϴ�.");
		printf("\t\t============================================\n");
		getchar();
		return;
	}

	printf("\t\t============================================\n");

	SearchRentInfo(Rent_Head, ISBN);
	getchar();

}

// �뿩���� ��ȸ - ID
void SearchRentUserInfo(void) {
	char ID[ID_LEN];
	int day1, day2;
	cusInfo *cusPtr;

	system("cls");

	printf("\t\t============ User �뿩���� ��ȸ ============\n");

	printf("\t\tID �Է� : ");
	gets(ID);

	cusPtr = GetCusPtrByID(Head, ID);

	if (cusPtr == NULL) {
		puts("\t\t�Էµ� ID�� ���Ե� ���� �����ϴ�.");
		printf("\t\t============================================\n");
		getchar();
		return;
	}

	printf("\t\t�뿩 �Ⱓ �Է�(ex>> 20190315 20190320) : ");
	scanf("%d %d", &day1, &day2);
	getchar();

	printf("\t\t============================================\n");

	SearchRentUserInfoByDays(Rent_Head, ID, day1, day2);

	getchar();

}


// CusList �ҷ� ����
void Txtload_CusList() {
	int res;
	FILE *load = fopen("CusList.txt", "rt");

	if (load == NULL) {
		printf("CusList ���� �б� ����\n");
		return;
	}

	cusInfo *MidNode = NULL;

	while (1) {
		MidNode = (cusInfo *)malloc(sizeof(cusInfo));
		MidNode->next = NULL;

		res = fscanf(load, "%s %s %s\n", &MidNode->ID, &MidNode->name, &MidNode->phoneNum);

		if (res == EOF) {
			break;
		}
		NumOfCusInfo++;

		if (Head == NULL) {
			Head = MidNode;
		}

		else {
			cusInfo *temp = Head;
			while (temp->next != NULL) {
				temp = temp->next;
			}
			temp->next = MidNode;
		}

	}

}

// DVDList �о� ����
void Txtload_DVDList(void) {

	int res;
	dvdInfo *MidNode = NULL;
	FILE *load = fopen("DVDList.txt", "rt");
	if (load == NULL) {
		printf("DVDList ���� �б� ����\n");
		return;
	}

	while (1) {
		MidNode = (dvdInfo *)malloc(sizeof(dvdInfo));
		MidNode->next = NULL;
		// DVDList.txt
		// ISBN genre rentstate title ������ ����Ǿ� ����
		res = fscanf(load, "%s %d %d", &MidNode->ISBN, &MidNode->genre, &MidNode->rentState);

		if (res == EOF) {
			break;
		}
		fgets(&MidNode->title, TITLE_LEN, load);

		NumOfDVDInfo++;

		if (DVD_Head == NULL) {
			DVD_Head = MidNode;
		}

		else {
			dvdInfo *temp = DVD_Head;
			while (temp->next != NULL) {
				temp = temp->next;
			}
			temp->next = MidNode;
		}
	}
	return;

}

// RentList �о� ����
void Txtload_RentList(void) {

	int res;
	dvdRentInfo *MidNode = NULL;
	FILE *load = fopen("RentList.txt", "rt");

	if (load == NULL) {
		printf("RentList ���� �б� ����\n");
		return;
	}

	while (1) {
		MidNode = (dvdRentInfo *)malloc(sizeof(dvdRentInfo));
		MidNode->next = NULL;

		res = fscanf(load, "%s %s %s %s %d\n", &MidNode->cusID, &MidNode->cusName, &MidNode->cusPhoneNum, &MidNode->ISBN_NUM, &MidNode->rentDay);
		if (res == EOF) {
			break;
		}
		NumOfRentInfo++;

		if (Rent_Head == NULL) {
			Rent_Head = MidNode;
		}

		else {
			dvdRentInfo *temp = Rent_Head;
			while (temp->next != NULL) {
				temp = temp->next;
			}
			temp->next = MidNode;
		}

	}
	return;
}

// CusList ��� �ϱ�
void Txtupload_CusList() {

	FILE *upload = fopen("CusList.txt", "a");
	cusInfo *temp;

	if (upload == NULL) {
		printf("CusList ���� ���� ����\n");
		return;
	}

	temp = (cusInfo *)malloc(sizeof(cusInfo));

	temp = Head;

	for (int i = 1; i <= NumOfCusInfo; i++) {
		temp = temp->next;
	}

	if (temp == NULL) {
		return;
	}

	while (temp->next != NULL) {
		fprintf(upload, "%s %s %s\n", temp->ID, temp->name, temp->phoneNum);

		temp = temp->next;
	}
	fprintf(upload, "%s %s %s\n", temp->ID, temp->name, temp->phoneNum);

	fclose(upload);
	free(temp);
	return;
}

// DVDList ��� �ϱ�
void Txtupload_DVDList(void) {

	dvdInfo *temp = NULL;
	FILE *upload = fopen("DVDList.txt", "a");
	if (upload == NULL) {
		printf("DVDList ���� ���� ����\n");
		return;
	}

	temp = (dvdInfo *)malloc(sizeof(dvdInfo));
	temp = DVD_Head;

	for (int i = 1; i <= NumOfDVDInfo; i++) {
		temp = temp->next;
	}

	if (temp == NULL) {
		return;
	}

	while (temp->next != NULL) {
		// DVDList.txt
		// ISBN genre rentstate title ������ ����
		fprintf(upload, "%s %d %d %s\n", temp->ISBN, temp->genre, temp->rentState, temp->title);

		temp = temp->next;
	}
	fprintf(upload, "%s %d %d %s\n", temp->ISBN, temp->genre, temp->rentState, temp->title);

	fclose(upload);
	free(temp);
	return;
}

// RentList ��� �ϱ�
void Txtupload_RentList(void) {

	dvdRentInfo *temp = NULL;
	FILE *upload = fopen("RentList.txt", "a");

	if (upload == NULL) {
		printf("RentList ���� ���� ����\n");
		return;
	}

	temp = (dvdRentInfo *)malloc(sizeof(dvdRentInfo));
	temp = Rent_Head;

	for (int i = 1; i <= NumOfRentInfo; i++) {
		temp = temp->next;
	}

	if (temp == NULL) {
		return;
	}

	while (temp->next != NULL) {
		fprintf(upload, "%s %s %s %s %d\n", temp->cusID, temp->cusName, temp->cusPhoneNum, temp->ISBN_NUM, temp->rentDay);

		temp = temp->next;
	}
	fprintf(upload, "%s %s %s %s %d\n", temp->cusID, temp->cusName, temp->cusPhoneNum, temp->ISBN_NUM, temp->rentDay);

	fclose(upload);
	free(temp);

	return;
}
*/