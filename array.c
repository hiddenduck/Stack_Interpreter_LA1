
#include "array.h"

/**
 *  \brief Função que calcula o tamanho de um array.
 *  @param d1 Endereço de um Data.
 */
void range(Data *d1) {
    Data d2 = CreateDataLONG((*(DataValSTACK(d1))).sp + 1);
    swapDataFree(d1, &d2);
}

/**
 *  \brief Função que coloca na stack todos os elementos de um array.
 *  @param d1 Endereço de um Data.
 *  @param stack Endereço da stack.
 */
void til(Data *d1, Stack *stack){
    for(int i=1; i<(*DataValSTACK(d1)).sp+1; i++)
        Push((*DataValSTACK(d1)).array[i], stack);
    Data d2 = (*DataValSTACK(d1)).array[0];
    swapDataFree(d1, &d2);
}

/**
 *  \brief Função que concatena duas stacks.
 *  @param d1 Endereço de um Data.
 *  @param d2 Endereço de um Data.
 */
void concatArray(Data *d1, Data *d2){
    int i;
    for(i=0; i<=(*DataValSTACK(d2)).sp; i++)
        Push((*DataValSTACK(d2)).array[i], DataValSTACK(d1));
}