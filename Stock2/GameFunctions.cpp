#include "GameFunctions.h"

int month, day, hour, achour;

int viewmode, timemode;

char *Tips[MAX_TIP] =
{
	"주가가 쌀 때 매수하고 비쌀 때 매도해서 이익을 내세요!",
	"전략을 세워 투자 왕이 되어보세요!",
	"1달마다 세금을 냅니다. 계속 기다리다간 파산할 수 있으니 조심하세요!",
	"여러 회사의 주식을 살 수 있습니다. 회사 목록을 확인하세요!",
};

char *GoodNews[MAX_NEWS] =
{
	"의 새 상품, 인기몰이 중",
	"의 발전을 이끈 새 CEO의 경영철학...",
	"의 성공적인 새 전략",
	", 환율 급등으로 주가 폭등",
	"에 외국인의 대규모 투자로 호재",
};

char *BadNews[MAX_NEWS] =
{
	"의 새 상품 대 실패... CEO 해임 위기",
	", 지금 추세로는 위험하다 - 전문가 분석",
	"의 위기... 시급한 대책 마련 필요",
	", 환율로 인한 심각한 피해",
	" 주식 팔자.. 외국인 대규모 매도에 주가 급락",
};

char *BadEventNews[MAX_NEWS] =
{
	" 압수수색 돌입",
	", 검사 자료 조작 밝혀져 충격",
	", 前 정부와 정경유착 의혹... 수사 돌입",
	" 노사 갈등 최악... 공장 가동 전면 중단",
	" CEO 구치소 구금",
};

char *Infos[MAX_COMPANY] =
{
	" Naissoft는 자칭 대한민국 최대 규모의 소프트웨어 개발 업체입니다.\n 유틸리티, 게임 등 여러 가지 프로그램들을 개발하고 있습니다.",
	" HawTech는 Naissoft와 양대산맥을 이루는 소프트웨어 업체입니다.",
	" 암겨농업은 산지에서 갓 생산된 싱싱한 작물을 전국에 유통하고 식품을 만드는 회사입니다.\n 특이한 이름이 회사 마케팅에 도움을 주지요.\n 최근은 경운기 등 농기구도 생산하고 있습니다.",
	" MK Electronics는 전자제품 생산 회사입니다.\n TV, PC, 스마트폰, 냉장고 등을 생산합니다.",
	" 폭펭군수는 군수 물자 생산 업체입니다.\n 이름답게 폭탄을 주로 생산하는 회사입니다.",
	" CJ 제일손연재는 패스트 푸드 업체입니다.\n 손연재란 먹을 손(飡), 잔치 연(宴), 집 재(齋) 로,\n 항상 먹는 잔치가 벌어지는 집이라는 의미입니다.",
	" KJS 시스템은 기업, 서버용 소프트웨어를 개발하는 회사입니다.\n 주로 가상 머신, 개발자 도구 등을 만듭니다.",
	" Fruit는 유명한 모바일 기기 회사입니다.\n 태블릿, 스마트폰, 스마트 워치 등을 생산하고 있습니다.\n Grand Theft Auto V™에 출연한 적이 있습니다.",
	" 수배자 모터스는 자동차를 개발/생산하는 업체입니다.\n 독자적인 엔진도 개발 중이며, 독일의 자동차 회사들과 경쟁 중입니다.",
	" 기야조선업은 기야그룹 산하의 중공업 회사로, 배를 만드는 회사입니다.",
};

char *goodHeadline[MAX_HEADLINE] =
{
	", 유례 없는 성장할 듯",
	"이(가) 나라 살린다",
	", 어디까지 성장하나",
	" 경영진들의 현명한 선택",
	" 주가 고공행진 중",
};

char *badHeadline[MAX_HEADLINE] =
{
	" 성장 둔화 전망",
	", 어쩌다 이렇게 됐나",
	" 주가 급락할 듯",
	" 상황, 더 나빠진다",
	", 이대로 가다간 파산",
};

