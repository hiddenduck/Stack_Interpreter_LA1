
#include "string_op.h"

void StringLength(Data *d1) {
    long len = strlen(DataValSTRING(d1));
    Data d2 = CreateDataLONG(len);
    swapDataFree(d1, &d2);
}

void strEqual(Data *d1, Data *d2) {
    GET_BOOL
    Data d3 = CreateDataLONG(!bool);
    swapDataFree(d1, &d3);
}

void strLesser(Data *d1, Data *d2){
    GET_BOOL
    Data d3 = CreateDataLONG(bool<0);
    swapDataFree(d1, &d3);
}

void strGreater(Data *d1, Data *d2){
    GET_BOOL
    Data d3 = CreateDataLONG(bool>0);
    swapDataFree(d1, &d3);
}

void strMult (Data *d1, Data *d2){ // d1 é long obrigatório?
    char *temp = strdup(DataValSTRING(d1));
    for(int i=1; i<*DataValLONG(d2); i++)
        *DataValSTRING(d1) = *strcat(DataValSTRING(d1), temp);
    free(temp);
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

// Funções barracadas
void strRemoveFirst (Data *d1, Stack *stack){ // (
    //tens de criar o Char que vai ser posto na stack
    Data newC = CreateDataCHAR(*DataValSTRING(d1));
    Data d2 = CreateDataSTRING((DataValSTRING(d1)+1)); // tu crias uma auxiliar que é a nova string
    swapDataFree(d1, (&d2)); //trocas as strings
    Push(newC, stack); //metes a char na stack
}

void strRemoveLast (Data *d1, Stack *stack){
    int len = strlen(DataValSTRING(d1)) -1;
    Data newC = CreateDataCHAR(*(DataValSTRING(d1) + len));
    *(DataValSTRING(d1)+len)= '\0';
    Push(newC, stack);
}

void strHashtag (Data *d1, Data *d2){
    int result = -1;
    char *r = strstr(DataValSTRING(d1), DataValSTRING(d2));
    if (r != NULL)
        result = r - DataValSTRING(d1);
    Data d3 = CreateDataLONG(result);
    swapDataFree(d1, &d3);
}

void strEMenor (Data *d1, Data *d2){
    GET_BOOL
    if(bool>0)
        swapData(d1, d2);
}

void strEMaior (Data *d1, Data *d2){
    GET_BOOL
    if(bool<0)
        swapData(d1, d2);
}

void strGetInd (Data *d1, Data *d2){
    Data dvalor = CreateDataCHAR(*(DataValSTRING(d1)+*DataValLONG(d2)));
    swapDataFree(d1, &dvalor);
}

void strConcat(Data *d1, Data *d2){
    char s3[strlen(DataValSTRING(d1))+strlen(DataValSTRING(d2))];
    strcpy(s3, DataValSTRING(d1));
    strcat(s3, DataValSTRING(d2));
    Data d3 = CreateDataSTRING(s3);
    swapData(d1, &d3);
    free(d3.value);
}