/**
 * @file	main.cpp
 * @brief	Implementação da função main()
 * @author	Mattheus Augusto Pinheiro de Oliveira
 * @since	04/09/2017
 * @date	04/09/2017
*/
#include <iostream>
#include <vector>

#include "jogador.h"
#include "dado.h"

int Jogador::numJogadores = 0;
int Jogador::N = 30;

int main(){

	std::vector<Jogador> jogadores_;	

	char novojog;
	std::cout << "Deseja adicionar um novo jogador? s - Sim   n - Não: ";
	std::cin >> novojog;

	if(novojog == 's'){
		jogadores_.push_back(*(new Jogador()));
	}

	//Define a quantidade de jogadores:
	while (novojog == 's'){
		std::cout << "Deseja adicionar mais um novo jogador? s - Sim   n - Não: ";
		std::cin >> novojog;
		if(novojog == 's'){
			jogadores_.push_back(*(new Jogador()));
		}
	}	

	//Lista os jogadores:
	for(std::vector<Jogador>::iterator it = jogadores_.begin(); it != jogadores_.end(); ++it){
		std::cout << (*it) << std::endl;
		std::cout << std::endl;
	}

	char start;
	std::cout << "Deseja começar o jogo? s - Sim   n - Não: ";
	std::cin >> start;

	if(start == 's'){

		//Começo do jogo:
		char pass = '-';		//variavel que diz que todos os participantes passaram
		char fzrJogada = '-';	//variavel de escolha da jogada
		int fimdjogo = 0;		//variavel de verificação de fim de jogo
		int playerRes = jogadores_.size(); //variavel que verifica se há mais de 1 jogador que não ultrapassou o valor maximo N
		
		Jogador win_player = (*jogadores_.begin());

		while(fimdjogo != 1){
			//Laço para verificar se todos os jogadroes passaram a vez:
			for(std::vector<Jogador>::iterator it3 = jogadores_.begin(); it3 != jogadores_.end(); ++it3){
				if((*it3).getJogada() == 'r') {
					pass = 'r';
					break;
				}
				else if((*it3).getJogada() == 'p'){
					pass = 'p';
				}

			}
			//Primeira condição de termino da partida: Quando todos os jogadores passam a vez
			if(pass == 'p'){
				fimdjogo = 1;
				for(std::vector<Jogador>::iterator it4 = jogadores_.begin(); it4 != jogadores_.end(); ++it4){
					if((*it4) > win_player){
						win_player = (*it4);
					}
				}
			}

			else if(pass != 'p' && fimdjogo != 1){
				//Laço para fazer a jogada:
				for(std::vector<Jogador>::iterator it2 = jogadores_.begin(); it2 != jogadores_.end(); ++it2){
					//Terceira condição de parada: Quando apenas 1 jogador não estrapolou o limite N
					if(playerRes == 1 && (*it2).perdeu() != true){
						win_player = (*it2);
						fimdjogo = 1;
						break;
					}
					else if((*it2).getJogada() != 'p' && (*it2).perdeu() != true){
						std::cout << (*it2) << "Qual a sua jogada? r - Rolar dados		p - Passar:\t";
						std::cin >> fzrJogada;

						(*it2).setJogada(fzrJogada);
						(*it2).turno();	
						fzrJogada = '-';

						if((*it2).perdeu() == true){
							playerRes--;
						}

						//Segunda condição de termino de jogo: Quando algum jogador atinge o valor maximo N
						if((*it2).venceu() == true){
							win_player = (*it2);
							fimdjogo = 1;
							break;
						}	
					}
				}
			}
		}
		std::cout << "=====VENCEDOR=====" << std::endl;
		std::cout << win_player << std::endl;
	}	
}