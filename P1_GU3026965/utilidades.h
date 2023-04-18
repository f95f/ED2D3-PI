#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
    Esta biblioteca cont�m fun��es para atividades auxiliares, tais como
    formata��es, gera��o de menus, verifica��es etc.
*/

// Cria uma linha com o caractere e desejado.
void linha(char formato, int tamanho);

// Cria um cabe�alho padr�o � todas as telas.
void gerarHeader();

// Chama o submenu, obtem a quantidade indicada pelo usu�rio e a retorna.
// Retornar� 0 caso o usu�rio seleciona a op��o "Voltar".
int obterQuantidade(char* titulo);
