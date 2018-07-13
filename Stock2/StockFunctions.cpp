#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include <Windows.h>

#include "StockFunctions.h"
#include "Stock.h"

unsigned long Money;
int StockPrice[MAX_COMPANY], PrevStockPrice[MAX_COMPANY], Stocks, StockDeal, loanMoney, companyOrder[MAX_COMPANY];
int GraphData[MAX_COMPANY][48] = { 0 };
bool ifGood[MAX_COMPANY];

char *CompanyName[MAX_COMPANY] =
{
	"Naissoft",
	"HawTech",
	"암겨농업",
	"MK Electronics",
	"폭펭군수",
	"CJ 제일손연재",
	"KJS 시스템",
	"Fruit",
	"수배자 모터스",
	"기야조선",
};

void ChangeStockPrice()
{
	srand((int)time(NULL));

	for (int i = 0; i < MAX_COMPANY; i++)
	{
		if (ifGood[i] == true)
		{
			if ((rand() % 2) == 0)
			{
				StockPrice[i] += (rand() % 1000);
			}
			else
			{
				StockPrice[i] -= (rand() % 100);
			}
		}
		else
		{
			if ((rand() % 2) == 0)
			{
				StockPrice[i] += (rand() % 500);
			}
			else
			{
				StockPrice[i] -= (rand() % 1000);
			}
		}
		if (StockPrice[i] < 2000) StockPrice[i] = 2000;
		StockPrice[i] = StockPrice[i] / 10 * 10;
	}
}

void ShowStockPrice(int mode)
{
	if (mode == 0)
	{
		for (int i = 0; i < MAX_COMPANY; i++)
		{
			PrintStockPrice(i);
			companyOrder[i] = i;
		}
		return;
	}

	int order[MAX_COMPANY], tmp;
	for (int i = 0; i < MAX_COMPANY; i++) order[i] = StockPrice[i];

	if (mode == 1)
	{
		for (int i = 0; i < MAX_COMPANY; i++)
		{
			for (int j = 0; j < MAX_COMPANY; j++)
			{
				if (order[i] > order[j])
				{
					tmp = order[i];
					order[i] = order[j];
					order[j] = tmp;
				}
			}
		}
		for (int i = 0; i < MAX_COMPANY; i++)
		{
			for (int j = 0; j < MAX_COMPANY; j++)
			{
				if (order[i] == StockPrice[j])
				{
					PrintStockPrice(j);
					order[i] = 0;
					companyOrder[i] = j;
				}
			}
		}
	}
	if (mode == 2)
	{
		for (int i = 0; i < MAX_COMPANY; i++)
		{
			for (int j = 0; j < MAX_COMPANY; j++)
			{
				if (order[i] < order[j])
				{
					tmp = order[i];
					order[i] = order[j];
					order[j] = tmp;
				}
			}
		}
		for (int i = 0; i < MAX_COMPANY; i++)
		{
			for (int j = 0; j < MAX_COMPANY; j++)
			{
				if (order[i] == StockPrice[j])
				{
					PrintStockPrice(j);
					order[i] = 0;
					companyOrder[i] = j;
				}
			}
		}
	}
}

void PrintStockPrice(int i)
{
	printf(" 회사 : ");
	if (ifGood[i])
	{
		textcolor(10);
		printf("%-20s", CompanyName[i]);
		textcolor(7);
	}
	else 
	{
		textcolor(12);
		printf("%-20s", CompanyName[i]);
		textcolor(7);
	}
	printf(" │ 가격 : %5d원  ", StockPrice[i]);
	if (PrevStockPrice[i] < StockPrice[i])
	{
		textcolor(2);
		printf("▲%4d원 ", StockPrice[i] - PrevStockPrice[i]);
		textcolor(7);
	}
	else if (PrevStockPrice[i] > StockPrice[i])
	{
		textcolor(14);
		printf("▼%4d원 ", -1 * (StockPrice[i] - PrevStockPrice[i]));
		textcolor(7);
	}
	printf("\n");
}

void loan(int lmoney)
{
	loanMoney += lmoney;
	Money += lmoney;
}

void interest()
{
	loanMoney += (loanMoney * 0.1);
}

void payback()
{
	Money -= loanMoney;
	loanMoney = 0;
}

void buyStock(int order, int amount)
{
	for (int i = 0; i < amount; i++)
	{
		if (StockPrice[order] <= Money)
		{
			system("cls");
			now = head;

			tmp.company = order;
			tmp.price = StockPrice[order];
			now = InsertStock(now, &tmp);

			Stocks++;
			StockDeal++;
			printf(" %d원을 주고 번째 주식을 구입하였습니다. 주식이 %d개입니다.\n", StockPrice[order], Stocks);
			Money -= StockPrice[order];
			printf(" 남은 돈은 %d원입니다.\n", Money);
		}
		else
		{
			printf(" 돈이 부족합니다. 주식을 살 수 없습니다.\n");
		}
	}
}

void sellStock(int i)
{
	Stock *f = FindStock(i - 1);
	if (f == NULL) return;
	
	Money += (StockPrice[f->company]);
	DeleteStock(f);
	Stocks--;	
}

void showStockList()
{
	system("cls");
	int j, k = 1;
	char i;

	if (Stocks <= 0)
		printf("\n 주식이 없습니다.\n");
	else
	{
		do
		{
			system("cls");
			titleLine("주식 목록 보기");
			printf("\n [ A, D로 더 보실 수 있습니다. ]\n\n");
			j = 1;
			for (now = head->next; now; now = now->next)
			{
				if (j >= k && j < k + 10) printf("\n %d. 회사 : %-20s, 가격 : %d원", j, CompanyName[now->company], now->price);
				j++;
			}
			printf("\n 돌아가려면 Q를 누르세요.\n");
			scanf(" %c", &i);
			if (i == 'D' || i == 'd') k += 10;
			else if (i == 'A' || i == 'a')
			{
				if (k > 10) k -= 10;
			}
		} while (i != 'Q');
	}
	system("cls");
}

void UpdateGraphData()
{
	for (int i = 0; i < MAX_COMPANY; i++)
	{
		for (int j = 46; j >= 0; j--)
		{
			GraphData[i][j + 1] = GraphData[i][j];
		}
		GraphData[i][0] = StockPrice[i];
	}
}
