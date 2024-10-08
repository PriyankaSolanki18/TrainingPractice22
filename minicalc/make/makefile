CC = gcc
CFLAGS = -Wall -Werror -g -c
IFLAGS = -I $(INC)
LDFLAGS = -o

SRC = ./src
OBJ = ./object
BIN = ./bin
INC = ./include



all: $(OBJ)/main.o $(OBJ)/function.o
	$(CC) $(LDFLAGS) $(BIN)/calc $(OBJ)/main.o $(OBJ)/function.o
$(OBJ)/main.o: $(SRC)/main.c
	$(CC) $(CFLAGS) $(SRC)/main.c $(IFLAGS)
$(OBJ)/function.o: $(SRC)/function.c
	$(CC) $(CFLAGS) $(SRC)/function.c $(IFLAGS)
	mv *.o $(OBJ)
clean: 
	rm $(OBJ)/*.o
	rm $(BIN)/calc
	echo "Cleaned successfully"


