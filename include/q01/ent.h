#ifndef ENT_H
#define ENT_H

#include <iostream>
#include <vector>

#include "funcionary.h"

class Enterprise{
	private:
		string name;
		string cnpj;
		std::vector<Funcionary*> func_;

	public:

		//Enterprise(); Achei que n havia necessidade de um construtor padrão, não parametrizado, uma vez que não existe empresa sem nome ou cnpj ou sem funcionario nenhum
		Enterprise(string n, string cnpj_, std::vector<Funcionary*> fun);
		//Enterprise(Enterprise& ent); Tambem achei desnecessário o construtor cópia ja que duas empresas não podem ter o mesmo cnpj

		string getName();
		void setName(string n); 

		string getCnpj();
		void setCnpj(string cnpj_); 

		Funcionary* getFun();
		void setFun(Funcionary* fun);

		bool cmpr(Funcionary func);
		void addfun(Funcionary* func);

		friend std::ostream& operator<< (std::ostream& ent0_, Enterprise& ent);
		
};

#endif