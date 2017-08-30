#Makefile

#Compilador : g++
CC=g++

#Variáveis de diretórios:
INC_DIR=./include
SRC_DIR=./src
OBJ_DIR=./build
DOC_DIR=./doc
BIN_DIR=./bin
LIB_DIR=./lib
TEST_DIR=./test

#Váriavel de compilação:
CFLAGS=-Wall -pedantic -ansi -std=c++11 -I. -I$(INC_DIR)/q01
#CFLAGS2=-Wall -pedantic -ansi -std=c++11 -I. -I$(INC_DIR)/q02


.PHONY: all clean doxy debug doc

#Remove os arquivos .o:
all: questao01# questao02

debug: CFLAGS += -g -O0
#debug: CFLAGS2 += -g -O0
debug: questao01# questao02

#Criação do executavel: questao01
questao01: $(OBJ_DIR)/date.o $(OBJ_DIR)/funcionary.o $(OBJ_DIR)/main1.o #$(OBJ_DIR)/funcionary.o
	@echo	"======================"
	@echo	"Carregando o alvo $@"
	@echo	"======================"
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^
	@echo	"++++ [Executavel questao01 criado em $(BIN_DIR)] ++++"
	@echo	"  =============================================    "

#Criação dos arquivos .o:
#date.o
$(OBJ_DIR)/date.o: $(SRC_DIR)/q01/date.cpp $(INC_DIR)/q01/date.h
	$(CC) -c $(CFLAGS) -o $@ $<

#funcionary.o:
$(OBJ_DIR)/funcionary.o: $(SRC_DIR)/q01/funcionary.cpp $(INC_DIR)/q01/funcionary.h
	$(CC) -c $(CFLAGS) -o $@ $<

#main.o
$(OBJ_DIR)/main1.o: $(SRC_DIR)/q01/main.cpp
	$(CC) -c $(CFLAGS) -o $@ $<

doxy:
	rm -rf $(DOC_DIR)/*
	doxygen Doxyfile

clean:
	rm -rf $(BIN_DIR)/*
	rm -rf $(OBJ_DIR)/*