CC = g++
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/Ponto.o $(OBJ)/MetOrd.o $(OBJ)/Pilha.o $(OBJ)/Lista.o $(OBJ)/FechoConvexo.o
HDRS = $(INC)/Ponto.hpp $(INC)/MetOrd.hpp $(INC)/Pilha.hpp $(INC)/Celula.hpp $(INC)/Lista.hpp $(INC)/FechoConvexo.hpp

EXE = $(BIN)/fecho

all:  $(EXE)

$(BIN)/fecho: $(OBJS) $(SRC)/fecho.cpp
	$(CC) -o $(EXE) $(SRC)/fecho.cpp $(OBJS) -Wall

$(OBJ)/Ponto.o: $(HDRS) $(SRC)/Ponto.cpp
	$(CC) -o $(OBJ)/Ponto.o $(SRC)/Ponto.cpp -c -Wall

$(OBJ)/MetOrd.o: $(HDRS) $(SRC)/MetOrd.cpp
	$(CC) -o $(OBJ)/MetOrd.o $(SRC)/MetOrd.cpp -c -Wall

$(OBJ)/Pilha.o: $(HDRS) $(SRC)/Pilha.cpp
	$(CC) -o $(OBJ)/Pilha.o $(SRC)/Pilha.cpp -c -Wall

$(OBJ)/Lista.o: $(HDRS) $(SRC)/Lista.cpp
	$(CC) -o $(OBJ)/Lista.o $(SRC)/Lista.cpp -c -Wall

$(OBJ)/FechoConvexo.o: $(HDRS) $(SRC)/FechoConvexo.cpp
	$(CC) -o $(OBJ)/FechoConvexo.o $(SRC)/FechoConvexo.cpp -c -Wall
	
clean:
	rm -f $(EXE) $(OBJS)
