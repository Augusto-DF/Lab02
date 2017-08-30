#ifndef FUNCIONARY_H
#define FUNCIONARY_H

#include <iostream>
#include <string>

using std::string;

#include "date.h"

class Funcionary{

	private:
		std::string name;
		float salary;
		Date date_;

	public:
		Funcionary();
		Funcionary(string n, float s, Date d);
		Funcionary(Funcionary& func_);

		string getName();
		void setName(string n);
		float getSalary();
		void setSalary(float s);
		Date& getDate();
		void setDate(Date d);

		friend std::ostream& operator<< (std::ostream &func0, Funcionary &func);
};

#endif