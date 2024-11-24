CC = gcc
CFLAGS = -Wall -g
SRC = Compartimento.c ListaMinerais.c ListaSondas.c Minerais.c RochaMineral.c SistemaDeControle.c Sonda.c main.c
OBJ = $(SRC:.c=.o)
EXEC = programa 

all: $(EXEC) testes

$(EXEC): $(OBJ)
    $(CC) $(CFLAGS) -o $@ $^

%.o: %.c
    $(CC) $(CFLAGS) -c $< -o $@

testes: Teste1 Teste2 TestePTerminal TestepTerminal2

Teste1: Teste1.c $(OBJ)
    $(CC) $(CFLAGS) -o $@ Teste1.c $(OBJ)

Teste2: Teste2.c $(OBJ)
    $(CC) $(CFLAGS) -o $@ Teste2.c $(OBJ)

TestePTerminal: TestePTerminal.c $(OBJ)
    $(CC) $(CFLAGS) -o $@ TestePTerminal.c $(OBJ)

TestepTerminal2: TestepTerminal2.c $(OBJ)
    $(CC) $(CFLAGS) -o $@ TestepTerminal2.c $(OBJ)

clean:
    rm -f *.o $(EXEC) Teste1 Teste2 TestePTerminal TestepTerminal2

rebuild: clean all
