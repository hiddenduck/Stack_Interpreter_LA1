
#include "string_op.h"

/**
 * \brief Função que faz a lenght de um Data STRING.
 * @param d1 Endereço de um Data.
 */
void StringLength(Data *d1) {
    long len = strlen(DataValSTRING(d1));
    Data d2 = CreateDataLONG(len);
    swapDataFree(d1, &d2);
}

/**
 * \brief Função que verifica se duas strings são iguais.
 * @param d1 Endereço de um Data.
 * @param d2 Endereço de um Data.
 */
void strEqual(Data *d1, Data *d2) {
    GET_BOOL
    Data d3 = CreateDataLONG(!bool);
    swapDataFree(d1, &d3);
}

/**
 * \brief Função que vê se a primeira string é menor que a segunda.
 * @param d1 Endereço de um Data.
 * @param d2 Endereço de um Data.
 */
void strLesser(Data *d1, Data *d2){
    GET_BOOL
    Data d3 = CreateDataLONG(bool<0);
    swapDataFree(d1, &d3);
}

/**
 * \brief Função que vê se a primeira string é maior que a segunda.
 * @param d1 Endereço de um Data.
 * @param d2 Endereço de um Data.
 */
void strGreater(Data *d1, Data *d2){
    GET_BOOL
    Data d3 = CreateDataLONG(bool>0);
    swapDataFree(d1, &d3);
}

/**
 * \brief Função que repete um Data STRING n vezes.
 * @param d1 Endereço de um Data.
 * @param d2 Endereço de um Data.
 */
void strMult (Data *d1, Data *d2){
    char *temp = strdup(DataValSTRING(d1));
    for(int i=1; i<*DataValLONG(d2); i++)
        *DataValSTRING(d1) = *strcat(DataValSTRING(d1), temp);
    free(temp);
}

/**
 * \brief Função que lê todo o input.
 * @param d1 Endereço de um Data.
 * @param d2 Endereço de um Data.
 */
void strAll (Stack *stack){
    char linha[MAX_LENGTH_INPUT];
    char *aux = linha;
    while(fgets(aux, MAX_LENGTH_INPUT, stdin)!=NULL)
        aux += strlen(aux);
    Push(CreateDataSTRING(linha), stack);
}

/**
 * \brief Função que remove o primeiro char de um Data STRING.
 * @param d1 Endereço de um Data.
 * @param d2 Endereço de um Data.
 */
void strRemoveFirst (Data *d1, Stack *stack){ // (
    //tens de criar o Char que vai ser posto na stack
    Data newC = CreateDataCHAR(*DataValSTRING(d1));
    Data d2 = CreateDataSTRING((DataValSTRING(d1)+1)); // tu crias uma auxiliar  strinque é a novag
    Push(d2, stack);
    swapDataFree(d1, &newC); //metes a char na stack
}

/**
 * \brief Função que remove o último char de um Data STRING.
 * @param d1 Endereço de um Data.
 * @param d2 Endereço de um Data.
 */
void strRemoveLast (Data *d1, Stack *stack){
    int len = strlen(DataValSTRING(d1)) -1;
    Data newC = CreateDataCHAR(*(DataValSTRING(d1) + len));
    *(DataValSTRING(d1)+len)= '\0';
    swapData(d1, &newC);
    Push(newC, stack);
}

/**
 * \brief Função que procura uma substring numa string e devolve o índice.
 * @param d1 Endereço de um Data.
 * @param d2 Endereço de um Data.
 */
void strHashtag (Data *d1, Data *d2){
    int result = -1;
    char *r = strstr(DataValSTRING(d1), DataValSTRING(d2));
    if (r != NULL)
        result = r - DataValSTRING(d1);
    Data d3 = CreateDataLONG(result);
    swapDataFree(d1, &d3);
}

/**
 * \brief Função que coloca no topo da stack a menor string entre dois Data.
 * @param d1 Endereço de um Data.
 * @param d2 Endereço de um Data.
 */
void strEMenor (Data *d1, Data *d2){
    GET_BOOL
    if(bool>0)
        swapData(d1, d2);
}