char *goodArticle[MAX_ARTICLE] = 
{
	"이(가) 유례 없는 성장을\n\
계속하고 있다. 어제 본지와의 인터뷰에 \n\
서 김갑동 준승대 경영학과 명예교수는 \"\n\
아직 단정짓기는 어려우나 현재 성장세를\n\
계속 유지할 것\"이라고 답변했다. 김 교 \n\
수는 환율과 경기 회복 등의 여러 요인이\n\
현재의 성장에 작용했다고 주장하고 있다",
	
	"의 신제품이 큰 인기를\n\
끌고 있다. 얼마 전 출시한 이 제품은 회\n\
사 경영진들의 반대를 무릅쓰고 출시한  \n\
품이다. 개발 초반부터 잡음이 많았으나 \n\
현재는 자타공인 회사의 대표 모델로 자 \n\
리매김하는 중이다.",

	"이(가)\n더욱 성장할 전망이다.\n\
美 소비자단체 NSC의 조사 결과 다른 회 \n\
사들을 모두 제치고 만족도 지수 1위를  \n\
달성하였으며, 이에 따라 판매량도 꾸준 \n\
히 늘어나고 있다. 이런 추세라면 곧 국 \n\
내 시장도 장악할 수 있을 것으로 전망된\n\
다.",
};

char *badArticle[MAX_ARTICLE] =
{
	"이(가) 악재에 직면했다.\n\
신제품의 부진과 노사 간 갈등으로 인해 \n\
투자가 급격히 줄어들고 있는 중이다.\n\
현재로서는 잠시 지켜보자는 신중론이 우\n\
세하나 전망은 밝지 않은 것으로 보인다.\n\
이같은 상황이 지속될 경우 결국 구조조 \n\
정에 돌입할 것으로 예상돼 갈등이 증폭 \n\
되고 있다.",

	"이(가) 수출 부진으로 고\n\
초를 겪고 있다. 최근 미국의 관세 정책\n\
으로 특히 타격을 크게 입은 이 기업은 \n\
미국 시장 철수설까지 돌고 있는 중이다.\n\
어느 때보다도 임직원들의 혜안이 필요한 \n\
시점으로 보인다.",

	"의 상황이 점점 나빠지고\n\
있다. 최근의 부진에서 벗어나지 못한 모 \n\
습이다. 이대로라면 특단의 대책이 필요 \n\
해 보인다. 한 전문가는 본지와의 인터뷰 \n\
에서 \"회사의 구조에 손을 좀 대야 할 것 \n\
입니다.\"라고 대답하며 근본적 문제의 \n\
해결이 우선이라고 주장하였다.",
};

int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

void init()
{
	Money = DEF_MONEY;
	for (int i = 0; i < MAX_COMPANY; i++) StockPrice[i] = 9000;
	for (int i = 0; i < MAX_COMPANY; i++)
	{
		ifGood[i] = true;
		goodEvent[i] = false;
		badEvent[i] = false;
	}
	Stocks = StockDeal = 0;
	loanMoney = 0;
	ChangeStockPrice();
	hour++;
	viewmode = timemode = 0;
	setcursortype(NOCURSOR);
}

void ShowMain()
{
	gotoxy(0, 1);
	printf(" Stock II - Naissoft 주식 게임 2\n ");
	printf(VERSION);
	printf("\n\n B 사기, S 팔기, V 목록, E 저장, I 회사 정보, 8 / 2 회사 선택, Esc 메뉴");
	if (timemode == 1) printf("\n W 기다리기");
	gotoxy(0, 5);
	printf("\n 현재 내 돈 : %lld원, 갚아야 할 돈 : %d원, 보유 주식 %d주\n\n\n\n", Money, loanMoney, Stocks);

	ShowStockPrice(viewmode);

	printf("\n %d월 %d일 %d시   ", month + 1, day + 1, hour);
	printf("\n\n 이번 달 납부할 세금은 %lld원입니다. %d일 남았습니다.\n", TAX(Money), days[month] - day);
}

