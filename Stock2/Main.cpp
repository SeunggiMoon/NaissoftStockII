//
// Stock II
// (c) 2016~2018 Naissoft.
//

#include "GameFunctions.h"

int main(void)
{
	int menu, cnt, order;
	char c, pausemenu;

	system("title Stock II " VERSION);

	system("mode con: cols=120 lines=40");

	startLogo();

	printMainMenu();
	scanf("%d", &menu);

	InitStock();
	init();
	loan(20000);
	cnt = month = day = hour = order = 0;

	switch (menu)
	{
	case 1:
		ChangeStockPrice();
		save();

		for (int i = 0; i < MAX_COMPANY; i++)
		{
			if (rand() % 3 == 0) ifGood[i] = true;
			else ifGood[i] = false;
		}

		break;
	case 2:
		load();
		break;
	case 3:
		exit(0);
		break;
	default:
		break;
	}
	system("cls");

	drawNewspaper(companyOrder[order]);

	Money = 10000000000000;

	while (true)
	{	
		ShowMain();
		DrawGraph(companyOrder[order]);
		showCompanyReport(companyOrder[order]);
		
		if (Money <= 0)
		{
			printf("\n �Ļ�... ������ �帮�ڽ��ϴ�.");
			getchar();
			loan(30000);
			system("cls");
		}
		
		gotoxy(57, 10 + order - 1);
		printf("  ");
		gotoxy(57, 10 + order + 1);
		printf("  ");
		gotoxy(57, 10 + order);
		printf("��");

		c = '\0';
		getKey(&c);

		switch (c)
		{
		case 'b':
		case 'B':
			buyMenu(companyOrder[order]);
			break;
		case 'v':
		case 'V':
			showStockList();
			break;
		case 27:
			system("cls");
			titleLine("�Ͻ� ����");
			printf(" 1. ��  ��\n\n 2. ��  ��\n\n 3. ��  ��\n\n 4. ��  ��\n\n 5. ������\n\n Esc ���ư���");

			clearbuffer();
			pausemenu = getch();
			
			switch (pausemenu)
			{
			case '1':
				showStats();
				break;
			case '2':
				loanMenu();
				break;
			case '3':
				payback();
				break;
			case '4':
				settingMenu();
				break;
			case '5':
				system("cls");
				printf("\n �����Ͻðڽ��ϱ�? ������� ���� ������ ������ϴ�.\n Y / N");
				char ch;
				ch = getch();
				if (ch == 'Y' || ch == 'y') return 0;
				break;
			case 27:
				break;
			default:
				break;
			}
			system("cls");
			Sleep(100);
			break;
		case 's':
		case 'S':
			sellMenu();
			break;
		case 'E':
		case 'e':
			system("cls");
			save();
			printf("\n ������ ����Ǿ����ϴ�.");
			Sleep(300);
			break;
		case 'W':
		case 'w':
			if (timemode == 1)
			{
				while (cnt % 20 != 0) cnt++;
				cnt += 20;
				Sleep(100);
			}
			break;
		case 'I':
		case 'i':
			showCompanyInfo();
			break;
		case '2':
			if (order < MAX_COMPANY - 1) order++;
			drawNewspaper(companyOrder[order]);
			break;
		case '8':
			if (order > 0) order--;
			drawNewspaper(companyOrder[order]);
			break;
		default:
			break;
		}
		for (int i = 0; i < MAX_COMPANY; i++)
			PrevStockPrice[i] = StockPrice[i];

		if (cnt % 20 == 0)
		{
			ChangeStockPrice();
			UpdateGraphData();
			hour++;
		}

		if (cnt % 60 == 0) showTipNews();

		
		if ((cnt - 20) % 3360 == 0)
		{
			int comp = 100;
			while (!(goodEvent[comp] == false && badEvent[comp] == false))
				comp = rand() % MAX_COMPANY;

			for (int i = 0; i < MAX_COMPANY; i++)
				goodEvent[i] = badEvent[i] = false;

			if (ifGood[comp] == true) goodEvent[comp] = true;
			else badEvent[comp] = true;
		}
		

		if (hour == 0)
		{
			for (int i = 0; i < MAX_COMPANY; i++)
			{
				if (rand() % 3 == 0)
				{
					if (goodEvent[i] == false && badEvent[i] == false) ifGood[i] = true;
				}
				else if (goodEvent[i] == false && badEvent[i] == false) ifGood[i] = false;
			}
		}
		if (hour > 23)
		{
			gotoxy(2, 1);
			printf("�ڵ� ���� ��...");
			save();

			hour = 0;
			interest();
			day++;
			srand((int)time(NULL));
		}
		if (day > days[month] - 1)
		{
			day = 0;
			month++;
			Money -= TAX(Money);
		}
		if (month > 11) month = 0;

		if (timemode == 0)
		{
			clearbuffer();
			Sleep(DELAY);
			cnt++;
		}
		else if (timemode == 1)
		{
			clearbuffer();
			Sleep(DELAY);
		}
	}
	getchar();
	UnInitStock();
	return 0;
}
