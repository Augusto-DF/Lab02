#include <iostream>

#include "date.h"
#include "funcionary.h"
#include "ent.h"

using namespace std;

float Enterprise::nEnt = 0;
float Funcionary::nFun = 0;


/*---MENU--- Primeira escolha
	c- Criar empresa
	e- Encerrar programa
*/
int main(){

	char choice = 'a';		//Variavel do menu
	char scdchoice = 's';	//Variavel para verificar se o usuario deseja criar uma nova empresa
	char addfun_ = 'n';		//Variaval para saber se quer um novo funcionario
	std::vector<Enterprise*> empresas_;		//vector de Empresas
	std::vector<Enterprise*>::iterator it;	//iterador
	char trdchoice = 'a';

	//Menu
	while (choice != 's'){
		std::cout << "\t---MENU---\n\tc - Criar empresa\n\ta - Acessar Empresa\n\ts - Sair" << endl;
		std::cin >> choice;
		
		while(choice != 'c' && choice != 'a' && choice != 's'){
			std::cout << "Entrada inválida, tente novamente:" << endl;
			std::cout << "\t---MENU---\n\tc - Criar empresa\n\ts - Sair\n" << endl;
			std::cin >> choice;
		}

		//Criando nova empresa:
		if(choice == 'c'){			

			while(scdchoice == 's'){
				empresas_.push_back(new Enterprise());
				it = empresas_.end() - 1;
				cin >> (**it);

				//Adicionando novo funcionário:
				std::cout << "Deseja adicionar mais 1 funciário na empresa: " << (**it).getName() << "? s - Sim   n - Não: ";
				std::cin >> addfun_;
				
				while(addfun_ != 's' && addfun_ != 'n'){
					std::cout << "Entrada inválida, tente novamente:" << endl;
					std::cout << "Deseja adicionar mais 1 funciário na empresa: " << (**it).getName() << "? s - Sim   n - Não: ";
				}
				while(addfun_ == 's'){
					(**it).addfun();
					std::cout << "Deseja adicionar mais 1 funciário na empresa: " << (**it).getName() << "? s - Sim   n - Não: ";
					std::cin >> addfun_;
				}


				std::cout << "Deseja criar outra empresa? s - Sim n - Não: ";
				std::cin >> scdchoice;

				while (scdchoice != 's' && scdchoice != 'n'){
					std::cout << "Entrada inválida, tente novamente:" << endl;
					std::cout << "Deseja criar outra empresa? s - Sim n - Não: ";
					std::cin >> scdchoice;
				}
			}
		}
		//Acessando empresa:
		/*
		  l - Listar todos os Funcionarios da empresa
		  a - Aumento de tantos % para todos os Funcionarios da empresa
		  e - Listar Funcionarios em periodo de experiencia 
		  m - Media de funcionários por empresa
		  s - Sair
		 */
		else if (choice == 'a'){
			std::vector<Enterprise*>::iterator it2;
			int nEmp = -1;
			
			std::cout << "Digite o numero da empresa que vc quer acessar: " << endl;
			int i1(0);
			for(it2 = empresas_.begin(); it2 < empresas_.end(); ++it2){
				std::cout << i1 << " - " << (**it2) << endl;
				++i1;
			}
			std::cin >> nEmp;

			while (nEmp < 0 || nEmp > i1){
				std::cout << "Entrada inválida, tente novamente:" << endl;
				std::cout << "Digite o numero da empresa que vc quer acessar: " << endl;
				i1 = 0;
				for(it2 = empresas_.begin();it2 < empresas_.end(); ++it2){
					std::cout << i1 << " - " << (**it2) << endl;
					++i1;
				}
				it2 = empresas_.begin();
				std::cin >> nEmp;
			}

			std::cout << "\tQual o tipo de acesso que você deseja?\n\tl - Listar todos os Funcionarios da empresa\n\ta - Aumento em porcetagem salarial para todos os Funcionarios da empresa\n\te - Listar Funcionarios em periodo de experiencia\n\tm - Media de funcionários por empresa\n\ts - Sair" << endl; 
			std::cin >> trdchoice;
			
			while(trdchoice != 'l' && trdchoice != 'a' && trdchoice != 'e' && trdchoice != 'm' && trdchoice != 's') {
				std::cout << "Entrada inválida, tente novamente:" << endl;
				std::cout << "\tQual o tipo de acesso que você deseja?\n\tl - Listar todos os Funcionarios da empresa\n\ta - Aumento em porcetagem salarial para todos os Funcionarios da empresa\n\te - Listar Funcionarios em periodo de experiencia\n\tm - Media de funcionários por empresa\n\ts - Sair" << endl; 
			}

			if(trdchoice == 'l'){
				//it2 = it2 + nEmp;
				it2 = empresas_.begin() + nEmp;

				(**it2).listfun();
			}

			else if(trdchoice == 'a'){
				float plus = 0;
				std::cout << "Digite o valor em porcetagem salarial a ser incrementado: ";
				std::cin >> plus;
				
				while(plus < 0){
					std::cout << "Entrada inválida, tente novamente" << endl;
					std::cout << "Digite o valor em porcetagem salarial a ser incrementado: ";
					std::cin >> plus;
				}
				it2 = it2 + nEmp;
				(**it2).increasesal(plus);
			}

			else if(trdchoice == 'e'){
				Date d_;
				
				std::cout << "Digite a data de comparação: ";
				cin >> d_;
				
				it2 = it2 + nEmp;
				(**it2).experienceperiod(d_);
			}

			else if(trdchoice == 'm'){
				(**it2).media();
			}

			else if(trdchoice == 's'){
				choice = 's';
			}
		}
	}
}
