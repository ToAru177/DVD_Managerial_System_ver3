#ifndef __MANAGER_H
#define __MANAGER_H

// ȸ�� ����
void RegisterCustomer(void);
void SearchCusInfo(void);

void Txtload_CusList();
void Txtupload_CusList();

// DVD ����
void RegistDVD(void);
void SearchDVDInfo(void);
void RentDVD(void);
void ReturnDVD(void);
void SearchRentDVDInfo(void);
void SearchRentUserInfo(void);

void Txtload_DVDList(void);
void Txtload_RentList(void);
void Txtupload_DVDList(void);
void Txtupload_RentList(void);

#endif // __MANAGER_H

