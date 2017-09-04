/**
 * @file	jogador.cpp
 * @brief	Implementação dos métodos da classe Jogador
 * @author	Mattheus Augusto Pinheiro de Oliveira
 * @since	04/09/2017
 * @date	04/09/2017
*/
#include <iostream>
#include "jogador.h"

/**
 * @brief	Construtor padrão não parametrizado:
 * @param 	Não recebe parametros
 * @return	Objeto da classe Jogador
*/
Jogador::Jogador(){
	numJogadores++;
	id = numJogadores;
	pont_max = 0;
}

/**
 * @brief	Retorna a pontuação maxima atual do jogador
 * @return	Valor inteiro referente ao atributo pont_max
*/
int Jogador::getPont_max(){
	return pont_max;
}

/**
 * @brief	Retorna oidentificador do jogador
 * @return	Valor inteiro referente ao atributo id
*/
int Jogador::getId(){
	return id;
}

/**
 * @brief	Modificador do atributo id do jogador
*/
void Jogador::setId(int i){
	id = i;
}

/**
 * @brief	Retorna o tipo da jogada do jogador
 * @return	Valor caractere referente ao atributo jogada
*/
char Jogador::getJogada(){
	return jogada;
}

/**
 * @brief	Modificador do atributo jogada do jogador
*/
void Jogador::setJogada(char l){
	while (l != 'r' && l != 'p'){
		std::cout << "Entrada inválida, tente novamente: " << std::endl;
		std::cout << "Qual a sua jogada? r - Rolar dados	p - Passar: ";
		std::cin >> l;
	}

	jogada = l;
}

/**
 * @brief	Modificador do atributo pont_max do jogador 
*/
void Jogador::somaJogada(Dado& a, Dado& b){
	pont_max = pont_max + a + b;
}

/**
 * @brief	Função que gera 2 dados e soma os valores deles
*/
void Jogador::turno(){
	if(jogada == 'r'){
		Dado x;
		Dado y;

		x.jogar();
		y.jogar();

		somaJogada(x, y);
	}
}

/**
 * @brief	Função que verifica se o atributo pont_max do jogador é maior que N
 * @return	true 	- Para pont_max > N
 * @return	false	- Para pont_max < N
*/
bool Jogador::perdeu(){
	if(pont_max > N){
		return true;
	}
	return false; 
}

/**
 * @brief	Função que verifica se o atributo pont_max do jogador é igual que N
 * @return	true 	- Para pont_max == N
 * @return	false	- Para pont_max != N
*/
bool Jogador::venceu(){
	if(pont_max == N){
		return true;
	}
	return false;
}

/**
 * @brief	Sobrecarga do operador >
*/
bool Jogador::operator> (Jogador& ply){
	if(pont_max > ply.pont_max) return true;
	return false;
}

/**
 * @brief	Sobrecarga do operador <
*/
bool Jogador::operator< (Jogador& ply){
	if(pont_max < ply.pont_max) return true;
	return false;
}
/**
 * @brief	Sobrecarga do operador ==
*/
bool Jogador::operator== (Jogador& ply){
	if(pont_max == ply.pont_max) return true;
	return false;
}	

/**
 * @brief	Sobrecarga do operador =
*/
Jogador Jogador::operator= (Jogador& ply){
	id 			= ply.getId();
	pont_max 	= ply.getPont_max();
	jogada 		= ply.getJogada();

	return *this;		
}

/**
 * @brief	Sobrecarga do operador  << (inserção)
*/
std::ostream& operator<<(std::ostream& j0, Jogador& j){
	std::cout << "Player: ";
	j0 << j.getId();
	std::cout << std::endl;
	std::cout << "Pontuação atual: ";
	j0 << j.getPont_max();
	std::cout << std::endl;
	return j0;
}