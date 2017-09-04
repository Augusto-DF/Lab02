/**
 * @file	dado.cpp
 * @brief	Implementação dos métodos da classe Dado
 * @author	Mattheus Augusto Pinheiro de Oliveira
 * @since	04/09/2017
 * @date	04/09/2017
*/
#include <random>
#include <ostream>
#include <random>
#include "dado.h"
#include <iostream>

std::random_device Dado::rd{};
std::mt19937 Dado::gen(Dado::rd());
std::uniform_int_distribution<> Dado::dis(1,6);

/**
		 * @brief	Construtor padrão não parametrizado:
		 * @param 	Não recebe parametros
		 * @return	Objeto da classe Dado
*/
Dado::Dado() {
	valor = std::round(dis(gen));
}

/**
		 * @brief	Construtor padrão  parametrizado:
		 * @param 	val Valor atual do dado
		 * @return	Objeto da classe Dado
*/
Dado::Dado(int val) {
	valor = val;
}

/**
		 * @brief	Função que gera um valor aleatório para um objeto dado 
		 * @param 	Não recebe parametros
		 * @return	Valor inteiro aleatório entre 1 - 6
*/
int Dado::jogar() {
	valor = std::round(dis(gen));
	return valor;
}

/**
		 * @brief	Função que que retorna o valor do objeto dado 
		 * @param 	Não recebe parametros
		 * @return	Valor do atributo val
*/
int Dado::getValor() {
	return valor;
}

/**
 * @brief	Sobrecarga do operador de inserção
*/
std::ostream& operator<< (std::ostream &o, Dado const &d) {
	o << d.valor;
	return o;
}
/**
 * @brief	Sobrecarga do operador de adição para objetos
*/
Dado Dado::operator+(const Dado &d) const {
	return Dado(this->valor+d.valor);
}
/**
 * @brief	Sobrecarga do operador de adição entre objetos e inteiros
*/
int Dado::operator+(const int &val) const {
	return (this->valor+val);
}
/**
 * @brief	Typecast de objetos da classe dado para inteiros
*/
Dado::operator int() {
	return valor;
}