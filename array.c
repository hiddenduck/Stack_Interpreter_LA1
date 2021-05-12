
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
void range(Data *d1, Stack *stack){
    Data d2 = CreateDataSTACK(CreateStack(*DataValLONG(d1), stack->collec, stack->vars));
    long i;
    long long a, j;
    NumTestD1
    for(i=0; i<LONG_MAX-1 && i<a; i++)
        Push(CreateDataLONG(i), DataValSTACK(&d2));
    for(j = i; j<a; j++)
        Push(CreateDataLONGLONG(j), DataValSTACK(&d2));
    //CleanupStack(DataValSTACK(&d2)); Apenas onde necessário
    //precisamos de passar aqui o vars e o collec
    swapDataFree(d1, &d2);
}

/**
 *  \brief Função que coloca na stack todos os elementos de um array.
 *  @param d1 Endereço de um Data.
 *  @param stack Endereço da stack.
 */
void til(Data *d1, Stack *stack) {
    int i = (DataValSTACK(d1))->sp;
    for (; i>0; i--) {
        Data temp = DataDup(Read(i, DataValSTACK(d1)));
        Push(temp, stack);
    }
    Data d2 = DataDup(Read(i, DataValSTACK(d1)));
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
        Push(DataDup(d2), DataValSTACK(d1));
        CleanupStack(DataValSTACK(d1));
    } else {
        if (d1->tipo != STACK) {
            Stack *temp = CreateStack((DataValSTACK(d2))->sp + 1,
                                      (DataValSTACK(d2))->collec,
                                      (DataValSTACK(d2))->vars);
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

/**
 * \brief Função que remove o primeiro elemento de uma STACK.
 * @param d1 Endereço de um Data.
 * @param stack Endereço da stack.
 */
void arrayRemoveFirst (Data *d1, Stack *stack){
    //referenciar a Data que vai acabar na stack
    Data newD = *Read((DataValSTACK(d1))->sp, DataValSTACK(d1));

    CleanupStack((DataValSTACK(d1)));

    (DataValSTACK(d1))->array++;
    (DataValSTACK(d1))->sp--;
    if ((DataValSTACK(d1))->sp != -1) {
        Data newStack = DataDup(d1);
        Push(newStack, stack);
    }
    swapDataFree(d1, &newD);
}

/**
 * \brief Função que remove o último elemento de uma STACK.
 * @param d1 Endereço de um Data.
 * @param stack Endereço da stack.
 */
void arrayRemoveLast (Data *d1, Stack *stack){
    Data newD = Pop(DataValSTACK(d1));
    //por o Data lido na stack
    swapData(d1, &newD);
    if ((DataValSTACK(&newD))->sp != -1)
        Push(newD, stack);
}

/**
 * \brief Função que vai buscar o elemento de acordo com o índice.
 * @param d1 Endereço de um Data.
 * @param stack Endereço da stack.
 */
void arrayGetInd (Data *d1, Data *d2){
    Data dvalor = DataDup(Read((DataValSTACK(d1))->sp - *DataValLONG(d2), DataValSTACK(d1)));
    swapDataFree(d1, &dvalor);
}

/**
 * \brief Função que vai buscar X chars no inicio de um Data STACK.
 * @param d1 Endereço de um Data.
 * @param d2 Endereço de um Data.
 */
void arrayGetXStart (Data *d1, Data *d2){
    int i;
    Data temp = CreateDataSTACK(DumpStack(DataValSTACK(d1)));
    for(i = 0; i<*DataValLONG(d2); i++)
        Push(DataDup(Read((DataValSTACK(&temp))->sp - i, DataValSTACK(&temp))), DataValSTACK(d1));
    Free(&temp);
}

/**
 * \brief Função que vai buscar X chars no inicio de um Data STACK.
 * @param d1 Endereço de um Data.
 * @param d2 Endereço de um Data.
 * @param stack Endereço da stack.
 * 012 2 >
 * sp = 2, d2 = 2, i = 1
 *
 */
void arrayGetXEnd (Data *d1, Data *d2){
    int i;
    Data temp = CreateDataSTACK(DumpStack(DataValSTACK(d1)));
    for(i = (DataValSTACK(&temp))->sp - *DataValLONG(d2) +1 ; i<= (DataValSTACK(&temp))->sp; i++)
        Push(DataDup(Read((DataValSTACK(&temp))->sp - i, DataValSTACK(&temp))), DataValSTACK(d1));
    Free(&temp);
}
