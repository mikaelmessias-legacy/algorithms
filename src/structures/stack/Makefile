# Compilador (gcc/g++)
CC=gcc

# Flags passadas ao compilador
FLAGS=-std=c99	\
			-W				\
			-Wall			\
			-pedantic \
			-g

# Dependências
DEPS=stack.h

# Nome do executável a ser gerado
EXEC=main

# Arquivos fontes a serem compilados
SRC= $(wildcard *.c)

# Arquivos objetos a serem gerados
OBJ= $(SRC:.c=.o)

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(FLAGS)

main: $(OBJ)
	$(CC) -o $(EXEC).out $(OBJ) $(FLAGS)

debug:

.PHONY: clean

clean:
	rm -f *.o *.out
