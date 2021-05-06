
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

/** \brief Função que realiza o map de blocos.
 *  @param d1 Endereço de um data.
 *  @param d2 Endereço de um data.
 *  @param stack Endereço da stack.
 */
void MapBlock(Data *d1, Data *d2, Stack *stack) {
    int i = (DataValSTACK(d1))->sp;
    for (; i>=0; i--) {
        Data temp = DataDup(Read(i, DataValSTACK(d1)));
        Push(temp, stack);
        eval(DataValSTRING(d2), stack);
    }
    Data d3 = Pop(stack);
    swapDataFree(d1, &d3);
}
