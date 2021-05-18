
#include "block.h"

/** \brief Função que executa um bloco.
 *  @param d1 Endereço de um Data.
 *  @param stack Endereço da stack.
 */
void ExecuteBlock(Data *d1, Stack *stack) {
    eval(DataValSTRING(d1), stack);
    Data d2 = Pop(stack);
    swapDataFree(d1, &d2);
}

/** \brief Função que auxilia o MapBlock com arrays.
 *  @param d1 Endereço de um Data.
 *  @param d2 Endereço de um Data.
 *  @param stack Endereço da stack.
 */
void MapBlockArray(Data *d1, Data *d2) {
    Data newStack = CreateDataSTACK(DumpStack(DataValSTACK(d1)));
    //depositar os elementos todos do d1 no newStack com Pop == limpar o d1
    //função dumpStack que deposita uma stack noutra e ta top com Pops
    char blockcopy[strlen(DataValSTRING(d2))+1];
    for (int i = (DataValSTACK(&newStack))->sp; i>=0; i--) {
        strcpy(blockcopy, DataValSTRING(d2));
        Data temp = DataDup(Read(i, DataValSTACK(&newStack)));
        Push(temp, (DataValSTACK(d1)));
        eval(blockcopy, (DataValSTACK(d1)));
    }
    Free(&newStack);
}

/** \brief Função que auxilia o MapBlock com strings.
 *  @param d1 Endereço de um Data.
 *  @param d2 Endereço de um Data.
 *  @param stack Endereço da stack.
 *
 */
void MapBlockString(Data *d1, Data *d2, Stack *stack){
    long size = strlen(DataValSTRING(d1));
    Data newStack = CreateDataSTACK(CreateStack(size));
    (DataValSTACK(&newStack))->collec = stack->collec;
    (DataValSTACK(&newStack))->vars = stack->vars;
    char blockcopy[strlen(DataValSTRING(d2))+1];
    for(int i=0; i<size; i++){
        strcpy(blockcopy, DataValSTRING(d2));
        Data temp = CreateDataCHAR((DataValSTRING(d1))[i]);
        Push(temp, DataValSTACK(&newStack));
        eval(blockcopy, DataValSTACK(&newStack));
    }
    DataToSTRING(&newStack);
    swapDataFree(d1, &newStack);
}

/** \brief Função que realiza o map de blocos.
 *  @param d1 Endereço de um Data.
 *  @param d2 Endereço de um Data.
 *  @param stack Endereço da stack.
 */
void MapBlock(Data *d1, Data *d2, Stack *stack) {
    if(d1->tipo == STRING)
        MapBlockString(d1, d2, stack);
    else
        MapBlockArray(d1, d2);
}

/** \brief Função que realiza o fold de blocos.
 *  @param d1 Endereço de um Data.
 *  @param d2 Endereço de um Data.
 *  @param stack Endereço da stack.
 */
void Fold(Data *d1, Data *d2){
    int i = (DataValSTACK(d1))->sp;
    Data newStack = CreateDataSTACK(DumpStack(DataValSTACK(d1)));

    Data first = DataDup(Read(i, DataValSTACK(&newStack)));
    Push(first, DataValSTACK(d1));
    char blockcopy[strlen(DataValSTRING(d2))+1];
    for(i--; i>=0; i--){
        strcpy(blockcopy, DataValSTRING(d2));
        Data temp = DataDup(Read(i, DataValSTACK(&newStack)));
        Push(temp, DataValSTACK(d1));
        eval(blockcopy, DataValSTACK(d1));
    }
    Free(&newStack);
}

/** \brief Função que cria os indices ordenados a partir de um array que teve o bloco aplicado.
 *  @param stack Endereço do array.
 *  @param ind Endereço do array de indices.
 */
void createIndNUM (Stack *stack, int ind[]){
    int i, j, min, tmp, N = stack->sp;
    for(i=0; i<=N; i++)
        ind[i] = i;
    for(i=0; i<=N; i++){
        min = i;
        for(j=i+1; j<=N; j++)
            if(CompareData( Read(N-ind[j], stack),
                            Read(N-ind[min], stack)) < 0)
                min = j;

        tmp = ind[i]; //swap
        ind[i] = ind[min];
        ind[min] = tmp;
    }
}

/** \brief Função que ordena o array de acordo com o indice.
 *  @param d1 Endereço do array original que foi destruido.
 *  @param d2 Endereço da cópia dos valores do array original.
 *  @param ind Endereço do array com os indices ordenados.
 */
void SortArrayByInd(Data *d1, Data *d2, int ind[]) {
    int len = (DataValSTACK(d2))->sp, i;
    for (i = 0; i<=len; i++)
        Push(DataDup(Read(len-ind[i], (DataValSTACK(d2)))), DataValSTACK(d1));
}

/** \brief Função auxiliar do SortBy que ordena um array de acordo com um bloco.
 *  @param d1 Endereço do array.
 *  @param d2 Endereço do bloco.
 */
