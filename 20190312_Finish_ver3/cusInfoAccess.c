#include "common.h"
#include "cusInfo.h"
#include "CusLinkedList.h"

#define MAX_CUSTOMER 100

cusInfo *MakeCusNode(char *ID, char *name, char *phone) {
	cusInfo *newCus = (cusInfo *)malloc(sizeof(cusInfo));
	strcpy(newCus->ID, ID);
	strcpy(newCus->name, name);
	strcpy(newCus->phoneNum, phone);

	return newCus;
}

void AddCusInfo(CusList *cusList,char * ID, char * name, char * phone)
{
	cusInfo *newCus = MakeCusNode(ID, name, phone);
	CusLInsert(cusList, newCus);	
}

int IsregistID(CusList *Head,char * ID)
{
	cusInfo *cus;

	if (CusLFirst(Head, &cus)) {
		if (!IDCompare(cus, ID))
			return FALSE;

		while(CusLNext(Head, &cus))
			if (!IDCompare(cus, ID))
				return FALSE;
	}
	return TRUE;
}

int IDCompare(cusInfo *pcus, char *ID) {
	return strcmp(pcus->ID, ID);
}