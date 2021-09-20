# Trabalho 5 - Comunicação via Rede através de Sockets
- Esse é um projeto que visou trabalhar a questão de comunicação e troca de informações via rede entre computadores utilizando o conceito de sockets em C++.

## Guia de Instalação:
1. Extrair o arquivo zip para o local desejado
2. Comando ```make``` para compilar
3. Para executar  ```make run```
4. Caso deseje recompilar, utilize ```make clean``` para apagar os objetos e repita os passos anteriores pra recriá-los
5. Caso tenha interesse, utilizando ```make valgrind``` o programa será executado para 64 quadros automaticamente e realizará a checagem de vazamento de memória

## Pré-requisitos: 
1. Bibliotecas Utilizadas
	- vector
	- iostream
	- iomanip
	- limits
	- string
	- unistd.h
	- sys/socket.h
	- netinet/in.h
2. Sistema operacional: Linux 20.04
3. IDE : Visual Studio Code
4. Compilador: G++ 
5. Dialeto == C++17

## Como comunicar os sockets
1. Primeiramente abra um terminal no diretório Client e outro no Server 
2. Em seguida, execute um ou o outro
3. Siga as instruções do primeiro socket a ser iniciado e execute o outro em seguida, eles esperam por sinais um do outro
	
## Autoria e constribuições:
- Esse projeto é autoria de Pedro Henrique Melo Araujo e Arthur Haickel Nina.
	
## Fontes:
- TANENBAUM, A. S. , Sistemas Operacionais Modernos. Segunda Edição, Prentice Hall, 2003.
- Stack Overflow, c2021. Disponível em: <stackoverflow.com>. Acesso em: 17 de setembro de 2021.
- Geeks for Geeks, c2021. Disponível em: <https://www.geeksforgeeks.org/socket-programming-cc/>. Acesso em: 14 de setembro de 2021.
