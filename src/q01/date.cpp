#include "date.h"

Date::Date(int d, int m, int y){
	day 	= d;
	month 	= m;
	year 	= y;
}
Date::Date(Date& date){
	day 	= date.day;
	month 	= date.month;
	year 	= date.year;
}

int Date::getDay(){
	return day;
}
void Date::setDay(int d){
	day = d;
}
int Date::getMonth(){
	return month;
}
void Date::setMonth(int m){
	month = m;
}
int Date::getYear(){
	return year;
}
void Date::setYear(int y){
	year = y;
}

int Date::diference(Date& b){
	int total = 0;

	total = (day + (month * 30) + (year * 365)) - (b.getDay() + (b.getMonth() * 30) + (b.getYear() *365));

	return total;
}

std::ostream& operator<< (std::ostream &d0, Date &d){
	d0 << d.getDay() << "/" << d.getMonth() << "/" << d.getYear();
	return d0;
}

/*std::ostream& operator>> (std::ostream &d0, Date &d){
	d0 >> d.day >> d.month >> d.year;
	return d0;
}*/

bool Date::operator>(Date& b){
	if(year > b.getYear()){return true;}
	else if (month > b.getMonth() && year == b.getYear()){return true;}
	else if (day > b.getDay() && year == b.getYear() && month == b.getMonth()){return true;}

	else {return false;} 
}

bool Date::operator==(Date& b){
	if(year == b.getYear() && month == b.getMonth() && day == b.getDay()){
		return true;
	}

	else {return false;} 
}

bool Date::operator<(Date& b){
	if(year < b.getYear()){return true;}
	else if (month < b.getMonth() && year == b.getYear()){return true;}
	else if (day < b.getDay() && year == b.getYear() && month == b.getMonth()){return true;}

	else {return false;} 
}
