#ifndef __MANAGER_H
#define __MANAGER_H

#include "CusLinkedList.h"
#include "DVDLinkedList.h"
#include "RentLinkedList.h"

/*
	��� : ȸ�� ����
	��ȯ : void
*/
void RegisterCustomer(CusList *cusList);

/*
	��� : ȸ�� ��ȸ
	��ȯ : void
*/
void SearchCusInfo(CusList *cusList);


/*
	��� : DVD ���
	��ȯ : void
*/
void RegistDVD(DVDList *dvdList);

/*
	��� : DVD ��ȸ
	��ȯ : void
*/
void SearchDVDInfo(DVDList *dvdList);

/*
	��� : DVD �뿩
	��ȯ : void
*/
void RentDVD(RentList *rentList, DVDList *dvdList, CusList *cusList);

/*
	��� : DVD �ݳ�
	��ȯ : void
*/
void ReturnDVD(RentList *rentList, DVDList *dvdList);

/*
	��� : Ư�� DVD�� ���� ȸ������ ���� ��ȸ
	��ȯ : void
*/
void SearchRentDVDInfo(RentList *rentList, DVDList *dvdList);

/*
	��� : Ư�� �Ⱓ ���� ȸ���� �뿩�� DVD�� ISBN ��ȸ
	��ȯ : void
*/
void SearchRentUserInfo(RentList *rentList, CusList *cusList);

/*
	��� : ����(.txt)�� �Է� �޾� ȸ�� ����Ʈ ���� ����
	��ȯ : void
*/
void Txtload_CusList(CusList *cusList);

/*
	��� : ����(.txt)�� �Է� �޾� DVD ����Ʈ ���� ����
	��ȯ : void
*/
void Txtload_DVDList(DVDList *dvdList);

/*
	��� : ����(.txt)�� �Է� �޾� �뿩 ����Ʈ ���� ����
	��ȯ : void
*/
void Txtload_RentList(RentList *rentList);

/*
	��� : ȸ�� ����Ʈ ������ ����(.txt)�� ���
	��ȯ : void
*/
void Txtupload_CusList(CusList *cusList);

/*
	��� : DVD ����Ʈ ������ ����(.txt)�� ���
	��ȯ : void
*/
void Txtupload_DVDList(DVDList *dvdList	);

/*
	��� : �뿩 ����Ʈ ������ ����(.txt)�� ���
	��ȯ : void
*/
void Txtupload_RentList(RentList *rentList);

#endif // __MANAGER_H

