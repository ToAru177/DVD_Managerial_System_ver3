#ifndef __DVDINFO_H__
#define __DVDINFO_H__

#include "cusInfo.h"

#define ISBN_LEN 30
#define TITLE_LEN 30
#define RENT_LEN 100

// ���� �帣 ����
enum { ACTION = 1, COMIC, SF, ROMANTIC };
// �뿩 ���� ����
enum { RENTED, RETURNED };

typedef struct dvdRentInfo
{
	char ISBN_NUM[ISBN_LEN];
	char cusID[ID_LEN];
	char cusName[NAME_LEN];
	char cusPhoneNum[PHONE_LEN];
	unsigned int rentDay;

	struct dvdRentInfo *next;

} dvdRentInfo;

typedef struct dvdInfo
{
	char ISBN[ISBN_LEN];
	char title[TITLE_LEN];
	int genre;//���� �帣 ��� ����

	// �뿩���ɿ���(�뿩, �ݳ�)
	int rentState;
	// rentList�� ���� ��ġ����
	int numOfRentCus;
	
	struct dvdInfo *next;
} dvdInfo;


#endif // !__DVDINFO_H__