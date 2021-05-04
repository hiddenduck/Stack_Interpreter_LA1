
#include "array.h"

/**
 *  \brief Função que calcula o tamanho de um array.
 *  @param d1 Endereço de um Data do tipo STACK.
 */
void ArrayLength(Data *d1) {
    Data d2 = CreateDataLONG((*(DataValSTACK(d1))).sp + 1);
    swapDataFree(d1, &d2);
}

/**
 * \brief Função que cria um array com todos os números de 0 até o valor de d1
 *
 * @param d1 Endereço do Data do tipo INTEIRO que gera o array.
 */
void range(Data *d1){
    Data d2 = CreateDataSTACK(CreateStack(*DataValLONG(d1)));
    for(int i=0; i<*DataValLONG(d1); i++)
        Push(CreateDataLONG(i), DataValSTACK(&d2));
    //CleanupStack(DataValSTACK(&d2)); Apenas onde necessário
    swapDataFree(d1, &d2);
}

/**
 *  \brief Função que coloca na stack todos os elementos de um array.
 *  @param d1 Endereço de um Data.
 *  @param stack Endereço da stack.
 */
void til(Data *d1, Stack *stack){
    for(int i=1; i<(DataValSTACK(d1))->sp+1; i++)
        Push((DataValSTACK(d1))->array[i], stack);
    Data d2 = (DataValSTACK(d1))->array[0];
    //queremos é perder a armatura da Stack ANTES do swap
    free(DataValSTACK(d1));
    //não deve poder ser o free porque se não perdem-se os elementos do d1
    swapData(d1, &d2);
}

/**
 *  \brief Função que concatena duas stacks.
 *  @param d1 Endereço de um Data.
 *  @param d2 Endereço de um Data.
 *
 */
void concatArray(Data *d1, Data *d2){
    if (d2->tipo != STACK) {
        Push(DataDup(d2), DataValSTACK(d1));
        CleanupStack(DataValSTACK(d1));
    } else {
        if (d1->tipo != STACK) {
            Stack *temp = CreateStack((DataValSTACK(d2))->sp + 1);
            Push(DataDup(d1), temp);
            Data d3 = CreateDataSTACK(temp);
            swapDataFree(d1, &d3);
        }
        for(int i=0; i<=(DataValSTACK(d2))->sp; i++)
            Push(DataDup(&(DataValSTACK(d2))->array[i]), DataValSTACK(d1));
        //CleanupStack(DataValSTACK(d2));
    }
}

/**
 * \brief Função que repete um Data STACK n vezes.
 * @param d1 Endereço de um Data.
 * @param d2 Endereço de um Data.
 */
void multArray(Data *d1, Data *d2){
    Data d3 = DataDup(d1);
    for(int i=1; i<*DataValLONG(d2); i++)
        concatArray(d1, &d3);
}

void arrayRemoveFirst (Data *d1, Stack *stack){
    //referenciar a Data que vai acabar na stack
    Data *newD = Read((DataValSTACK(d1))->sp, DataValSTACK(d1));
    //alterar a stack do d1 para remover o primeiro elemento
    Stack *original = (DataValSTACK(d1));
    original->array++;
    original->sp--;
    original->size--;
    //por o Data lido na stack
    Push(*newD, stack);
}

void arrayRemoveLast (Data *d1, Stack *stack){
    Data newD = Pop(DataValSTACK(d1));
    //por o Data lido na stack
    Push(newD, stack);
}
