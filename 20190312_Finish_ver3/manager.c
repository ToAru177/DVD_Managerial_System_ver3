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
	printf("\t\t========= 회원 가입 =========\n");
	printf("\t\tID 입력 : ");
	gets(ID);

	if (cusList->numOfData != 0)
	{
		if (!IsregistID(cusList, ID)) {

			puts("\t\t해당 ID는 사용중입니다.");
			printf("\t\t=============================\n");
			getchar();
			return;
		}
	}
	
	printf("\t\t이름 입력 : ");
	gets(name);

	printf("\t\t전화번호 입력 : ");
	gets(phoneNum);

	AddCusInfo(cusList, ID, name, phoneNum);

	puts("\t\t회원 가입이 되었습니다.");
	printf("\t\t=============================\n");
	getchar();
}

void SearchCusInfo(CusList *cusList)
{
	char ID[ID_LEN];
	cusInfo *cus;

	system("cls");

	printf("\t\t========= 회원 조회 =========\n");
	printf("\t\t찾을 ID 입력 : ");
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
	printf("\t\t존재하지 않는 ID 입니다.\n");
	printf("\t\t=============================\n");	
	getchar();
	
}

void RegistDVD(DVDList *dvdList)
{
	char ISBN[ISBN_LEN];
	char title[TITLE_LEN];
	int genre;

	system("cls");

	printf("\t\t================== DVD 등록 ================\n");

	printf("\t\tISBN 입력 : ");
	gets(ISBN);

	if (dvdList->numOfData != 0)
	{
		if (!IsRegistISBN(dvdList, ISBN)) {

			puts("\t\t해당 ISBN은 이미 등록되었습니다.");
			printf("\t\t============================================\n");
			getchar();
			return;
		}
	}

	printf("\t\t제목 입력 : ");
	gets(title);

	printf("\t\t장르 입력 (액션 : 1, 코믹 : 2, SF : 3, 로맨틱 : 4) : ");
	scanf("%d", &genre);
	getchar();

	AddDVDInfo(dvdList, ISBN, title, genre);

	puts("\t\t등록이 완료되었습니다.");
	printf("\t\t============================================\n");
	getchar();
}

void SearchDVDInfo(DVDList *dvdList)
{
	char ISBN[ISBN_LEN];
	dvdInfo *dvdPtr;

	system("cls");

	printf("\t\t================== DVD 조회 ================\n");


	printf("\t\t찾는 ISBN 입력 : ");
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
	puts("\t\t등록되지 않은 ISBN입니다.");
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

	printf("\t\t================== DVD 대여 ================\n");

	printf("\t\tID를 입력 : ");
	gets(ID);

	if (IsregistID(cusList, ID) != 0) {
		puts("\t\t입력된 ID로 가입된 고객이 없습니다.");
		printf("\t\t============================================\n");
		getchar();
		return;
	}
	cusPtr = cusList->cur->data;

	printf("\t\t대여할 ISBN 입력 : ");
	gets(ISBN);

	if (IsRegistISBN(dvdList, ISBN) != 0) {
		puts("\t\t등록되지 않은 DVD ISBN입니다.");
		printf("\t\t============================================\n");
		getchar();
		return;
	}
	dvdPtr = dvdList->cur->data;

	state = RentDVDState(dvdPtr);

	if (state) {
		puts("\t\t대여 중인 DVD이므로, 대여가 불가능합니다.");
		printf("\t\t============================================\n");
		getchar();
		return;
	}

	printf("\t\t대여일 입력(yyyymmdd) : ");
	scanf("%d", &day);
	getchar();

	AddRentListInfo(rentList, dvdPtr, cusPtr, day);

	puts("\t\t정상 대여 되었습니다.");
	printf("\t\t============================================\n");
	getchar();

}

void ReturnDVD(RentList *rentList, DVDList *dvdList) {
	char ISBN[ISBN_LEN];
	dvdInfo *dvdPtr;
	int state;

	system("cls");

	printf("\t\t================== DVD 반납 ================\n");


	printf("\t\t반납 할 ISBN 입력 : ");
	gets(ISBN);

	if (IsRegistISBN(dvdList, ISBN) != 0) {
		puts("\t\t등록되지 않은 DVD ISBN입니다.");
		printf("\t\t============================================\n");
		getchar();
		return;
	}
	dvdPtr = dvdList->cur->data;

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

void SearchRentDVDInfo(RentList *rentList, DVDList *dvdList) {
	char ISBN[ISBN_LEN];
	dvdInfo *dvdPtr;
	RentInfo *rentPtr;

	system("cls");

	printf("\t\t============= DVD 대여내역 조회 ============\n");

	printf("\t\t조회 할 ISBN 입력 : ");
	gets(ISBN);
	
	if (IsRegistISBN(dvdList, ISBN) != 0) {
		puts("\t\t등록되지 않은 DVD ISBN입니다.");
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

	printf("\t\t============ User 대여내역 조회 ============\n");

	printf("\t\tID 입력 : ");
	gets(ID);

	if (IsregistID(cusList, ID) != 0) {
		puts("\t\t입력된 ID로 가입된 고객이 없습니다.");
		printf("\t\t============================================\n");
		getchar();
		return;
	}
	cusPtr = cusList->cur->data;

	printf("\t\t대여 기간 입력(ex>> 20190315 20190320) : ");
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
		printf("CusList 파일 읽기 실패\n");
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
		printf("DVDList 파일 읽기 실패\n");
		return;
	}

	while (1) {
		loadNode = (dvdInfo *)malloc(sizeof(dvdInfo));

		// DVDList.txt
		// ISBN genre rentstate title 순으로 저장되어 있음
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
		printf("RentList 파일 읽기 실패\n");
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

	// 덮어 쓰기
	FILE *upload = fopen("CusList.txt", "w");
	cusInfo *uploadNode;

	if (upload == NULL) {
		printf("CusList 파일 생성 실패\n");
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
		printf("DVDList 파일 생성 실패\n");
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
		printf("RentList 파일 생성 실패\n");
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
