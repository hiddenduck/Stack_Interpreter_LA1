
#ifndef STRING_OP_H
#define STRING_OP_H

#include "data.h"

/**
 * \brief Definição do tamanho máximo da line de input.
 */
#define MAX_LENGTH_INPUT 10240

void StringLength(Data *d1);
void strEqual(Data *d1, Data *d2);
void strLesser(Data *d1, Data *d2);
void strGreater(Data *d1, Data *d2);
void strMult (Data *d1, Data *d2);
void strConcat (Data *d1, Data *d2);
void strBar (Data *d1, Data *d2);
void strAll (Stack *stack);
void strRemoveFirst (Data *d1, Stack *stack);
void strRemoveLast (Data *d1, Stack *stack);
void strHashtag (Stack *stack);
#endif //TRING_OP_H