/**
 * \brief Função que coloca no topo da stack a maior string entre dois Data.
 * @param d1 Endereço de um Data.
 * @param d2 Endereço de um Data.
 */
void strEMaior (Data *d1, Data *d2){
    GET_BOOL
    if(bool<0)
        swapData(d1, d2);
}

/**
 * \brief Função que vai buscar um char de acordo com um índice.
 * @param d1 Endereço de um Data.
 * @param d2 Endereço de um Data.
 */
void strGetInd (Data *d1, Data *d2){
    Data dvalor = CreateDataCHAR(*(DataValSTRING(d1)+*DataValLONG(d2)));
    swapDataFree(d1, &dvalor);
}

/**
 * \brief Função que concatena dois Data STRING.
 * @param d1 Endereço de um Data.
 * @param d2 Endereço de um Data.
 */
void strConcat(Data *d1, Data *d2){
    char s3[strlen(DataValSTRING(d1))+strlen(DataValSTRING(d2))];
    strcpy(s3, DataValSTRING(d1));
    strcat(s3, DataValSTRING(d2));
    Data d3 = CreateDataSTRING(s3);
    swapDataFree(d1, &d3);
}

/**
 * \brief Função que vai buscar X chars no inicio de um Data STRING.
 * @param d1 Endereço de um Data.
 * @param d2 Endereço de um Data.
 */
void strGetXStart (Data *d1, Data *d2, Stack *stack){
    int i;
    for(i = 0; i<*DataValLONG(d2)-1; i++) {
        Data newC = CreateDataCHAR((DataValSTRING(d1))[i]);
        Push(newC, stack);
    }
    Data d3 = CreateDataCHAR((DataValSTRING(d1))[i]);
    swapDataFree(d1, &d3);
}

/**
 * \brief Função que vai buscar os X chars no fim de um Data STRING.
 * @param d1 Endereço de um Data.
 * @param d2 Endereço de um Data.
 */
void strGetXEnd (Data *d1, Data *d2, Stack *stack){
    long len = strlen(DataValSTRING(d1)), i;
    for (i = len - *DataValLONG(d2); i<len-1; i++)
        Push(CreateDataCHAR((DataValSTRING(d1))[i]), stack);
    Data d3 = CreateDataCHAR((DataValSTRING(d1))[i]);
    swapDataFree(d1, &d3);
}

void barAux(char *str, char *delim, int delim_tamanho, Stack *stack){
    char *r = strstr(str, delim);
    while(r!=NULL && *str!='\0'){
        str[r-str] = '\0';
        Push(CreateDataSTRING(str), stack);
        str = str + (r-str) + delim_tamanho;
        r = strstr(str, delim);
    }
    if(strlen(str)!=0)
        Push(CreateDataSTRING(str), stack);
}

void barAux2(char *str, Stack *stack){
    for(int i=0; str[i]!='\0'; i++)
        Push(CreateDataCHAR(str[i]), stack);
}

/**
 * \brief Função que procura uma substring numa string e um array de strings.
 * @param d1 Endereço de um Data.
 * @param d2 Endereço de um Data.
 */
void strBar (Data *d1, Data *d2){
    Stack *new = CreateStack(10);
    char *s = strdup(DataValSTRING(d1));
    char *delim = strdup(DataValSTRING(d2));
    if(strlen(DataValSTRING(d2))!=0)
        barAux(s, delim, strlen(delim), new);
    else
        barAux2(s, new);
    Data d3 = CreateDataSTACK(new);
    swapDataFree(d1, &d3);
    free(delim);
    free(s);
}

/**
 * \brief Função que procura espaços numa string e um array de strings.
 * @param d1 Endereço de um Data.
 * @param d2 Endereço de um Data.
 */
void strWhiteSpace (Data *d1){
    Data str = CreateDataSTRING(" ");
    strBar(d1, &str);
}

/**
 * \brief Função que procura new numa string e um array de strings.
 * @param d1 Endereço de um Data.
 * @param d2 Endereço de um Data.
 */
void strNewLine (Data *d1){
    Data str = CreateDataSTRING("\n");
    strBar(d1, &str);
}

