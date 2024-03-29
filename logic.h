#ifndef LOGIC_H
#define LOGIC_H

#include "data.h"

/** \brief Mapa logico */
#define LOGIC_MAP {}

void equals(Data *d1, Data *d2);
void lesser(Data *d1, Data *d2);
void greater(Data *d1, Data *d2);
void notLG(Data *d1);
void ifThenElse(Stack *stack);
void LesserBetweenTwo(Data *d1, Data *d2);
void GreaterBetweenTwo(Data *d1, Data *d2);
void andWithShortcut(Data *d1, Data *d2);
void orWithShortcut(Data *d1, Data *d2);

#endif
