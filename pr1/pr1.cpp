﻿#include <iostream>
#include <windows.h>
#include <string>
#include <vector>

using namespace std;

struct Date {
	unsigned short day;
	unsigned short month;
	unsigned short year;
};

struct Record
{
	char name[17];
	char type;
	double price;
	unsigned short minCount;
	struct Date date;
};

void myCentr(string s, int wLine) {

	int w = s.length();
	int delta = (wLine - w) / 2;
	cout << left;
	cout.width(delta); cout << " ";
	cout << s;
	cout.width(delta + 1); cout << " ";

}

void printDate(unsigned short day, unsigned short month, unsigned short year, int wLine) {
	int w = 10;
	int delta = (wLine - w) / 2 - 1;
	cout << left;
	cout.width(delta); cout << " ";
	if (day > 9) {
		cout << day;
	}
	else {
		cout << "0" << day;
	}
	cout << ".";
	if (month > 9) {
		cout << month;
	}
	else {
		cout << "0" << month;
	}
	cout << ".";
	cout << year;
	cout.width(delta); cout << " ";
}

void printWithZero4(int num, int width) {

	if (num < 10) {
		cout << "000" << num;
	}
	if (num > 9 and num < 100) {
		cout.width(width + 1);
		cout << "00" << num;
	}
	if (num > 99 and num < 1000) {
		cout.width(width);
		cout << "0" << num;
	}
	if (num > 999 and num < 10000) {
		cout << num;
	}

}

void printWithSpace4(double num, int width, int spaceCount) {

	if (num < 10) {
		cout.precision(5);
		cout.width(spaceCount + 3); cout.fill(' ');
		cout << " " << left << fixed << num;
	}
	if (num > 9 and num < 100) {
		cout.precision(5);
		cout.width(spaceCount + 2); cout.fill(' ');
		cout << " " << left << fixed << num;
	}
	if (num > 99 and num < 1000) {
		cout.precision(5);
		cout.width(spaceCount + 1); cout.fill(' ');
		cout << " " << left << fixed << num;
	}
	if (num > 999 and num < 10000) {
		cout.precision(5);
		cout.width(spaceCount); cout.fill(' ');
		cout << " " << left << fixed << num;
	}

}

void Draw(struct Record* records) {
	unsigned short width = 95;
	cout << endl;	cout.width(width); cout.fill('-'); cout << "-" << endl;
	cout.fill(' '); cout.width(width - 1);  cout << left << "|Прайс-лист"; cout << "|" << endl;
	cout.width(width); cout.fill('-'); cout << "-" << endl;
	cout.fill(' ');
	cout << left << "|Наименование товара ";
	cout << left << "|Тип товара";
	cout << left << "|Цена за 1 шт (грн)";
	cout << left << "|  Минимальное количество  ";
	cout << left << " |     Дата     ";
	cout << "|" << endl;
	cout.width(width); cout.fill('-'); cout << "-" << endl;
	cout.fill(' ');
	for (int i = 0; i < 3; i++) {
		cout << left << "|"; cout.width(20); cout << left << records[i].name;
		cout << left << "|"; cout.width(10); cout << left << records[i].type;
		cout << left << "|"; cout.width(16); cout << left;
		printWithSpace4(records[i].price, 16, 8);
		cout << left << "|"; cout.width(27); cout << left << records[i].minCount;
		cout << left << "|";
		printDate(records[i].date.day, records[i].date.month, records[i].date.year, 16);
		cout << "|" << endl;
	}
	cout.width(width); cout.fill('-'); cout << "-" << endl;
	cout.fill(' '); cout.width(width - 1);  cout << left << "|Примечание: К – канцтовары, О – оргтехника "; cout << "|" << endl;
	cout.width(width); cout.fill('-'); cout << "-" << endl;
}

void insertMaxRecord(struct Record* table) {
	int elementCount = sizeof(table) / sizeof(Record);
	table = new Record[elementCount +1];
	table[elementCount] = { "BRUH",'B',99.00000,9,{12,04,2024}};
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	struct Record table[10];
	table[0] = { "Папка", 'К', 4.75000, 4, {03,07,2022} };
	table[1] = { "Бумага", 'К', 13.90000, 10, {03,04,2021} };
	table[2] = { "Калькулятор", 'О', 411.00000, 1, {4,3,2022} };

	Record tempRecord = { "Лист",'К',25.00000,6,{15,01,2023}};

	Draw(table);

	insertMaxRecord(table);
	Draw(table);
}
