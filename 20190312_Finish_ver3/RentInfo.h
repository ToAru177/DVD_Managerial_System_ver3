#ifndef _RENT_INFO_H_
#define _RENT_INFO_H_

#include "cusInfo.h"

#define ISBN_LEN 30
#define RENT_LEN 100

typedef struct RentInfo
{
	char ISBN_NUM[ISBN_LEN];
	char cusID[ID_LEN];
	char cusName[NAME_LEN];
	char cusPhoneNum[PHONE_LEN];
	unsigned int rentDay;

} RentInfo;

#endif // !_RENT_INFO_H_

