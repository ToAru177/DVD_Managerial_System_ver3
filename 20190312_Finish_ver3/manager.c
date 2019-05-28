#include "common.h"
#include "cusInfo.h"
#include "dvdInfo.h"
#include "cusInfoAccess.h"
#include "dvdInfoAccess.h"
#include "screenOut.h"

cusInfo *Head = NULL;
dvdInfo *DVD_Head = NULL;
dvdRentInfo *Rent_Head = NULL;

static int NumOfCusInfo = 0;
static int NumOfDVDInfo = 0;
static int NumOfRentInfo = 0;

// 회원 가입 
void RegisterCustomer(void)
{
	char ID[ID_LEN];
	char name[NAME_LEN];
	char phoneNum[PHONE_LEN];

	system("cls");
	printf("\t\t========= 회원 가입 =========\n");
	printf("\t\tID 입력 : ");
	gets(ID);

	if (IsregistID(Head, ID))
	{
		puts("\t\t해당 ID는 사용중입니다.");
		printf("\t\t=============================\n");
		getchar();
		return;
	}

	printf("\t\t이름 입력 : ");
	gets(name);

	printf("\t\t전화번호 입력 : ");
	gets(phoneNum);

	AddCusInfo(&Head, ID, name, phoneNum);

	puts("\t\t회원 가입이 되었습니다.");
	printf("\t\t=============================\n");
	getchar();
}

// 회원 조회
void SearchCusInfo(void)
{
	char ID[ID_LEN];
	cusInfo * cusPtr;

	system("cls");

	printf("\t\t========= 회원 조회 =========\n");
	printf("\t\t찾을 ID 입력 : ");
	gets(ID);

	cusPtr = GetCusPtrByID(Head, ID);
	if (cusPtr == 0)
	{
		puts("\t\t존재하지 않는 ID입니다.");
		printf("\t\t=============================\n");
		getchar();
		return;
	}

	ShowCustomerInfo(cusPtr);
}

// DVD 등록
void RegistDVD(void)
{
	char ISBN[ISBN_LEN];
	char title[TITLE_LEN];
	int genre;

	system("cls");

	printf("\t\t================== DVD 등록 ================\n");

	printf("\t\tISBN 입력 : ");
	gets(ISBN);

	if (IsRegistISBN(DVD_Head, ISBN))
	{
		puts("\t\t해당 ISBN은 이미 등록되었습니다.");
		printf("\t\t============================================\n");
		getchar();
		return;
	}

	printf("\t\t제목 입력 : ");
	gets(title);

	printf("\t\t장르 입력 (액션 : 1, 코믹 : 2, SF : 3, 로맨틱 : 4) : ");
	scanf("%d", &genre);
	getchar();

	AddDVDInfo(&DVD_Head, ISBN, title, genre);

	puts("\t\t등록이 완료되었습니다.");
	printf("\t\t============================================\n");
	getchar();
}

// DVD 조회
void SearchDVDInfo(void)
{
	char ISBN[ISBN_LEN];
	dvdInfo *dvdPtr;

	system("cls");

	printf("\t\t================== DVD 조회 ================\n");


	printf("\t\t찾는 ISBN 입력 : ");
	gets(ISBN);

	dvdPtr = GetDVDPtrByISBN(DVD_Head, ISBN);
	if (dvdPtr == 0)
	{
		puts("\t\t등록되지 않은 ISBN입니다.");
		printf("\t\t============================================\n");
		getchar();
		return;
	}

	ShowDVDInfo(dvdPtr);
}

// DVD 대여
void RentDVD(void) {
	char ISBN[ISBN_LEN];
	char ID[ID_LEN];
	int day;
	int state;
	dvdInfo *dvdPtr;
	cusInfo *cusPtr;

	system("cls");

	printf("\t\t================== DVD 대여 ================\n");


	printf("\t\tID를 입력 : ");
	gets(ID);

	cusPtr = GetCusPtrByID(Head, ID);

	if (cusPtr == NULL) {
		puts("\t\t입력된 ID로 가입된 고객이 없습니다.");
		printf("\t\t============================================\n");
		getchar();
		return;
	}

	printf("\t\t대여할 ISBN 입력 : ");
	gets(ISBN);

	dvdPtr = GetDVDPtrByISBN(DVD_Head, ISBN);

	if (dvdPtr == NULL) {
		puts("\t\t등록되지 않은 DVD ISBN입니다.");
		printf("\t\t============================================\n");
		getchar();
		return;
	}

	state = RentDVDState(dvdPtr);

	if (state) {
		puts("\t\t대여 중인 DVD이므로, 대여가 불가능합니다.");
		printf("\t\t============================================\n");
		getchar();
		return;
	}

	printf("\t\t대여일 입력(yyyymmmdd) : ");
	scanf("%d", &day);
	getchar();

	AddRentListInfo(&Rent_Head, dvdPtr, cusPtr, day);

	puts("\t\t정상 대여 되었습니다.");
	printf("\t\t============================================\n");
	getchar();

}

