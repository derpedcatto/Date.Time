#include "libraries.h"

int Date::PrintDate() const
{
	return printf("%02d:%02d:%02d\n", d, m, y);
}

char* Date::DayOfWeek() const
{
	char* ch = new char[20];
	return 0;
}

void Date::AddDays()
{

}

/*Операторы перегрузки*/
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
	return output << src.PrintDate();
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