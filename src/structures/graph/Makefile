# Compilador (gcc/g++)
CC=gcc

# Flags passadas ao compilador
CFLAGS=-Wall -Werror -pedantic

# Dependências
DEPS=graph.h

# Nome do executável a ser gerado
EXEC=graph

# Arquivos fontes a serem compilados
SRC= $(wildcard *.c)

# Arquivos objetos a serem gerados
OBJ= $(SRC:.c=.o)

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

regra1: $(OBJ)
	$(CC) -o $(EXEC).out $(OBJ) $(CFLAGS)

.PHONY: clean

clean:
	rm -f *.o

clean-all:
	rm -f *.o *.out
