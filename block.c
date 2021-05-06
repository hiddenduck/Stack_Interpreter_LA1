
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

/** \brief Função que auxilia o MapBlock com arrays.
 *  @param d1 Endereço de um Data.
 *  @param d2 Endereço de um Data.
 *  @param stack Endereço da stack.
 */
void MapBlockArray(Data *d1, Data *d2) {
    Data newStack = CreateDataSTACK(DumpStack(DataValSTACK(d1)));
    //depositar os elementos todos do d1 no newStack com Pop == limpar o d1
    //função dumpStack que deposita uma stack noutra e ta top com Pops
    for (int i = (DataValSTACK(&newStack))->sp; i>=0; i--) {
        Data temp = DataDup(Read(i, DataValSTACK(&newStack)));
        Push(temp, (DataValSTACK(d1)));
        eval(DataValSTRING(d2), (DataValSTACK(d1)));
    }
    Free(&newStack);
    //free ao newStack de alguma maneira
    //se o newStack fosse um Data talvez ajudasse
}

/** \brief Função que auxilia o MapBlock com strings.
 *  @param d1 Endereço de um Data.
 *  @param d2 Endereço de um Data.
 *  @param stack Endereço da stack.
 */
void MapBlockString(Data *d1, Data *d2, Stack *stack){
    long size = strlen(DataValSTRING(d1));
    Data newStack = CreateDataSTACK(CreateStack(size));
    (DataValSTACK(&newStack))->collec = stack->collec;
    (DataValSTACK(&newStack))->vars = stack->vars;

    for(int i=0; i<size; i++){
        Data temp = CreateDataCHAR((DataValSTRING(d1))[i]);
        Push(temp, DataValSTACK(&newStack));
        eval(DataValSTRING(d2), DataValSTACK(&newStack));
    }
    swapDataFree(d1, &newStack);
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
        MapBlockArray(d1, d2);
}

void Fold(Data *d1, Data *d2, Stack *stack){
    int i = (DataValSTACK(d1))->sp;
    Data first = DataDup(Read(i, DataValSTACK(d1)));
    Push(first, stack);
    for(i--; i>=0; i--){
        Data temp = DataDup(Read(i, DataValSTACK(d1)));
        Push(temp, stack);
        eval(DataValSTRING(d2), stack);
    }
    Data d3 = Pop(stack);
    swapDataFree(d1, &d3);
}

//void SortByString(Data *d1, Data *d2, Stack *stack) {
//
//}

void SortByArray(Data *d1, Data *d2) {
    
}

void SortBy(Data *d1, Data *d2, Stack *stack) {
    SortByArray(d1, d2);
}
