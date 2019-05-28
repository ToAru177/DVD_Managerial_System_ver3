#ifndef __MANAGER_H
#define __MANAGER_H

#include "CusLinkedList.h"
#include "DVDLinkedList.h"

// 雀盔 包府
void RegisterCustomer(CusList *cusList);
void SearchCusInfo(CusList *cusList);
//
//void Txtload_CusList();
//void Txtupload_CusList();
//
//// DVD 包府
void RegistDVD(DVDList *dvdList);
void SearchDVDInfo(DVDList *dvdList);
//void RentDVD(void);
//void ReturnDVD(void);
//void SearchRentDVDInfo(void);
//void SearchRentUserInfo(void);
//
//void Txtload_DVDList(void);
//void Txtload_RentList(void);
//void Txtupload_DVDList(void);
//void Txtupload_RentList(void);
//
#endif // __MANAGER_H

