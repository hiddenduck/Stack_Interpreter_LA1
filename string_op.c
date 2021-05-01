
#include "string_op.h"

void StringLength(Data *d1) {
    long len = strlen(DataValSTRING(d1));
    Data d2 = CreateDataLONG(len);
    free(d1->value);
    swapData(d1, &d2);
}

void strComp(Data *d1, Data *d2) {
    long bool = strcmp(DataValSTRING(d1), DataValSTRING(d2));
    Data d3 = CreateDataLONG(bool);
    free(d1->value);
    swapData(d1, &d3);
}
