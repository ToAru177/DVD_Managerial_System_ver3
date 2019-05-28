#ifndef __DVDINFO_H__
#define __DVDINFO_H__

#define ISBN_LEN 30
#define TITLE_LEN 30

// ���� �帣 ����
enum { ACTION = 1, COMIC, SF, ROMANTIC };
// �뿩 ���� ����
enum { RENTED, RETURNED };

typedef struct dvdInfo
{
	char ISBN[ISBN_LEN];
	char title[TITLE_LEN];
	int genre;//���� �帣 ��� ����

	// �뿩���ɿ���(�뿩, �ݳ�)
	int rentState;
	// rentList�� ���� ��ġ����
	int numOfRentCus;
	
	//struct dvdInfo *next;
} dvdInfo;


#endif // !__DVDINFO_H__