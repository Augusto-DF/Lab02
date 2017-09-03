#include <iostream>

#include "date.h"
#include "funcionary.h"
#include "ent.h"

using namespace std;

int main(){

	string a = "Dragonfly";
	string b = "02.302.567/0001-56";
	Date q(24,12,1990);
	std::vector<Funcionary*> vF;

	vF.push_back(new Funcionary("Jão",2000.0,q));

	Enterprise k(a,b,vF);

	std::cout << k << endl;

	k.addfun(new Funcionary("Jão",2000.0,q));

}