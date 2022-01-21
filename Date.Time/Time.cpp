#include "libraries.h"
using namespace std;

int Time::PrintTime() const
{
	return printf("%02d:%02d:%02d\n", h, m, s);
}

char* Time::TimeOfDay() const
{
	char* ch = new char[8];

	if (h >= 0 && h <= 6)
	{
		strcpy_s(ch, 8, "Night");
		return ch;
	}
	else if (h >= 7 && h <= 12)
	{
		strcpy_s(ch, 8, "Morning");
		return ch;
	}
	else if (h >= 13 && h <= 18)
	{
		strcpy_s(ch, 8, "Day");
		return ch;
	}
	else if (h >= 18 && h < 24)
	{
		strcpy_s(ch, 8, "Evening");
		return ch;
	}
}

int Time::AddSeconds(int input)
{
	while (true)
	{
		if (s + input > 59)
		{
			input -= (60 - s);
			s = 0;
			m++;

			if (m == 60)
			{
				m = 0;
				h++;

				if (h == 24)
				{
					h = 0;
				}
			}
		}

		else
		{
			return s += input;
		}
	}
}

int Time::RemoveSeconds(int input)
{
	while (true)
	{
		if (s - input < 0)
		{
			input -= s;
			s = 60;
			m--;

			if (m < 0)
			{
				m = 59;
				h--;

				if (h < 0)
				{
					h = 23;
				}
			}
		}

		else
		{
			return s -= input;
		}
	}
}

/*Операторы перегрузки*/
Time& Time::operator+(const int& input)
{
	this->AddSeconds(input);
	return *this;
}
Time& Time::operator-(const int& input)
{
	this->RemoveSeconds(input);
	return *this;
}

//postfix
Time& Time::operator++(int)
{
	this->AddSeconds(1);
	return *this;
} 
Time& Time::operator--(int)
{
	this->RemoveSeconds(1);
	return *this;
}
bool Time::operator>(const Time& other)
{
	if (h > other.h)
		return true;
	else if (h == other.h && m > other.m)
		return true;
	else if (h == other.h && m == other.m && s > other.s)
		return true;
	else
		return false;
}
bool Time::operator<(Time& other)	//const?
{
	return other > *this;
}
bool Time::operator==(const Time& other)
{
	if (h == other.h && m == other.m && s == other.s)
		return true;
	else
		return false;
}
bool Time::operator!=(const Time& other)
{
	return !(*this == other);
}
Time& Time::operator() (int h, int m, int s)
{
	SetHours(h);
	SetMinutes(m);
	SetSeconds(s);
	return *this;
}
ostream& operator<<(ostream& output, const Time& src)
{
	return output << src.PrintTime();
}
istream& operator>>(istream& input, Time& src)
{
	int hh, mm, ss;
	input >> hh >> mm >> ss;

	src.SetHours(hh);
	src.SetMinutes(mm);
	src.SetSeconds(ss);

	return input;
}

/*Set-Get*/
void Time::SetSeconds(int s)
{
	if (s < 0 || s > 59)
		throw "Error";

	this->s = s;
}
void Time::SetMinutes(int m)
{
	if (m < 0 || m > 59)
		throw "Error";

	this->m = m;
}
void Time::SetHours(int h)
{
	if (h < 0 || h > 23)
		throw "Error";

	this->h = h;
}

unsigned int Time::GetSeconds() const { return s; }
unsigned int Time::GetMinutes() const { return m; }
unsigned int Time::GetHours() const { return h; }
