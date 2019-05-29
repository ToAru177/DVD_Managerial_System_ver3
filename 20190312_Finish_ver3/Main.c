#include "common.h"
#include "manager.h"
#include "screenOut.h"
#include "CusLinkedList.h"
#include "DVDLinkedList.h"
#include "RentLinkedList.h"

enum{CUS_MENU=1, DVD_MENU, DVDRENT_MENU, SEARCH_MENU, QUIT};

int main(void)
{
	// 메뉴 선택 변수
	int intputMenu = 0;
	
	// 각 list 생성
	CusList cusList;
	DVDList dvdList;
	RentList rentList;
	
	// list 초기화
	CusListInit(&cusList);
	DVDListInit(&dvdList);
	RentListInit(&rentList);

	// 파일에 저장된 데이터 load
	Txtload_CusList(&cusList);
	Txtload_DVDList(&dvdList);
	Txtload_RentList(&rentList);

	while (1)
	{
		ShowMenu();
		scanf("%d", &intputMenu);
		getchar();

		switch (intputMenu)
		{
		case CUS_MENU:
			ShowCusMenu(&cusList);
			break;

		case DVD_MENU:
			ShowDVDMenu(&dvdList);
			break;

		case DVDRENT_MENU:
			ShowDVDRentMenu(&rentList, &dvdList, &cusList);
			break;

		case SEARCH_MENU:
			ShowSearchMenu(&rentList, &dvdList, &cusList);
			break;

		}

		if (intputMenu == QUIT)
		{
			Txtupload_CusList(&cusList);
			Txtupload_DVDList(&dvdList);
			Txtupload_RentList(&rentList);
			puts("\t\t이용해주셔서 감사합니다.");
			break;
		}
	}
	return 0;
}