// DVD 반납
void ReturnDVD(void) {
	char ISBN[ISBN_LEN];
	dvdInfo *dvdPtr;
	int state;

	system("cls");

	printf("\t\t================== DVD 반납 ================\n");


	printf("\t\t반납 할 ISBN 입력 : ");
	gets(ISBN);

	dvdPtr = GetDVDPtrByISBN(DVD_Head, ISBN);

	if (dvdPtr == NULL) {
		puts("\t\t등록되지 않은 DVD ISBN입니다.");
		printf("\t\t============================================\n");
		getchar();
		return;
	}

	state = RentDVDState(dvdPtr);

	if (state == 0) {
		dvdPtr->rentState = RETURNED;
		puts("\t\t대여되지 않은 DVD입니다.");
		printf("\t\t============================================\n");
		getchar();
		return;
	}

	dvdPtr->rentState = RETURNED;

	puts("\t\t반납 되었습니다.");
	printf("\t\t============================================\n");
	getchar();

}

// 대역내역 죄회 - ISBN
void SearchRentDVDInfo(void) {
	char ISBN[ISBN_LEN];
	dvdInfo *dvdPtr;

	system("cls");

	printf("\t\t============= DVD 대여내역 조회 ============\n");

	printf("\t\t조회 할 ISBN 입력 : ");
	gets(ISBN);
	dvdPtr = GetDVDPtrByISBN(DVD_Head, ISBN);

	if (dvdPtr == NULL) {
		puts("\t\t등록되지 않은 DVD ISBN입니다.");
		printf("\t\t============================================\n");
		getchar();
		return;
	}

	printf("\t\t============================================\n");

	SearchRentInfo(Rent_Head, ISBN);
	getchar();

}

// 대여내역 조회 - ID
void SearchRentUserInfo(void) {
	char ID[ID_LEN];
	int day1, day2;
	cusInfo *cusPtr;

	system("cls");

	printf("\t\t============ User 대여내역 조회 ============\n");

	printf("\t\tID 입력 : ");
	gets(ID);

	cusPtr = GetCusPtrByID(Head, ID);

	if (cusPtr == NULL) {
		puts("\t\t입력된 ID로 가입된 고객이 없습니다.");
		printf("\t\t============================================\n");
		getchar();
		return;
	}

	printf("\t\t대여 기간 입력(ex>> 20190315 20190320) : ");
	scanf("%d %d", &day1, &day2);
	getchar();

	printf("\t\t============================================\n");

	SearchRentUserInfoByDays(Rent_Head, ID, day1, day2);

	getchar();

}


// CusList 불러 오기
void Txtload_CusList() {
	int res;
	FILE *load = fopen("CusList.txt", "rt");

	if (load == NULL) {
		printf("CusList 파일 읽기 실패\n");
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

// DVDList 읽어 오기
void Txtload_DVDList(void) {

	int res;
	dvdInfo *MidNode = NULL;
	FILE *load = fopen("DVDList.txt", "rt");
	if (load == NULL) {
		printf("DVDList 파일 읽기 실패\n");
		return;
	}

	while (1) {
		MidNode = (dvdInfo *)malloc(sizeof(dvdInfo));
		MidNode->next = NULL;
		// DVDList.txt
		// ISBN genre rentstate title 순으로 저장되어 있음
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

// RentList 읽어 오기
void Txtload_RentList(void) {

	int res;
	dvdRentInfo *MidNode = NULL;
	FILE *load = fopen("RentList.txt", "rt");

	if (load == NULL) {
		printf("RentList 파일 읽기 실패\n");
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

// CusList 기록 하기
void Txtupload_CusList() {

	FILE *upload = fopen("CusList.txt", "a");
	cusInfo *temp;

	if (upload == NULL) {
		printf("CusList 파일 생성 실패\n");
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

// DVDList 기록 하기
void Txtupload_DVDList(void) {

	dvdInfo *temp = NULL;
	FILE *upload = fopen("DVDList.txt", "a");
	if (upload == NULL) {
		printf("DVDList 파일 생성 실패\n");
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
		// ISBN genre rentstate title 순으로 저장
		fprintf(upload, "%s %d %d %s\n", temp->ISBN, temp->genre, temp->rentState, temp->title);

		temp = temp->next;
	}
	fprintf(upload, "%s %d %d %s\n", temp->ISBN, temp->genre, temp->rentState, temp->title);

	fclose(upload);
	free(temp);
	return;
}

// RentList 기록 하기
void Txtupload_RentList(void) {

	dvdRentInfo *temp = NULL;
	FILE *upload = fopen("RentList.txt", "a");

	if (upload == NULL) {
		printf("RentList 파일 생성 실패\n");
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