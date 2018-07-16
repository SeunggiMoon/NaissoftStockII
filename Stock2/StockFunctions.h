#include "Arts.h"

#define DEF_STOCK 9000
#define DEF_MONEY 10000
#define MAX_COMPANY 10

extern int companyOrder[MAX_COMPANY];
extern int GraphData[MAX_COMPANY][48];

void ChangeStockPrice();

void ShowStockPrice(int);

void PrintStockPrice(int);

void loan(unsigned int);

void interest();

void payback();

void buyStock(int, int);

void sellStock(int);

void showStockList();

void UpdateGraphData();