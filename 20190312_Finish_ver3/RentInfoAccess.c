#include "common.h"
#include "RentInfoAccess.h"
#include "RentLinkedList.h"

RentInfo *MakeRentNode(dvdInfo *dvdPtr, cusInfo *cusPtr, int day) {
	RentInfo *newRent = (RentInfo *)malloc(sizeof(RentInfo));
	strcpy(newRent->ISBN_NUM, dvdPtr->ISBN);
	strcpy(newRent->cusID, cusPtr->ID);
	strcpy(newRent->cusName, cusPtr->name);
	strcpy(newRent->cusPhoneNum, cusPtr->phoneNum);
	newRent->rentDay = day;

	return newRent;
}

int RentDVDState(dvdInfo *dvdPtr) {
	if (dvdPtr->rentState == RENTED) {
		return 1;
	}
	else {
		dvdPtr->rentState = RENTED;
		return 0;
	}
}

void AddRentListInfo(RentList *rentList, dvdInfo *dvdPtr, cusInfo *cusPtr,int day) {

	RentInfo *newRent = MakeRentNode(dvdPtr, cusPtr, day);
	RentLInsert(rentList, newRent);

}

int RentISBNCompare(RentInfo *prent, char *ISBN) {
	return strcmp(prent->ISBN_NUM, ISBN);
}

int RentIDCompare(RentInfo *prent, char *ID) {
	return strcmp(prent->cusID, ID);
}

void SearchRentInfo(RentList *rentList, char *ISBN) {

	RentInfo *rentPtr;

	if (RentLFirst(rentList, &rentPtr)) {
		if (!RentISBNCompare(rentPtr, ISBN)) {
			ShowRentInfo(rentPtr);

		}

		while (RentLNext(rentList, &rentPtr))
			if (!RentISBNCompare(rentPtr, ISBN)) {
				ShowRentInfo(rentPtr);
			}
	}
}

void SearchRentUserInfoByDays(RentList *rentList, char *ID, int day1, int day2) {
	int day;
	RentInfo *rentPtr;

	for (day = day1; day <= day2; day++) {
		printf("\t\t================== %d ================\n", day);

		if (RentLFirst(rentList, &rentPtr)) {
			if (!RentIDCompare(rentPtr, ID) && (rentPtr->rentDay == day)) {
				ShowRentInfoUser(rentPtr);
			}

			while (RentLNext(rentList, &rentPtr))
				if (!RentIDCompare(rentPtr, ID) && (rentPtr->rentDay == day)) {
					ShowRentInfoUser(rentPtr);
				}
		}
	}
	printf("\t\t============================================\n", day);
}
