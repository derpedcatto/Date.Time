#pragma once
#include <iostream>
#include <chrono>
using namespace std;

class Date
{
private:
	int y;
	int m;
	int d;

public:
	/*������������*/
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

	/*������*/
	int PrintDate() const;
	char* DayOfWeek() const;
	void AddDays();

	/*��������� ����������*/
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
����������� ����� Date, ���������� ��������� :
+ ���� day, month, year;
- ����������� ����� char* DayOfWeek() const;
+ ����������� �� ��������� Date() (������� ����);
+ ����������� � ����������� Date(int day, int month, int year);
+ ����������� ������� � ������� ��� �����;
- �����, ������������ ������� ����� ����� ������ � ���� (�-�);
- ����� ��������� ���� �� �������� ���������� ���� (�+�);
+ ����� ������ ���� �� ����� void PrintDate();
- �+�
- �-�
- �++� 
- �--� 
+ �>�
+ �<�
+ �==�
+ �!=�
+ �>>�
+ �<<�
+ �( )�
*/