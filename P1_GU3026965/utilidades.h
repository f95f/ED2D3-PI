#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
    Esta biblioteca contém funções para atividades auxiliares, tais como
    formatações, geração de menus, geração de vetores, verificações etc.,
    bem como a função principal de executar as medições e exibir os resultados.
*/

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

// Monta a lista de números aleatórios de acordo com a quantidade informada,
// executa a ordenação de acordo com o algoritmo solicitado e executa a medição de tempo.
// Ao final, exibe os resultados das medições.
int executar(int op, int quant);
