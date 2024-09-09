#include <stdio.h>
#include <stdlib.h>
#include "funcao.h"

// Adryelle Caroline de Souza Calefi
// Brenda
// Tabata

enum { // criar um menu mais facil de entender.
    OPSAIR = 0,
    OPRETIRARSENHA = 1,
    OPATENDER = 2,
};

int main() {
    int op;

    // Inicializa a fila
    inicializa_fila();

    // Criar menu
    printf("Bem vindo ao sistema de senha!\n");
    printf("\n1 - Retirar senha");
    printf("\n2 - Atender");
    printf("\n0 - Sair");

    do {
        printf("\nEscolha uma opcao: ");
        scanf("%d", &op);

        switch (op) {
            case OPRETIRARSENHA:
                // Adiciona um novo número aleatório na fila
                if (push_queue(0)) {
                    printf("Senha retirada com sucesso!\n");
                } else {
                    printf("Fila cheia. Não foi possível retirar nova senha.\n");
                }
                break;

           case OPATENDER:
            imprimir_inicio(); // Remove e imprime a senha a ser atendida
                break;

            case OPSAIR:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida!\n");
                break;
        }
    } while (op != OPSAIR);

    return 0;
}
