#include "Stock.h"
#include "StockFunctions.h"

#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include <Windows.h>

#define VERSION "��1.5.0716"

#define DELAY 50

#define MAX_TIP 4
#define MAX_NEWS 5
#define MAX_HEADLINE 5
#define MAX_ARTICLE 3

#define TAX(money) (30000 + ((money) / 4))

extern FILE input, output;
extern int month, day, hour, achour;
extern char *Tips[MAX_TIP], *GoodNews[MAX_NEWS], *BadNews[MAX_NEWS], *BadEventNews[MAX_NEWS];
extern int days[12];

extern unsigned int StockPrice[MAX_COMPANY], PrevStockPrice[MAX_COMPANY], Stocks, StockDeal, loanMoney;
extern unsigned long long Money;
extern bool ifGood[MAX_COMPANY];
extern bool goodEvent[MAX_COMPANY];
extern bool badEvent[MAX_COMPANY];
extern char *CompanyName[MAX_COMPANY];
extern Stock *head, *now, tmp;

extern int viewmode, timemode;

void init();

void ShowMain();

void load();

void save();

void showTipNews();

void buyMenu(int);

void sellMenu();

void showStats();

void getKey(char *);

void settingMenu();

void loanMenu();

void showCompanyInfo();

void DrawGraph(int);

void showCompanyReport(int);

void drawNewspaper(int);
