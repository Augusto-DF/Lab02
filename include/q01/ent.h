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

		static float nEnt;

		Enterprise(); 
		Enterprise(string n, string cnpj_, Funcionary* fun);
		//Enterprise(Enterprise& ent); Tambem achei desnecessário o construtor cópia ja que duas empresas não podem ter o mesmo cnpj

		string getName();
		void setName(string n); 

		string getCnpj();
		void setCnpj(string cnpj_); 

		Funcionary* getFun();
		void setFun(Funcionary* fun);

		bool cmpr();
		void addfun();
		void listfun();
		void increasesal(float prct);
		void experienceperiod(Date date_);
		float media();

		friend std::ostream& operator<< (std::ostream& ent0_, Enterprise& ent);
		friend std::istream& operator>> (std::istream& ent0_, Enterprise& ent);
		
};

#endif