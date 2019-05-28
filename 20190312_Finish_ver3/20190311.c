#include "common.h"
#include "manager.h"
#include "screenOut.h"

enum{CUS_MENU=1, DVD_MENU, DVDRENT_MENU, SEARCH_MENU, QUIT};

int main(void)
{
	int intputMenu = 0;

	Txtload_CusList();
	Txtload_DVDList();
	Txtload_RentList();

	while (1)
	{
		ShowMenu();
		scanf("%d", &intputMenu);
		getchar();

		switch (intputMenu)
		{
		case CUS_MENU:
			ShowCusMenu();
			break;

		case DVD_MENU:
			ShowDVDMenu();
			break;

		case DVDRENT_MENU:
			ShowDVDRentMenu();
			break;

		case SEARCH_MENU:
			ShowSearchMenu();
			break;

		}

		if (intputMenu == QUIT)
		{
			Txtupload_CusList();
			Txtupload_DVDList();
			Txtupload_RentList();
			puts("\t\t이용해주셔서 감사합니다.");
			break;
		}


	}
	return 0;
}