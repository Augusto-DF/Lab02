#include "funcionary.h"

Funcionary::Funcionary(){
	name 	= "Não identificado";
	salary 	= 0.0;
	nFun++;
}
Funcionary::Funcionary(string n, float s, Date d){
	name 	= n;
	salary 	= s;
	date_	= d;
	nFun++;

}
Funcionary::Funcionary(Funcionary& func_){
	name 	= func_.name;
	salary 	= func_.salary;
	date_	= func_.date_;
	nFun++;
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

int Funcionary::getnFun(){
	return nFun;
}

bool Funcionary::operator== (Funcionary& func){
	if(name == func.getName() && date_ == func.getDate()){
		return true;
	}
	else return false;
}

bool Funcionary::operator!=(Funcionary& func){
	if(name != func.getName() && salary != func.getSalary() && date_ != func.getDate()){
		return true;
	}
	else return false;
}

std::ostream& operator<< (std::ostream &func0, Funcionary &func){
	func0 << func.getName() << "	||	" << func.getSalary() << "	||	" << func.getDate();
	return func0;
}

std::istream& operator>> (std::istream &func0, Funcionary &func){
	std::cout << "Digite o nome do funcionário: ";
	func0 >> func.name;
	std::cout << "Digite o salário do funcionário: ";
	func0 >> func.salary;
	std::cout << "Digite a data de admissão do funcionário: ";
	func0 >> func.date_;
	return func0;
}