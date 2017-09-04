#include "date.h"

Date::Date(){
	day 	= 0;
	month 	= 0;
	year 	= 0;
}
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

std::istream& operator>> (std::istream &d0, Date &d){
	std::cout << "Digite a data: ";
	std::cout << "Dia: ";
	d0 >> d.day;
	while(d.day < 0 || d.day > 30){
		std::cout << "Dia inválido escolha um dia entre 1 e 30: ";
		d0 >> d.day;
	}
	std::cout << "Mes: ";
	d0 >> d.month;
	while(d.month < 0 || d.month > 12){
		std::cout << "Dia inválido escolha um dia entre 1 e 12: ";
		d0 >> d.month;
	}
	std::cout << "Ano: ";
	d0 >> d.year;
	while(d.year > 2017){
		std::cout << "Funcionarios do futuro não são bem vindos, contrate outro ou coloque o ano certo: ";
		d0 >> d.year;
	}
	return d0;
}

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

bool Date::operator!=(Date& b){
	if(year != b.getYear() && month != b.getMonth() && day != b.getDay()){
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

Date& Date::operator=(Date& b){
	day = b.getDay();
	month = b.getMonth();
	year = b.getYear();

	return *this;
}
