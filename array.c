
#include "array.h"

void range(Data *d1) {
    Data d2 = CreateDataLONG((*(DataValSTACK(d1))).sp + 1);
    swapDataFree(d1, &d2);
}
