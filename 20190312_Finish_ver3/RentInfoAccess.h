#ifndef _RENTACCESS_H_
#define _RENTACCESS_H_

#include "RentInfo.h"
#include "dvdInfo.h"
#include "RentLinkedList.h"

int RentDVDState(dvdInfo *dvdPtr);

void AddRentListInfo(RentInfo **Rent_Head, dvdInfo *dvdPtr, cusInfo *cusPtr, int day);

void SearchRentInfo(RentInfo *Rent_Head, char *ISBN);

void SearchRentUserInfoByDays(RentInfo *Rent_Head, char *ID, int day1, int day2);

RentInfo *MakeRentNode(void);

#endif // !_RENTACCESS_H_