void load()
{
	int stocks = 0;
	Stock tmp;

	FILE *save = fopen("save.ns3", "rb");
	if (save == NULL)
	{
		init();
		return;
	}

	fscanf(save, "%d ", &stocks);
	stocks = _rotr(stocks, 1);

	for (int i = 0; i < stocks; i++)
	{
		now = head;

		fscanf(save, "%d %d ", &tmp.company, &tmp.price);
		tmp.company = _rotr(tmp.company, 1); tmp.price = _rotr(tmp.price, 1);
		InsertStock(now, &tmp);
	}

	for (int i = 0; i < MAX_COMPANY; i++)
	{
		fscanf(save, "%d ", &StockPrice[i]);
		StockPrice[i] = _rotr(StockPrice[i], 1);
	}

	for (int i = 0; i < MAX_COMPANY; i++)
	{
		fscanf(save, "%d ", &ifGood[i]);
		ifGood[i] = _rotr(ifGood[i], 1);
	}

	for (int i = 0; i < MAX_COMPANY; i++)
	{
		fscanf(save, "%d ", &goodEvent[i]);
		goodEvent[i] = _rotr(goodEvent[i], 1);
	}

	for (int i = 0; i < MAX_COMPANY; i++)
	{
		fscanf(save, "%d ", &badEvent[i]);
		badEvent[i] = _rotr(badEvent[i], 1);
	}

	fscanf(save, "%lld %d %d %d %d %d %d %d %d", &Money, &loanMoney, &Stocks, &StockDeal, &month, &day, &hour, &viewmode, &timemode);
	Money = _rotr64(Money, 1); loanMoney = _rotr(loanMoney, 1); Stocks = _rotr(Stocks, 1);
	StockDeal = _rotr(StockDeal, 1); month = _rotr(month, 1); day = _rotr(day, 1); hour = _rotr(hour, 1);

	fclose(save);
}

void save()
{
	int stocks = 0;
	FILE *save = fopen("save.ns3", "wb");

	for (now = head->next; now; now = now->next) stocks++;
	fprintf(save, "%d ", _rotl(stocks, 1));

	for (now = head->next; now; now = now->next)
		fprintf(save, "%d %d ", _rotl(now->company, 1), _rotl(now->price, 1));

	for (int i = 0; i < MAX_COMPANY; i++)
		fprintf(save, "%d ", _rotl(StockPrice[i], 1));

	for (int i = 0; i < MAX_COMPANY; i++)
		fprintf(save, "%d ", _rotl(ifGood[i], 1));

	for (int i = 0; i < MAX_COMPANY; i++)
		fprintf(save, "%d ", _rotl(goodEvent[i], 1));

	for (int i = 0; i < MAX_COMPANY; i++)
		fprintf(save, "%d ", _rotl(badEvent[i], 1));

	fprintf(save, "%lld %d %d %d %d %d %d %d %d", _rotl64(Money, 1), _rotl(loanMoney, 1), _rotl(Stocks, 1), _rotl(StockDeal, 1),
		_rotl(month, 1), _rotl(day, 1), _rotl(hour, 1), viewmode, timemode);

	fclose(save);
}

void showTipNews()
{
	gotoxy(0, 8);
	for (int i = 0; i < 80; i++) printf(" ");
	gotoxy(0, 8);
	if (rand() % 4 == 0)
		printf(" 팁 : %s", Tips[rand() % MAX_TIP]);
	else
	{
		int comp = rand() % MAX_COMPANY;
		if (ifGood[comp] == true) printf(" NEWS : %s%s", CompanyName[comp], GoodNews[rand() % MAX_NEWS]);
		else if (badEvent[comp] == false) printf(" NEWS : %s%s", CompanyName[comp], BadNews[rand() % MAX_NEWS]);
		else printf(" 속보 : %s%s", CompanyName[comp], BadEventNews[rand() % MAX_NEWS]);
	}
}

