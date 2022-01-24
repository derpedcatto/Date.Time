#include "libraries.h"

/*Функции*/
bool isLeap(int y)
{
	if (y % 100 != 0 && y % 4 == 0 || y % 400 == 0)
		return true;

	return false;
}

int countLeapYears(Date d)
{
	int years = d.GetYear();

	if (d.GetMonth() <= 2)
		years--;

	return isLeap(years);
}

int offsetDays(int d, int m, int y)
{
	int offset = d;

	switch (m - 1)
	{
	case 11:
		offset += 30;
	case 10:
		offset += 31;
	case 9:
		offset += 30;
	case 8:
		offset += 31;
	case 7:
		offset += 31;
	case 6:
		offset += 30;
	case 5:
		offset += 31;
	case 4:
		offset += 30;
	case 3:
		offset += 31;
	case 2:
		offset += 28;
	case 1:
		offset += 31;
	}

	if (isLeap(y) && m > 2)
		offset += 1;

	return offset;
}

void revoffsetDays(int offset, int y, int* d, int* m)
{
	int month[13] = { 0, 31, 28, 31, 30, 31, 30,
					  31, 31, 30, 31, 30, 31 };

	if (isLeap(y))
		month[2] = 29;

	int i;
	for (i = 1; i <= 12; i++)
	{
		if (offset <= month[i])
			break;
		offset = offset - month[i];
	}

	*d = offset;
	*m = i;
}

/*Методы*/
int Date::PrintDate() const
{
	return printf("%02d:%02d:%02d\n", d, m, y);
}

string Date::DayOfWeek() const
{
	string weekday[7] = { "Saturday","Sunday","Monday","Tuesday", "Wednesday","Thursday","Friday" };
	Date tmp;
	tmp.y = y;

	if (m > 2)
		tmp.m = m; //for march to december month code is same as month
	else {
		tmp.m = (12 + m); //for Jan and Feb, month code will be 13 and 14
		tmp.y--; //decrease year for month Jan and Feb
	}
	int last_dig = tmp.y % 100;	//last two digit
	int first_dig = tmp.y / 100; //first two digit
	int w = (d + floor((13 * (tmp.m + 1)) / 5) + last_dig + floor(last_dig / 4) + floor(first_dig / 4) + (5 * first_dig));
	w = w % 7;

	return weekday[w];
}

void Date::AddDays(int input)
{
	int offset1 = offsetDays(d, m, y);
	int remDays = isLeap(y) ? (366 - offset1) : (365 - offset1);

	int y2, offset2;
	if (input <= remDays)
	{
		y2 = y;
		offset2 = offset1 + input;
	}

	else
	{
		input -= remDays;
		y2 = y + 1;
		int y2days = isLeap(y2) ? 366 : 365;
		while (input >= y2days)
		{
			input -= y2days;
			y2++;
			y2days = isLeap(y2) ? 366 : 365;
		}
		offset2 = input;
	}

	int m2, d2;
	revoffsetDays(offset2, y2, &d2, &m2);

	y = y2;
	m = m2;
	d = d2;
}

int Date::DateDifference(Date other)
{
	const int monthDays[12]
		= { 31, 28, 31, 30, 31, 30,
		   31, 31, 30, 31, 30, 31 };

	long int n1 = y * 365 + d;
	for (int i = 0; i < m - 1; i++)
		n1 += monthDays[i];
	n1 += countLeapYears(*this);


	long int n2 = other.y * 365 + other.d;
	for (int i = 0; i < other.m - 1; i++)
		n2 += monthDays[i];
	n2 += countLeapYears(other);

	if (*this > other)
		return (n1 - n2);
	else
		return (n2 - n1);
}

/*Операторы перегрузки*/
Date& Date::operator+(const int& input)
{
	this->AddDays(input);
	return *this;
}
Date& Date::operator++(int)
{
	this->AddDays(1);
	return *this;
}
int Date::operator-(const Date& other)
{
	return DateDifference(other);
}
bool Date::operator>(const Date& other)
{
	if (y > other.y)
		return true;
	else if (y == other.y && m > other.m)
		return true;
	else if (y == other.y && m == other.m && d > other.d)
		return true;
	else
		return false;
}
bool Date::operator<(Date& other)
{
	return other > *this;
}
bool Date::operator==(const Date& other)
{
	if (y == other.y && m == other.m && d == other.d)
		return true;
	else
		return false;
}
bool Date::operator!=(const Date& other)
{
	return !(*this == other);
}
Date& Date::operator() (int y, int m, int d)
{
	SetYear(y);
	SetMonth(m);
	SetDay(d);
	return *this;
}
ostream& operator<<(ostream& output, const Date& src)
{
	src.PrintDate();
	return output; 
}
istream& operator>>(istream& input, Date& src)
{
	int yy, mm, dd;
	input >> yy >> mm >> dd;

	src.SetYear(yy);
	src.SetMonth(mm);
	src.SetDay(dd);

	return input;
}

/*Set-Get*/
/*Сделать проверку для Day*/
void Date::SetYear(int y)
{
	if (y < 0)
		throw "Error";

	this->y = y;
}
void Date::SetMonth(int m)
{
	if (m < 0 || m > 12)
		throw "Error";

	this->m = m;
}
void Date::SetDay(int d)
{
	if (d < 1 || d > 31)
		throw "Error";

	this->d = d;
}

int Date::GetYear() const { return y; }
int Date::GetMonth() const { return m; }
int Date::GetDay() const { return d; }