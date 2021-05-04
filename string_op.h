
#ifndef STRING_OP_H
#define STRING_OP_H

#include "data.h"


/**
 * \brief Pega um bool através do strcmp de duas strings.
 */
#define GET_BOOL long bool = strcmp(DataValSTRING(d1), DataValSTRING(d2));

void StringLength(Data *d1);
void strEqual(Data *d1, Data *d2);
void strLesser(Data *d1, Data *d2);
void strGreater(Data *d1, Data *d2);
void strMult (Data *d1, Data *d2);
void strBar (Data *d1, Data *d2);
void strAll (Stack *stack);
void strRemoveFirst (Data *d1, Stack *stack);
void strRemoveLast (Data *d1, Stack *stack);
void strHashtag (Data *d1, Data *d2);
void strEMenor (Data *d1, Data *d2);
void strEMaior (Data *d1, Data *d2);
void strGetInd (Data *d1, Data *d2);
void strConcat(Data *d1, Data *d2);
void strGetXStart (Data *d1, Data *d2, Stack *stack);
void strGetXEnd (Data *d1, Data *d2, Stack *stack);
void strWhiteSpace (Data *d1);
void strNewLine (Data *d1);
void barAux(char *str, char *delim, int delim_tamanho, Stack *stack);
void barAux2(char *str, Stack *stack);
#endif //TRING_OP_H
