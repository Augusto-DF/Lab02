#include "ent.h"
#include <vector>

Enterprise::Enterprise(){
	name = " ";
	cnpj = " ";	
	nEnt++;
}

Enterprise::Enterprise(string n, string cnpj_, Funcionary* fun){
	name = n;
	cnpj = cnpj_;
	func_.push_back(fun);	
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

bool Enterprise::cmpr(){
	std::vector<Funcionary*>::iterator it2 = (func_.end() - 1);
	if(func_.begin() == func_.end()){
		return false;
	}

	for(std::vector<Funcionary*>::iterator it = func_.begin();it < func_.end(); ++it){
		if((**it) == (**it2)) {
			return true;
		}
	}
	return false;
}

void Enterprise::addfun(){
	std::vector<Funcionary*>::iterator it = (func_.end() - 1);
	func_.push_back(new Funcionary());
	std::cin >> (**it);

	if(cmpr() == false){
		std::cout << "Funcionario adicionado" << std::endl;
	}
	else{
		std::cout << "O funcionario ja é contratado da empresa: " << getName() << std::endl;
		func_.pop_back();
	}
}

void Enterprise::listfun(){
	std::vector<Funcionary*>::iterator it;
	std::cout << "Funcionários da empresa " << getName() << ": " << std::endl;
	for(it = func_.begin();it < func_.end();++it){
		std::cout << (**it) << std::endl;
	}
}

void Enterprise::increasesal(float prct){
	float increase;
	std::vector<Funcionary*>::iterator it;
	for(it = func_.begin();it < func_.end();++it){
		increase = (**it).getSalary() + ((**it).getSalary()/100) * prct;
		(**it).setSalary(increase);
	}
	listfun();
}

void Enterprise::experienceperiod(Date date_){
	std::vector<Funcionary*>::iterator it;
	std::cout << "Funcionários da empresa " << getName() << " em periodo de experiencia: " << std::endl;
	for(it = func_.begin();it < func_.end();++it){

		if((**it).getDate().diference(date_) > -90){
			std::cout << (**it) << std::endl;
		}
	}
}

float Enterprise::media(){
	float total = ((*func_.begin()))->nFun/nEnt;
	return total;
}

std::ostream& operator<< (std::ostream &ent0_, Enterprise &ent){
	ent0_ << ent.getName() << "\n" << ent.getCnpj() << "\n" << "Quantidade de funcionarios: " << ent.func_.size();
	return ent0_;
}

std::istream& operator>> (std::istream& ent0_, Enterprise& ent){
	std::cout << "Digite o nome da empresa: ";
	ent0_ >> ent.name;
	std::cout << "Digite o numero do CNPJ: ex: **.***.***/0001-** ";
	ent0_ >> ent.cnpj;

	/*while(ent.cnpj.at(2)!='.' || ent.cnpj.at(6) != '.' || ent.cnpj.at(10) != '/' || ent.cnpj.at(11) != '0' || ent.cnpj.at(12) != '0' || ent.cnpj.at(13) != '0' || ent.cnpj.at(14) != '1' || ent.cnpj.at(15) != '-'){
		std::cout << "CNPJ inválido. Digite o numero do CNPJ: ex: **.***.***//*0001-** ";
		ent0_ >> ent.cnpj;
	}*/


	/*ent0_ >> ent.func_.begin();*/
	return ent0_;
}

