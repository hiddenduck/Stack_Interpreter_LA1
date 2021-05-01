
#include "string_op.h"

void StringLength(Data *d1) {
    long len = strlen(DataValSTRING(d1));
    Data d2 = CreateDataLONG(len);
    free(d1->value);
    swapData(d1, &d2);
}

void strEqual(Data *d1, Data *d2) {
    long bool = strcmp(DataValSTRING(d1), DataValSTRING(d2));
    Data d3 = CreateDataLONG(!bool);
    free(d1->value);
    swapData(d1, &d3);
}

void strLesser(Data *d1, Data *d2){
    long bool = strcmp(DataValSTRING(d1), DataValSTRING(d2));
    Data d3 = CreateDataLONG(!(bool+1));
    free(d1->value);
    swapData(d1, &d3);
}

void strGreater(Data *d1, Data *d2){
    long bool = strcmp(DataValSTRING(d1), DataValSTRING(d2));
    Data d3 = CreateDataLONG(!(bool-1));
    free(d1->value);
    swapData(d1, &d3);
}

void strMult (Data *d1, Data *d2){ // d1 é long obrigatório?
    char *temp = strdup(DataValSTRING(d1));
    for(int i=1; i<*DataValLONG(d2); i++)
        *DataValSTRING(d1) = *strcat(DataValSTRING(d1), temp);
    free(temp);
}

void strConcat (Data *d1, Data *d2){ //manhoso?
    *DataValSTRING(d1) = *strcat(DataValSTRING(d1), DataValSTRING(d2));
}

void strBar (Data *d1, Data *d2){ // É mAU?
    char *new = strstr(DataValSTRING(d1), DataValSTRING(d2));
    *new = '\0';
}

// não temos certeza disto mas parece cool, CRTL+D no linux para parar, CRTL+Z no windows
// metemos o max_lenght_input no string_op.h
void strAll (Stack *stack){
    char linha[MAX_LENGTH_INPUT];
    while(fgets(linha, MAX_LENGTH_INPUT, stdin)!=NULL);
    Push(CreateDataSTRING(linha), stack);
}
