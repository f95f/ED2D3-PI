#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
    Esta biblioteca contém funções para atividades auxiliares, tais como
    formatações, geração de menus, verificações etc.
*/

// Estrutura para armazenar informações sobre os testes, tais como tempos de execuções.
typedef struct r R;

// Cria uma linha com o caractere e desejado.
void linha(char formato, int tamanho);

// Cria um cabeçalho padrão à todas as telas.
void gerarHeader();

// Função para validação de respostas do usuário - verifica se o valor informado "resposta" está dentro
// do intervalo informado por parâmetro (valorMin e valorMax).
int checkResposta(int resposta, int valorMin, int valorMax);

// Chama o submenu, obtem a quantidade indicada pelo usuário e a retorna.
// Retornará 0 caso o usuário seleciona a opção "Voltar".
int obterQuantidade();

// Retorna um vetor dinâmico de números inteiros aleatórios com a quantidade especificada.
int *gerarLista(int tamanho);

// Monta a lista de números aleatórios, executa a ordenação de acordo com o algoritmo solicitado
// e executa a medição de tempo.
int executar(int op, int quant);

// Obtem uma amostra de 100 números de uma lista e a exibe na tela.
// Esta função foi implementada com a intenção de verificar de forma simples a lista antes e depois
// de ordenada. Recebe a descrição por parâmetro e a exibe na tela.
void amostrar(int *lista, char *descr);

// Recebe uma estrutura com informações sobre o teste e os exibe na tela.
void mostrarResultados();
