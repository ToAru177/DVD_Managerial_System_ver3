#include "common.h"
#include "screenOut.h"
#include "dvdInfo.h"
#include "dvdInfoAccess.h"


static int numOfDVD = 0;
static int numOfRentDVD = 0;

dvdInfo *MakeDVDNode(void) {
	dvdInfo *tmp = (dvdInfo *)malloc(sizeof(dvdInfo));
	tmp->next = NULL;

	return tmp;
}

dvdRentInfo *MakeRentNode(void) {
	dvdRentInfo *tmp = (dvdRentInfo *)malloc(sizeof(dvdRentInfo));
	tmp->next = NULL;

	return tmp;
}

void AddDVDInfo(dvdInfo **DVD_Head, char * ISBN, char * title, int genre)
{
	if ((*DVD_Head) == NULL) {

		*DVD_Head = MakeDVDNode();

		strcpy((*DVD_Head)->ISBN, ISBN);
		strcpy((*DVD_Head)->title, title);
		(*DVD_Head)->genre = genre;
		(*DVD_Head)->rentState = RETURNED;

		return;

	}

	else {
		AddDVDInfo(&(*DVD_Head)->next, ISBN, title, genre);
	}

}

dvdInfo * GetDVDPtrByISBN(dvdInfo *DVD_Head,char * ISBN)
{
	dvdInfo *temp = (dvdInfo *)malloc(sizeof(dvdInfo));

	temp = DVD_Head;

	while (temp != NULL) {
		if (strcmp(temp->ISBN, ISBN) == 0) {
			return temp;
		}

		temp = temp->next;
	}

	return (dvdInfo *)0;
}

int IsRegistISBN(dvdInfo *DVD_Head, char * ISBN)
{
	dvdInfo * pDVD = GetDVDPtrByISBN(DVD_Head, ISBN);

	if (pDVD == 0)
		return 0;
	else
		return 1;
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

void AddRentListInfo(dvdRentInfo **Rent_Head, dvdInfo *dvdPtr, cusInfo *cusPtr,int day) {

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

void SearchRentInfo(dvdRentInfo *Rent_Head, char *ISBN) {
	dvdRentInfo *temp = (dvdRentInfo *)malloc(sizeof(dvdRentInfo));

	temp = Rent_Head;

	while(temp != NULL) {
		if (strcmp(temp->ISBN_NUM, ISBN) == 0) {
			ShowRentInfo(temp);
		}
		temp = temp->next;
	}

}

void SearchRentUserInfoByDays(dvdRentInfo *Rent_Head, char *ID, int day1, int day2) {
	int day;

	for (day = day1; day <= day2; day++) {
		printf("\t\t================== %d ================\n", day);

		dvdRentInfo *temp = (dvdRentInfo *)malloc(sizeof(dvdRentInfo));

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
