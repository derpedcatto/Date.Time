#pragma once
using namespace std;

class Date
{
private:
	int y;
	int m;
	int d;

public:
	/*Конструкторы*/
	Date()
	{
		SYSTEMTIME st;
		GetSystemTime(&st);
		SetYear(st.wYear);
		SetMonth(st.wMonth);
		SetDay(st.wDay);
	}

	Date(int y, int m, int d)
	{
		SetYear(y);
		SetMonth(m);
		SetDay(d);
	}

	/*Методы*/
	int PrintDate() const;
	string DayOfWeek() const;
	void AddDays(int input);
	int DateDifference(Date other);

	/*Операторы перегрузки*/
	Date& operator+(const int& input);
	Date& operator++(int);
	int operator-(const Date& other);
	bool operator>(const Date& other);
	bool operator<(Date& other);
	bool operator==(const Date& other);
	bool operator!=(const Date& other);
	Date& operator() (int y, int m, int d);
	friend ostream& operator<<(ostream& output, const Date& src);
	friend istream& operator>>(istream& input, Date& src);

	/*Set-Get*/
	void SetYear(int y);
	void SetMonth(int m);
	void SetDay(int d);

	int GetYear() const;
	int GetMonth() const;
	int GetDay() const;
};

/*
Разработать класс Date, включающий следующее :
+ Поля day, month, year;
+ Константный метод char* DayOfWeek() const;
+ Конструктор по умолчанию Date() (текущая дата);
+ Конструктор с параметрами Date(int day, int month, int year);
+ Необходимые сеттеры и геттеры для полей;
+ Метод, возвращающий разницу между двумя датами в днях («-»);
+ Метод изменения даты на заданное количество дней («+»);
+ Метод вывода даты на экран void PrintDate();
+ «+»
+ «-»
+ «++» 
- «--» 
+ «>»
+ «<»
+ «==»
+ «!=»
+ «>>»
+ «<<»
+ «( )»
*/