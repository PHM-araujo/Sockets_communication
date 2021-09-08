# Trabalho 5 - Simulação de algoritmos de substituição de páginas 
- Esse é um projeto que visou a simulação de vários conceitos de gerenciamento de memória em sistemas operacionais .

## Guia de Instalação:
1. Extrair o arquivo zip para o local desejado
2. Crie um arquivo de entrada do tipo .txt e insira no diretório base do projeto (junto ao Makefile)
3. Comando ```make``` para compilar
4. Para executar, insira no terminal "./simulador numero_de_quadros < nome_do_arquivo.txt" (sem aspas)
5. Exemplo de como a entrada ficará no terminal: ```./simulador 4 < referencias.txt```
6. Caso deseje recompilar, utilize ```make clean``` para apagar os objetos e repita os passos anteriores pra recriá-los
7. Caso tenha interesse, utilizando ```make valgrind``` o programa será executado para 64 quadros automaticamente e realizará a checagem de vazamento de memória

## Pré-requisitos: 
1. Bibliotecas Utilizadas
	- vector
	- iostream
	- iomanip
	- chrono
	- thread
	- fstream
2. Sistema operacional: Linux 20.04
3. IDE : Visual Studio Code
4. Compilador: G++ 
5. Dialeto == C++17

##Como formatar o seu arquivo de entrada
1. Primeiramente ele deve ser do tipo .txt
2. Em seguida ele deve conter números separados somente por quebra de linha
3. Ou seja, o arquivo contém somente 1 coluna com 1 número em cada linha
	
## Autoria e constribuições:
- Esse projeto é autoria de Pedro Henrique Melo Araujo e Arthur Haickel Nina.
	
## Fontes:
- TANENBAUM, A. S. , Sistemas Operacionais Modernos. Segunda Edição, Prentice Hall, 2003.
- Stack Overflow, c2021. Disponível em: <stackoverflow.com>. Acesso em: 28 de agosto de 2021.
- SISTEMAS OPERACIONAIS: Gerenciamento de memória - paginação. Prof. Carlos Maziero, DInf UFPR, Curitiba PR, julho de 2020.
