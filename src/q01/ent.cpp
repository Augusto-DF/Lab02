#include "ent.h"
#include <vector>

Enterprise::Enterprise(string n, string cnpj_, std::vector<Funcionary*> fun){
	name = n;
	cnpj = cnpj_;

	for(std::vector<Funcionary*>::iterator it = fun.begin(); it < fun.end(); ++it){
		func_.push_back(*it);
	}
}

string Enterprise::getName(){
	return name;
}

void Enterprise::setName(string n){
	name = n;
}

string Enterprise::getCnpj(){
	return cnpj;
}

void Enterprise::setCnpj(string cnpj_){
	cnpj = cnpj_;
}

Funcionary* Enterprise::getFun(){
	return (*func_.begin());
}

void Enterprise::setFun(Funcionary* fun){
	func_.push_back(fun);
}

bool Enterprise::cmpr(Funcionary func){
	for(std::vector<Funcionary*>::iterator it = func_.begin();it < func_.end(); ++it){
		if((**it) == func) return true;
	}
	return false;
}

void Enterprise::addfun(Funcionary* func){
	if(cmpr(*func) == false){
		func_.push_back(func);
	}
	else{
		std::cout << "O funcionario ja é contratado da empresa: " << getName() << std::endl;
	}
}

std::ostream& operator<< (std::ostream &ent0_, Enterprise &ent){
	ent0_ << ent.getName() << "\n" << ent.getCnpj() << "\n" << "Quantidade de funcionarios: " << ent.func_.size();
	return ent0_;
}

