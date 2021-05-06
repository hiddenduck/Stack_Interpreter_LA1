#ifndef BLOCK_H
#define BLOCK_H

#include "parser.h"

void ExecuteBlock(Data *d1, Stack *stack);
void MapBlock(Data *d1, Data *d2, Stack *stack);
void MapBlockArray(Data *d1, Data *d2, Stack *stack);
void MapBlockString(Data *d1, Data *d2, Stack *stack);
void Fold(Data *d1, Data *d2, Stack *stack);

#endif //PROJETOLAI_BLOCK_H