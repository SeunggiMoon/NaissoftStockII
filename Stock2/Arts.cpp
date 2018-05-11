#include "Arts.h"

#include <stdio.h>
#include <conio.h>
#include <Windows.h>

void startLogo()
{
	setcursortype(NOCURSOR);
	textcolor(7);
	Sleep(300);
	textcolor(8);
	gotoxy(1, 2), printf("유의 사항 및 저작권 안내");
	Sleep(75);
	textcolor(7);
	gotoxy(1, 2), printf("유의 사항 및 저작권 안내");
	Sleep(75);
	textcolor(15);
	gotoxy(1, 2), printf("유의 사항 및 저작권 안내");
	Sleep(300);
	gotoxy(1, 6);
	printf(" 이 게임은 실제 주식 투자와 많은 차이가 있습니다. 실제로 주식 투자를 할 때에는 항상 신중하십시오.\n  게임 내의 회사는 실존 회사를 묘사하지 않으며, 그 내용은 모두 허구입니다.\n ");
	printf(" 소스 코드를 상업적으로 이용하는 것은 금지되어 있습니다.\n  피드백 및 문의는 moon44432.blog.me에서 하실 수 있습니다.\n  Stock!과 Stock II의 저작권은 Naissoft가 보유하고 있습니다.\n\n\n ⓒ 2013~2018 Naissoft. All rights reserved.\n\n 시작하려면 아무 키나 누르십시오.");
	getch();
	textcolor(7);
	gotoxy(1, 2), printf("유의 사항 및 저작권 안내");
	Sleep(75);
	textcolor(8);
	gotoxy(1, 2), printf("유의 사항 및 저작권 안내");
	Sleep(75);
	system("cls");
	textcolor(7);
	Sleep(300);

	setcursortype(NORMALCURSOR);
}

void printMainMenu()
{
	printf("\n\n\t\t\t\t\t        Stock II - 주식 게임 2");
	printf("\n\n\n\t\t\t\t\t    항목을 선택해 주시기 바랍니다.");
	printf("\n\n\t\t\t\t\t        「  새로운 게임  : 1」");
	printf("\n\n\t\t\t\t\t        「  불 러 오 기  : 2」");
	printf("\n\n\t\t\t\t\t        「  종       료  : 3」");
}