void buyMenu(int order)
{
	int amount;

	system("cls");
	titleLine("주식 사기");

	printf(" 현재 %s 회사의 주가는 %d원입니다.\n\n 몇 개를 구입하시겠습니까? (취소 : 0)", CompanyName[order], StockPrice[order]);

	scanf("%d", &amount);
	if (amount > 0)
	{
		buyStock(order, amount);
		printf("\n\n 구입하였습니다.");
		Sleep(2000);
	}
	system("cls");
	return;
}

void sellMenu()
{
	char ch = '\0';
	int idx, j, k;
	k = idx = 1;
	system("cls");
	while (true)
	{	
		titleLine("주식 팔기");
		printf("\n [ W / S로 팔 주식을 고르세요. A / D로 더 볼 수 있습니다. B를 누르면 팝니다. ]\n\n 현재 보유 주식 %d주\n", Stocks);
		j = 1;
		for (now = head->next; now; now = now->next)
		{
			if (j >= k && j < k + 10) printf("\n %d. 회사 : %-20s, 가격 : %d원", j, CompanyName[now->company], now->price);
			j++;
		}
		printf("\n\n 돌아가려면 Q를 누르세요.\n");
		
		Stock *f = FindStock(idx - 1);
		if (f == NULL) {
			system("cls");
			return;
		}	
	
		printf("\n [ 선택 주식 정보 ]\n\n 번호 : %d\n 회사 : %s\n 가격 : %d원\n 현재 가격 : %d원\n 매도 이익 : %d원\n", idx, CompanyName[f->company], f->price, StockPrice[f->company], StockPrice[f->company] - f->price);
		
		ch = getch();
		
		switch (ch)
		{
			case 'A':
			case 'a':
				if (k > 10) k -= 10;
				break;
			case 'D':
			case 'd':
				k += 10;
				break;
			case 'W':
			case 'w':
				if (idx > 1) idx--;
				break;
			case 'S':
			case 's':
				if (idx < j) idx++;
				break;
			case 'Q':
			case 'q':
				system("cls");
				return;
				break;
			case 'B':
			case 'b':
				sellStock(idx);
				break;
		}
		
		ch = '\0';
		system("cls");
	}
}

void showStats()
{
	system("cls");
	titleLine("통  계");
	printf("\n 주식을 사거나 판 횟수 : %d\n 현재 가진 돈 : %d원\n 주식 개수 : %d\n\n 돌아가려면 Enter를 누르세요.\n", StockDeal, Money, Stocks);
	getchar();
	system("cls");
}

void getKey(char *c)
{
	if (!timemode)
	{
		if (kbhit()) *c = getch();
	}
	else *c = getch();
}

void settingMenu()
{
	char select;
	system("cls");
	titleLine("설  정");
	printf(" 1. 보기 모드 전환\n 2. 시간 흐름 방식 전환\n Esc 돌아가기");
	
	select = getch();

	switch (select)
	{
	case '1':
		viewmode++;
		if (viewmode > 2) viewmode = 0;
		switch (viewmode)
		{
		case 0:
			printf("\n 보기 방식이 기본 모드로 전환되었습니다.");
			break;
		case 1:
			printf("\n 보기 방식이 내림차순 모드로 전환되었습니다.");
			break;
		case 2:
			printf("\n 보기 방식이 오름차순 모드로 전환되었습니다.");
			break;
		}
		break;
	case '2':
		timemode++;
		if (timemode > 1) timemode = 0;
		switch (timemode)
		{
		case 0:
			printf("\n 시간 흐름이 자동으로 전환되었습니다.");
			break;
		case 1:
			printf("\n 시간 흐름이 수동으로 전환되었습니다.");
			break;
		}
		break;
	case 27:
		break;
	default:
		break;
	}
	Sleep(300);
	system("cls");
	return;
}

void loanMenu()
{
	unsigned int loanmoney;

	system("cls");
	titleLine("대  출");
	printf("\n 얼마를 대출받으시겠습니까? (한도 10억)");
	scanf("%d", &loanmoney);
	if (loanmoney <= 1000000000) loan(loanmoney);

	return;
}

