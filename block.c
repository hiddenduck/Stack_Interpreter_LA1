
#include "block.h"

/** \brief Função que executa um bloco.
 *  @param d1 Endereço de um data.
 *  @param stack Endereço da stack.
 */
void ExecuteBlock(Data *d1, Stack *stack) {
    eval(DataValSTRING(d1), stack);
    Data d2 = Pop(stack);
    swapDataFree(d1, &d2);
}


void MapBlockArray(Data *d1, Data *d2, Stack *stack){
    for (int i = (DataValSTACK(d1))->sp; i>=0; i--) {
        Data temp = DataDup(Read(i, DataValSTACK(d1)));
        Push(temp, stack);
        eval(DataValSTRING(d2), stack);
    }
    Data d3 = Pop(stack);
    swapDataFree(d1, &d3);
}

void MapBlockString(Data *d1, Data *d2, Stack *stack){
    long size = strlen(DataValSTRING(d1));
    for(int i=0; i<size; i++){
        Data temp = CreateDataCHAR((DataValSTRING(d1))[i]);
        Push(temp, stack);
        eval(DataValSTRING(d2), stack);
    }
    Data d3 = Pop(stack);
    swapDataFree(d1, &d3);
}

/** \brief Função que realiza o map de blocos.
 *  @param d1 Endereço de um data.
 *  @param d2 Endereço de um data.
 *  @param stack Endereço da stack.
 */
void MapBlock(Data *d1, Data *d2, Stack *stack) {
    if(d1->tipo == STRING)
        MapBlockString(d1, d2, stack);
    else
        MapBlockArray(d1, d2 , stack);
}
