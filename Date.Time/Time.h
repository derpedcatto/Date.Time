#pragma once
class Time
{
private:
	int s;
	int m;
	int h;

public:
	/*Конструкторы*/
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

	/*Методы*/
	int PrintTime() const;
	char* TimeOfDay() const;
	int AddSeconds(int input);
	int RemoveSeconds(int input);

	/*Операторы перегрузки*/
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
Разработать класс Time,  включающий следующее:
+ Поля seconds, minutes, hours;
+ Константный метод char *TimeOfDay() const;
+ Конструктор по умолчанию Time() (текущее время);
+ Конструктор с параметрами Time(int day, int month, int year);
+ Необходимые сеттеры и геттеры для полей;
+ Метод изменения времени на заданное количество секунд (перегруженный бинарный оператор «+»);
+ Метод вывода времени на экран void PrintTime();
+ «+»
+ «-»
+ «++»
+ «--»
+ «>»
+ «<»
+ «==»
+ «!=»
+ «>>»
+ «<<»
+ «( )»
*/
