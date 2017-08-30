#include "funcionary.h"

Funcionary::Funcionary(){
	name 	= "Não identificado";
	salary 	= 0.0;
}
Funcionary::Funcionary(string n, float s, Date d){
	name 	= n;
	salary 	= s;
	date_	= d;

}
Funcionary::Funcionary(Funcionary& func_){
	name 	= func_.name;
	salary 	= func_.salary;
	date_	= func_.date_;
}

string Funcionary::getName() {
	return name;
}
void Funcionary::setName(string n){
	name = n;
}
float Funcionary::getSalary(){
	return salary;
}
void Funcionary::setSalary(float s){
	salary = s;
}
Date& Funcionary::getDate(){
	return date_;
}
void Funcionary::setDate(Date d){
	date_ = d;
}

std::ostream& operator<< (std::ostream &func0, Funcionary &func){
	func0 << func.getName() << "||" << func.getSalary() << "||" << func.getDate();
	return func0;
}