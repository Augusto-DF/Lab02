#include <iostream>

#include "date.h"
#include "funcionary.h"

using namespace std;

int main(){

	Date aa(10,10,2000);
	Date bb;

	bb = aa;

	cout << bb << endl;

	Funcionary a("Jão", 1000.0, aa);

	Funcionary b("Caio", 20000.0, bb);

	std::cout << a << endl;
	std::cout << b << endl;

	cout << a.getDate() << endl;

}