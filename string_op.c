
#include "string_op.h"

void StringLength(Data *d1) {
    long len = strlen(DataValSTRING(d1));
    Data d2 = CreateDataLONG(len);
    free(d1->value);
    swapData(d1, &d2);
}