void showCompanyInfo()
{
	int i = 0;
	char ch = '\0';

	system("cls");
	while (ch != 27)
	{
		system("cls");
		titleLine("회사 정보");

		gotoxy(0, 5);
		printf(" %d / %d. W, S 키로 넘겨 볼 수 있습니다. Esc로 나가기\n 회사 : %s\n\n", i + 1, MAX_COMPANY, CompanyName[i]);
		printf("%s", Infos[i]);

		ch = getch();

		switch (ch)
		{
		case 'W':
		case 'w':
			if (i < MAX_COMPANY - 1) i++;
			break;
		case 'S':
		case 's':
			if (i > 0) i--;
			break;
		}
	}
	system("cls");
}

void DrawGraph(int company)
{

	gotoxy(0, 25);
	printf(" 24000                                                                     \n 22000                                                                     \n 20000                                                                     "
		"\n 18000                                                                     \n 16000                                                                     \n 14000                                                                     "
		"\n 12000                                                                     \n 10000                                                                     \n  8000                                                                     "
		"\n  6000                                                                     \n  4000                                                                     \n  2000                                                                     \n                                                                              ");
	gotoxy(7, 46);

	int j = 0;
	for (int i = 47; i >= 0; i--)
	{
		if (GraphData[company][i] > 0 && GraphData[company][i] < 26000)
		{
			gotoxy(7 + j, 36 - ((int)((GraphData[company][i] % 26000) / 2000) - 1));
			if (GraphData[company][i] < 2000) printf("v");
			else printf("*");
			j++;
		}
		else if (GraphData[company][i] >= 26000)
		{
			gotoxy(7 + j, 36 - ((int)(((GraphData[company][i] - 2000) % 24000) / 2000)));
			if ((GraphData[company][i] - 2000) / 24000 + 1 > 9) printf("+");
			else printf("%d", (GraphData[company][i] - 2000) / 24000 + 1);
			j++;
		}
	}
}

void showCompanyReport(int company)
{
	for (int i = 2; i < 7; i++)
	{
		gotoxy(75, i);
		printf("                     ");
	}
	gotoxy(75, 2);
	printf("회사 : %s", CompanyName[company]);
	gotoxy(75, 4);
	printf("현재 주가 : %d원", StockPrice[company]);
	gotoxy(75, 6);
	printf("전문가 의견 : %s", ifGood[company] ? "긍정적" : "부정적");
}

void drawNewspaper(int comp)
{
	textcolor(112);
	
	for (int i = 0; i < 25; i++)
	{
		gotoxy(75, 10 + i);
		for (int j = 0; j < 40; j++) putch(' ');
	}
	
	gotoxy(88, 12);
	printf("羅  所  日  報    %d월 %d일", month + 1, day + 1);
	gotoxy(76, 13);
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
	
	textcolor(15);
	gotoxy(76, 14);
	
	if (ifGood[comp] == true) printf(" %s%s ", CompanyName[comp], goodHeadline[rand() % MAX_HEADLINE]);
	else printf(" %s%s ", CompanyName[comp], badHeadline[rand() % MAX_HEADLINE]);
	
	textcolor(112);
	gotoxy(76, 16);
	if (ifGood[comp] == true)
	{
		int i = 0;
		int articleNo = rand() % MAX_ARTICLE;
		int cnt = 0;
		printf(" %s", CompanyName[comp]);
		while (goodArticle[articleNo][i] != '\0')
		{
			if (goodArticle[articleNo][i] == '\n')
			{
				cnt++;
				gotoxy(76, 16 + cnt);
			}
			else putchar(goodArticle[articleNo][i]);
			i++;
		}
	}
	else
	{
		int i = 0;
		int articleNo = rand() % MAX_ARTICLE;
		int cnt = 0;
		printf(" %s", CompanyName[comp]);
		while (badArticle[articleNo][i] != '\0')
		{
			if (badArticle[articleNo][i] == '\n')
			{
				cnt++;
				gotoxy(76, 16 + cnt);
			}
			else putchar(badArticle[articleNo][i]);
			i++;
		}
	}
	
	textcolor(7);
}
