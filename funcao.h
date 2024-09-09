#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include <time.h>

// Adryelle Caroline de Souza Calefi
// Brenda
// Tabata 

// Variáveis globais, utilizadas em todo o código 
int vec_fila[TAMANHO];
bool flag_queue[TAMANHO] = {VAZIA, VAZIA, VAZIA, VAZIA, VAZIA};
int finalfila = INICIO_FILA;
int iniciofila = INICIO_FILA;

// Função para inicializar a fila e gerar um número aleatório
void inicializa_fila() {
    srand(time(NULL)); // Inicializa o gerador de números aleatórios, com base no tempo atual, ele começa nulo por isso o NULL

}
// verifica se o valor gerado não é igual a algum existente na fila
bool verificarsenha(int senha) {
    int i = iniciofila;
    do { 
        if (vec_fila[i] == senha) {
            return false; // Senha já existe na fila
        }
        
        i++; // Avança para a próxima posição

        // Verifica se chegou ao final da fila
        if (i == FIM_FILA) {
            i = INICIO_FILA; // Volta ao início da fila circular
        }

    } while (i != finalfila); // Continua até verificar todos os elementos

    return true; // Senha não encontrada na fila
}


// Verifica se a fila está cheia para inserir números ou sair da fila , se estiver cheia sai do códogo
bool push_queue(int valor) {
    if (flag_queue[finalfila] == NAO_VAZIA) {
        printf("Fila cheia\n");
        return false;  // Fila cheia
    }
// chama a fução para gerar o numero aleatório
    int numeroAleatorio = rand(); // Gera número aleatório e insere caso a fila esteja vazia, e ainda tenha espaço
    if (!verificarsenha(numeroAleatorio)) {
        // se não for igual ao verificador da senha,
        numeroAleatorio = rand(); // Gera outro número se for repetido
    }
//Imprime o valor gerado ao cliente 
    printf("\nSua senha é: %d\n", numeroAleatorio);
    vec_fila[finalfila] = numeroAleatorio; // Armazena o número gerado na fila
    flag_queue[finalfila] = NAO_VAZIA;
    finalfila++; // Move o final da fila para a próxima posição

    if (finalfila == FIM_FILA) {
        finalfila = INICIO_FILA; // Reseta o final da fila se atingir o limite
    }

    return true;
}

// Pesquisa na fila, mostra o valor que foi adicionado
void pesquisar_fila() {
    if (iniciofila == finalfila && flag_queue[iniciofila] == VAZIA) {
        printf("Fila vazia\n");
    } else {
        printf("O valor da fila é: %d\n", vec_fila[iniciofila]);
    }
}

// Imprime o valor do início da fila e o remove (esvazia)
void imprimir_inicio() {
    if (iniciofila == finalfila && flag_queue[iniciofila] == VAZIA) {
        printf("Fila vazia\n");
    } else {
        printf("Senha a ser atendida: %d\n", vec_fila[iniciofila]);
        
        // Esvazia o valor que foi atendido
        vec_fila[iniciofila] = 0; // Ou um valor especial para indicar vazio (ex: -1)
        flag_queue[iniciofila] = VAZIA; // Marca a posição como vazia

        iniciofila++; // Move o início da fila para a próxima posição

        if (iniciofila == FIM_FILA) {
            iniciofila = INICIO_FILA; // Reseta o início da fila se atingir o limite
        }
    }
}