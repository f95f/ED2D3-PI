#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
    Esta biblioteca cont�m fun��es para atividades auxiliares, tais como
    formata��es, gera��o de menus, verifica��es etc.
*/

// Estrutura para armazenar informa��es sobre os testes, tais como tempos de execu��es.
typedef struct r R;
// Cria uma linha com o caractere e desejado.
void linha(char formato, int tamanho);

// Cria um cabe�alho padr�o � todas as telas.
void gerarHeader();

// Chama o submenu, obtem a quantidade indicada pelo usu�rio e a retorna.
// Retornar� 0 caso o usu�rio seleciona a op��o "Voltar".
int obterQuantidade(char* titulo);

// Retorna um vetor din�mico de n�meros inteiros aleat�rios com a quantidade especificada.
int *gerarLista(int tamanho);

// Recebe uma estrutura com informa��es sobre o teste e os exibe na tela.
void mostrarResultados();
