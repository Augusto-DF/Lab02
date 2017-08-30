#include <iostream>

#include "date.h"

using namespace std;

int main(){

	Date a(22, 12, 2001);
	Date b(22, 10, 2002);

	if(a > b){
		std::cout << "pessoa a é mais nova que pessoa b" << endl;
	}

	else if (a < b){
		std::cout << "pessoa a é mais velha que pessoa b " << endl; 
	}

	else if (a == b) {
		std::cout << "pessoa a e pessoa b tem a mesma idade" << endl;
	}

	std::cout << a.diference(b) << endl;

}