
#include "block.h"

void ExecuteBlock(Data *d1, Stack *stack) {
    eval(DataValSTRING(d1), stack);
}
