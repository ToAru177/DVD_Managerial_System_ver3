#include "common.h"
#include "screenOut.h"
#include "dvdInfo.h"
#include "dvdInfoAccess.h"
#include "DVDLinkedList.h"

dvdInfo *MakeDVDNode(char * ISBN, char * title, int genre) {
	dvdInfo *newDVD = (dvdInfo *)malloc(sizeof(dvdInfo));
	strcpy(newDVD->ISBN, ISBN);
	strcpy(newDVD->title, title);
	newDVD->genre = genre;
	newDVD->rentState = RETURNED;

	return newDVD;
}

void AddDVDInfo(DVDList *dvdList, char * ISBN, char * title, int genre)
{
	dvdInfo *newDVD = MakeDVDNode(ISBN, title, genre);
	DVDLInsert(dvdList, newDVD);
}

int IsRegistISBN(DVDList *dvdList, char * ISBN)
{
	dvdInfo *pDVD;

	if (DVDLFirst(dvdList, &pDVD)) {
		if(!ISBNCompare(pDVD, ISBN))
			return FALSE;

		while(DVDLNext(dvdList, &pDVD))
			if (!ISBNCompare(pDVD, ISBN))
				return FALSE;
	}
	
	return TRUE;
}

int ISBNCompare(dvdInfo *pdvd, char *ISBN) {
	return strcmp(pdvd->ISBN, ISBN);
}


