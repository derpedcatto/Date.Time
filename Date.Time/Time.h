#pragma once
class Time
{
private:
	int s;
	int m;
	int h;

public:
	/*������������*/
	Time()
	{
		SYSTEMTIME st;
		GetSystemTime(&st);
		h = (st.wHour + 2) % 24;
		m = st.wMinute;
		s = st.wSecond;
	}

	Time(int h, int m, int s)
	{
		SetHours(h);
		SetMinutes(m);
		SetSeconds(s);
	}

	/*������*/
	int PrintTime() const;
	char* TimeOfDay() const;
	int AddSeconds(int input);
	int RemoveSeconds(int input);

	/*��������� ����������*/
	Time& operator+(const int& other);
	Time& operator-(const int& other);

	Time& operator++(int);
	Time& operator--(int);

	bool operator>(const Time& other);
	bool operator<(Time& other);
	bool operator==(const Time& other);
	bool operator!=(const Time& other);

	Time& operator() (int h, int m, int s);
	friend ostream& operator<<(ostream& output, const Time& src);
	friend istream& operator>>(istream& input, Time& src);

	/*Set-Get*/
	void SetSeconds(int s);
	void SetMinutes(int m);
	void SetHours(int h);

	unsigned int GetSeconds() const;
	unsigned int GetMinutes() const;
	unsigned int GetHours() const;
};

/*
����������� ����� Time,  ���������� ���������:
+ ���� seconds, minutes, hours;
+ ����������� ����� char *TimeOfDay() const;
+ ����������� �� ��������� Time() (������� �����);
+ ����������� � ����������� Time(int day, int month, int year);
+ ����������� ������� � ������� ��� �����;
+ ����� ��������� ������� �� �������� ���������� ������ (������������� �������� �������� �+�);
+ ����� ������ ������� �� ����� void PrintTime();
+ �+�
+ �-�
+ �++�
+ �--�
+ �>�
+ �<�
+ �==�
+ �!=�
+ �>>�
+ �<<�
+ �( )�
*/