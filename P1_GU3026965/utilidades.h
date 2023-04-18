#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
    Esta biblioteca contém funções para atividades auxiliares, tais como
    formatações, geração de menus, verificações etc.
*/

// Cria uma linha com o caractere e desejado.
void linha(char formato, int tamanho);

// Cria um cabeçalho padrão à todas as telas.
void gerarHeader();

// Chama o submenu, obtem a quantidade indicada pelo usuário e a retorna.
// Retornará 0 caso o usuário seleciona a opção "Voltar".
int obterQuantidade(char* titulo);
