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
CFLAGS2=-Wall -pedantic -ansi -std=c++11 -I. -I$(INC_DIR)/q02


.PHONY: all clean doxy debug doc

#Remove os arquivos .o:
all: questao01 questao02

debug: CFLAGS += -g -O0
debug: CFLAGS2 += -g -O0
debug: questao01 questao02

#Criação do executavel: questao01
questao01: $(OBJ_DIR)/date.o $(OBJ_DIR)/funcionary.o $(OBJ_DIR)/ent.o $(OBJ_DIR)/main1.o 
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

#ent.o:
$(OBJ_DIR)/ent.o: $(SRC_DIR)/q01/ent.cpp $(INC_DIR)/q01/ent.h
	$(CC) -c $(CFLAGS) -o $@ $<

#main.o
$(OBJ_DIR)/main1.o: $(SRC_DIR)/q01/main.cpp
	$(CC) -c $(CFLAGS) -o $@ $<

questao02: $(OBJ_DIR)/dado.o $(OBJ_DIR)/jogador.o $(OBJ_DIR)/main2.o 
	@echo	"======================"
	@echo	"Carregando o alvo $@"
	@echo	"======================"
	$(CC) $(CFLAGS2) -o $(BIN_DIR)/$@ $^
	@echo	"++++ [Executavel questao02 criado em $(BIN_DIR)] ++++"
	@echo	"  =============================================    "

#Criação dos arquivos .o:
#dado.o
$(OBJ_DIR)/dado.o: $(SRC_DIR)/q02/dado.cpp $(INC_DIR)/q02/dado.h
	$(CC) -c $(CFLAGS2) -o $@ $<

#jogador.o
$(OBJ_DIR)/jogador.o: $(SRC_DIR)/q02/jogador.cpp $(INC_DIR)/q02/jogador.h
	$(CC) -c $(CFLAGS2) -o $@ $<

#main2.o
$(OBJ_DIR)/main2.o: $(SRC_DIR)/q02/main.cpp
	$(CC) -c $(CFLAGS2) -o $@ $<

doxy:
	rm -rf $(DOC_DIR)/*
	doxygen Doxyfile

clean:
	rm -rf $(BIN_DIR)/*
	rm -rf $(OBJ_DIR)/*