void SortByArray(Data *d1, Data *d2) {
    Data temp = DataDup(d1);
    MapBlockArray(&temp, d2); //aqui o temp é o data com os valores a comparar
    int ind[(DataValSTACK(&temp))->sp+1];
    createIndNUM(DataValSTACK(&temp), ind); //função que ordene o temp e coloque essa ordenação no ind
    Free(&temp);

    Data aux = CreateDataSTACK(DumpStack(DataValSTACK(d1)));
    SortArrayByInd(d1, &aux, ind);
    Free(&aux);
    //função que, pelo ind, cria um novo Data que vai substituir o d1
}

/** \brief Função que cria os indices ordenados a partir de uma string que teve o bloco aplicado.
 *  @param stack Endereço da string.
 *  @param ind Endereço da string de indices.
 */
void createIndSTR(char *string, int ind[]) {
    int i, j, min, tmp, N = strlen(string);
    for(i=0; i<N; i++)
        ind[i] = i;
    for(i=0; i<N; i++){
        min = i;
        for(j=i+1; j<N; j++)
            if(string[ind[j]] < string[ind[min]])
                min = j;

        tmp = ind[i]; //swap
        ind[i] = ind[min];
        ind[min] = tmp;
    }
}

/** \brief Função que ordena a string de acordo com o indice.
 *  @param d1 Endereço do array original que foi destruido.
 *  @param aux Endereço da cópia dos valores da string original.
 *  @param ind Endereço da string com os indices ordenados.
 */
void SortStringByInd(Data *d1, char* aux, int ind[]) {
    int len = strlen(DataValSTRING(d1)), i;
    for (i = 0; i<len; i++) {
        aux[i] = (DataValSTRING(d1))[ind[i]];
    }
}

/** \brief Função auxiliar do SortBy que ordena uma string de acordo com um bloco.
 *  @param d1 Endereço da string.
 *  @param d2 Endereço do bloco.
 *  @param stack Endereço da stack.
 */
void SortByString(Data *d1, Data *d2, Stack *stack) {
    Data temp = DataDup(d1);
    MapBlockString(&temp, d2, stack); //aqui o temp é o data com os valores a comparar
    int len = strlen(DataValSTRING(&temp))+1, ind[len];
    createIndSTR(DataValSTRING(&temp), ind); //função que ordene o temp e coloque essa ordenação no ind
    Free(&temp);

    char aux[len];
    SortStringByInd(d1, aux, ind); //pega nos indices e ordena o d1
    Data d3 = CreateDataSTRING(aux);
    swapDataFree(d1, &d3);
}

/** \brief Função que ordena um array/string de acordo com um bloco.
 *  @param d1 Endereço do array/string.
 *  @param d2 Endereço do bloco.
 */
void SortBy(Data *d1, Data *d2, Stack *stack) {
    if(d1->tipo == STACK)
        SortByArray(d1, d2);
    else
        SortByString(d1, d2, stack);
}

/** \brief Função auxiliar do filter que filtra um array.
 *  @param d1 Endereço do array.
 *  @param d2 Endereço do bloco.
 */
void filterArray(Data *d1, Data *d2){
    Data temp = DataDup(d1);
    MapBlockArray(&temp, d2);
    Stack *stack = DumpStack(DataValSTACK(d1));
    for (int i = stack->sp; i>=0; i--) {
        if(GetBoolFromData(Read(i, DataValSTACK(&temp))))
            Push(DataDup(Read(i, stack)), DataValSTACK(d1));
    }
    CleanupStack(DataValSTACK(d1));
    Free(&temp);
}

/** \brief Função auxiliar do filter que filtra uma string.
 *  @param d1 Endereço da string.
 *  @param d2 Endereço do bloco.
 *  @param stack Endereço da stack.
 */
void filterString(Data *d1, Data *d2, Stack *stack){
    Data temp = DataDup(d1);
    MapBlockString(&temp, d2, stack); //o temp é uma string.
    char newString[strlen(DataValSTRING(d1))];
    int w = 0, i, len = strlen(DataValSTRING(&temp));
    for (i = 0; i<= len; i++) {
        if((DataValSTRING(&temp))[i]-48)
            newString[w++] = (DataValSTRING(d1))[i];//queremos construir a string só com os elementos que interessam
    }
    Free(&temp);
    Data d3 = CreateDataSTRING(newString);
    swapDataFree(d1, &d3);
}

/** \brief Função que filtra um array/string.
 *  @param d1 Endereço do array/string.
 *  @param d2 Endereço do bloco.
 *  @param stack Endereço da stack.
 */
void filter(Data *d1, Data *d2, Stack *stack){
    if(d1->tipo == STACK)
        filterArray(d1, d2);
    else
        filterString(d1, d2, stack);
}

/** \brief Função que executa um bloco enquanto o topo da stack for true.
 *  @param d1 Endereço do array/string.
 *  @param stack Endereço da stack.
 */
void While(Data *d1, Stack *stack) {
    char blockcopy[strlen(DataValSTRING(d1))+1];
    Data d2;
    int r;
    do {
        strcpy(blockcopy, DataValSTRING(d1));
        eval(blockcopy, stack);
        d2 = Pop(stack);
        r = GetBoolFromData(&d2);
    }while(r);

    d2 = Pop(stack);
    swapDataFree(d1, &d2);
}
