/**
 * @file	dado.h
 * @brief	Declaração da classe Dado, seus atributos e seus métodos
 * @author	Mattheus Augusto Pinheiro de Oliveira
 * @since	04/09/2017
 * @date	04/09/2017
*/
#ifndef _DADO_H_
#define _DADO_H_

#include <random>
#include <ostream>

/**
 * @brief	Declaração da classe dado
*/
class Dado {
	private:
		int valor;

	public:
		static std::random_device rd;
		static std::mt19937 gen;
		static std::uniform_int_distribution<> dis;

		/**
		 * @brief	Construtor padrão não parametrizado:
		 * @param 	Não recebe parametros
		 * @return	Objeto da classe Dado
		*/
		Dado();

		/**
		 * @brief	Construtor padrão  parametrizado:
		 * @param 	val Valor atual do dado
		 * @return	Objeto da classe Dado
		*/
		Dado(int val);
		
		/**
		 * @brief	Função que gera um valor aleatório para um objeto dado 
		 * @param 	Não recebe parametros
		 * @return	Valor inteiro aleatório entre 1 - 6
		*/
		int jogar();

		/**
		 * @brief	Função que que retorna o valor do objeto dado 
		 * @param 	Não recebe parametros
		 * @return	Valor do atributo val
		*/
		int getValor();

		/**
		 * @brief	Sobrecarga do operador de inserção
		*/
		friend std::ostream& operator<< (std::ostream &o, Dado const &d);

		/**
		 * @brief	Sobrecarga do operador de adição para objetos
		*/
		Dado operator+(const Dado &d) const;

		/**
		 * @brief	Sobrecarga do operador de adição entre objetos e inteiros
		*/
		int operator+(const int &val) const;
		
		/**
		 * @brief	Typecast de objetos da classe dado para inteiros
		*/
		operator int();
};
#endif