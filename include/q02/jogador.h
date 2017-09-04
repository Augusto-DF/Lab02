/**
 * @file	jogador.h
 * @brief	Declaração da classe Jogador, seus atributos e seus métodos
 * @author	Mattheus Augusto Pinheiro de Oliveira
 * @since	04/09/2017
 * @date	04/09/2017
*/
#ifndef JOGADOR_H
#define JOGADOR_H

#include <iostream>
#include "dado.h"

class Jogador{
	private:
		int id;
		int pont_max;
		char jogada;
	public:
		static int N;
		static int numJogadores;

		/**
		 * @brief	Construtor padrão não parametrizado:
		 * @param 	Não recebe parametros
		 * @return	Objeto da classe Jogador
		*/
		Jogador();

		/**
		 * @brief	Retorna a pontuação maxima atual do jogador
		 * @return	Valor inteiro referente ao atributo pont_max
		*/
		int getPont_max();

		/**
		 * @brief	Retorna oidentificador do jogador
		 * @return	Valor inteiro referente ao atributo id
		*/
		int getId();

		/**
		 * @brief	Modificador do atributo id do jogador
		*/
		void setId(int i);

		/**
		 * @brief	Retorna o tipo da jogada do jogador
		 * @return	Valor caractere referente ao atributo jogada
		*/
		char getJogada();

		/**
		 * @brief	Modificador do atributo jogada do jogador
		*/
		void setJogada(char l);
		
		/**
		 * @brief	Modificador do atributo pont_max do jogador 
		*/
		void somaJogada(Dado& a, Dado& b);

		/**
		 * @brief	Função que gera 2 dados e soma os valores deles
		*/
		void turno();

		/**
		 * @brief	Função que verifica se o atributo pont_max do jogador é maior que N
		 * @return	true 	- Para pont_max > N
		 * @return	false	- Para pont_max < N
		*/
		bool perdeu();

		/**
		 * @brief	Função que verifica se o atributo pont_max do jogador é igual que N
		 * @return	true 	- Para pont_max == N
		 * @return	false	- Para pont_max != N
		*/
		bool venceu();

		/**
		 * @brief	Sobrecarga do operador >
		*/
		bool operator> (Jogador& ply);

		/**
		 * @brief	Sobrecarga do operador <
		*/
		bool operator< (Jogador& ply);

		/**
		 * @brief	Sobrecarga do operador ==
		*/
		bool operator== (Jogador& ply);

		/**
		 * @brief	Sobrecarga do operador =
		*/
		Jogador operator= (Jogador& ply);	

		/**
		 * @brief	Sobrecarga do operador  << (inserção)
		*/
		friend std::ostream& operator<<(std::ostream& j0, Jogador& j);
};

#endif