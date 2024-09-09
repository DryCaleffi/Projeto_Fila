
#ifndef fila_h
#define fila_h
#include <stdbool.h>
// Adryelle Caroline de Souza Calefi
// Brenda
// Tabata 

// Constantes
enum {
  TAMANHO = 5,
  FIM_FILA = 5,
  INICIO_FILA = 0,
  VAZIA = true,
  NAO_VAZIA = false
};

// Declarações de variáveis externas
extern int vec_fila[TAMANHO];
extern int finalfila;
extern int iniciofila;

// Declarações de funções
bool push_queue(int value);
bool move_queue(int* value);
void show_vec();
void pesquisar_fila();

#endif 