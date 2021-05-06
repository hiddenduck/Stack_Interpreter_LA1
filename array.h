
#ifndef ARRAY_H
#define ARRAY_H
#include "data.h"

void ArrayLength(Data *d1);
void range(Data *d1, Stack *stack);
void til(Data *d1, Stack *stack);
void concatArray(Data *d1, Data *d2);
void multArray(Data *d1, Data *d2);
void arrayRemoveFirst (Data *d1, Stack *stack);
void arrayRemoveLast (Data *d1, Stack *stack);
void arrayGetInd (Data *d1, Data *d2);
void arrayGetXStart (Data *d1, Data *d2, Stack *stack);
void arrayGetXEnd (Data *d1, Data *d2, Stack *stack);
#endif //ARRAY_H
