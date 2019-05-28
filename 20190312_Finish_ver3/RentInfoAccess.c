#include "common.h"
#include "RentInfoAccess.h"
#include "RentLinkedList.h"

RentInfo *MakeRentNode(void) {
	RentInfo *tmp = (RentInfo *)malloc(sizeof(RentInfo));
	tmp->next = NULL;

	return tmp;
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

void AddRentListInfo(RentInfo **Rent_Head, dvdInfo *dvdPtr, cusInfo *cusPtr,int day) {

	if ((*Rent_Head) == NULL) {
		*Rent_Head = MakeRentNode();

		strcpy((*Rent_Head)->ISBN_NUM, dvdPtr->ISBN);
		strcpy((*Rent_Head)->cusID, cusPtr->ID);
		strcpy((*Rent_Head)->cusName, cusPtr->name);
		strcpy((*Rent_Head)->cusPhoneNum, cusPtr->phoneNum);
		(*Rent_Head)->rentDay = day;

		return;
	}

	else {
		AddRentListInfo(&(*Rent_Head)->next, dvdPtr, cusPtr, day);
	}

}

void SearchRentInfo(RentInfo *Rent_Head, char *ISBN) {
	RentInfo *temp = (RentInfo *)malloc(sizeof(RentInfo));

	temp = Rent_Head;

	while(temp != NULL) {
		if (strcmp(temp->ISBN_NUM, ISBN) == 0) {
			ShowRentInfo(temp);
		}
		temp = temp->next;
	}

}

void SearchRentUserInfoByDays(RentInfo *Rent_Head, char *ID, int day1, int day2) {
	int day;

	for (day = day1; day <= day2; day++) {
		printf("\t\t================== %d ================\n", day);

		RentInfo *temp = (RentInfo *)malloc(sizeof(RentInfo));

		temp = Rent_Head;
		while(temp != NULL){
			if ((strcmp(temp->cusID, ID) == 0) && (temp->rentDay == day)) {
				ShowRentInfoUser(temp);
			}
			temp = temp->next;
		}
	}
	printf("\t\t============================================\n", day);
}
