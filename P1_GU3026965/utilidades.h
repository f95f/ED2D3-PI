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

// Fun��o para valida��o de respostas do usu�rio - verifica se o valor informado "resposta" est� dentro
// do intervalo informado por par�metro (valorMin e valorMax).
int checkResposta(int resposta, int valorMin, int valorMax);

// Chama o submenu, obtem a quantidade indicada pelo usu�rio e a retorna.
// Retornar� 0 caso o usu�rio seleciona a op��o "Voltar".
int obterQuantidade();

// Retorna um vetor din�mico de n�meros inteiros aleat�rios com a quantidade especificada.
int *gerarLista(int tamanho);

// Monta a lista de n�meros aleat�rios, executa a ordena��o de acordo com o algoritmo solicitado
// e executa a medi��o de tempo.
int executar(int op, int quant);

// Obtem uma amostra de 100 n�meros de uma lista e a exibe na tela.
// Esta fun��o foi implementada com a inten��o de verificar de forma simples a lista antes e depois
// de ordenada. Recebe a descri��o por par�metro e a exibe na tela.
void amostrar(int *lista, char *descr);

// Recebe uma estrutura com informa��es sobre o teste e os exibe na tela.
void mostrarResultados();
