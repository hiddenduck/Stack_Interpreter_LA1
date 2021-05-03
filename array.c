
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
 *
 */
void concatArray(Data *d1, Data *d2){
    if (d2->tipo != STACK) {
        Push(*d1, DataValSTACK(d2));
    } else {
        if (d1->tipo != STACK) {
            Stack *temp = CreateStack((DataValSTACK(d2))->sp + 1);
            Push(DataDup(d1), temp);
            Data d3 = CreateDataSTACK(temp);
            swapDataFree(d1, &d3);
        }
        for(int i=0; i<=(*DataValSTACK(d2)).sp; i++)
            Push(DataDup(&(*DataValSTACK(d2)).array[i]), DataValSTACK(d1));
    }
}

/**
 *
 * @param d1
 * @param d2
 */
void multArray(Data *d1, Data *d2){
    Data d3 = DataDup(d1);
    for(int i=1; i<*DataValLONG(d2); i++)
        concatArray(d1, &d3);
}
