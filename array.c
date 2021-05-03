
#include "array.h"

/**
 *  \brief Função que calcula o tamanho de um array.
 */
void range(Data *d1) {
    Data d2 = CreateDataLONG((*(DataValSTACK(d1))).sp + 1);
    swapDataFree(d1, &d2);
}
