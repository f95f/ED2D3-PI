#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
    Esta biblioteca cont�m fun��es para atividades auxiliares, tais como
    formata��es, gera��o de menus, gera��o de vetores, verifica��es etc.,
    bem como a fun��o principal de executar as medi��es e exibir os resultados.
*/

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

// Monta a lista de n�meros aleat�rios de acordo com a quantidade informada,
// executa a ordena��o de acordo com o algoritmo solicitado e executa a medi��o de tempo.
// Ao final, exibe os resultados das medi��es.
int executar(int op, int quant);
