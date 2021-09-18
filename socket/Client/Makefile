#Exemplo de makefile

# Copilador
CC = g++ -std=c++17

# Flags de copilacao
FLAGS = -Wall -Wextra -Wshadow -Werror

# Variaveis do tipo execultavel
O = *.o

#Nome do execultavel
EXE = exe

# Comando para limpar arquivo
RM = rm -rf

# Comando para pegar todos os .cpp da pasta do Makefile
APPNAME = $(wildcard *.cpp)

# Copila e execulta o programa e depois apaga todos os arquivos .o e o
# execultavel criado
all: run clean

# Limpa o terminal de verdade
limpa:
	tput reset

# Copila e execulta o programa
run:
	$(CC) $(FLAGS) -c $(APPNAME)
	$(CC) $(FLAGS) -o $(EXE) $(O)
	./$(EXE)

# Apaga todos os arquivos .o e o execultavel criado
clean:
	$(RM) $(O)
	$(RM) $(EXE)

.PHONY: all clean
#------------------------------------------------------------------------------#