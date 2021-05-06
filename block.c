
#include "block.h"

/** \brief Função que executa um bloco.
 *  @param d1 Endereço de um data.
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
    for (int i = (DataValSTACK(&newStack))->sp; i>=0; i--) {
        Data temp = DataDup(Read(i, DataValSTACK(&newStack)));
        Push(temp, (DataValSTACK(d1)));
        eval(DataValSTRING(d2), (DataValSTACK(d1)));
    }
    Free(&newStack);
    //free ao newStack de alguma maneira
    //se o newStack fosse um Data talvez ajudasse
}

/** \brief Função que auxilia o MapBlock com strings.
 *  @param d1 Endereço de um Data.
 *  @param d2 Endereço de um Data.
 *  @param stack Endereço da stack.
 */
void MapBlockString(Data *d1, Data *d2, Stack *stack){
    long size = strlen(DataValSTRING(d1));
    Data newStack = CreateDataSTACK(CreateStack(size));
    (DataValSTACK(&newStack))->collec = stack->collec;
    (DataValSTACK(&newStack))->vars = stack->vars;

    for(int i=0; i<size; i++){
        Data temp = CreateDataCHAR((DataValSTRING(d1))[i]);
        Push(temp, DataValSTACK(&newStack));
        eval(DataValSTRING(d2), DataValSTACK(&newStack));
    }
    swapDataFree(d1, &newStack);
}

/** \brief Função que realiza o map de blocos.
 *  @param d1 Endereço de um data.
 *  @param d2 Endereço de um data.
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
void Fold(Data *d1, Data *d2, Stack *stack){
    int i = (DataValSTACK(d1))->sp;
    Data first = DataDup(Read(i, DataValSTACK(d1)));
    Push(first, stack);
    for(i--; i>=0; i--){
        Data temp = DataDup(Read(i, DataValSTACK(d1)));
        Push(temp, stack);
        eval(DataValSTRING(d2), stack);
    }
    Data d3 = Pop(stack);
    swapDataFree(d1, &d3);
}

//void SortByString(Data *d1, Data *d2, Stack *stack) {
//
//}

void createInd (Stack *stack, int ind[]){
    int i, j, min, tmp, N = stack->sp;
    for(i=0; i<=N; i++)
        ind[i] = i;

    for(i=0; i<=N; i++){
        min = i;
        for(j=i+1; j<=N; j++)
            if(CompareDataNUMERO(Read(N-ind[j], stack),
                                 Read(N-ind[min], stack)) < 0)
                min = j;

        tmp = ind[i]; //swap
        ind[i] = ind[min];
        ind[min] = tmp;

        for(int k = 0; k<N+1;k++) {
            printf("%d ", ind[k]);
        }
        putchar('\n');
    }
}

/**
 *
 * @param d1
 * @param ind
 *
 *  [ 86 105 118 97 32 111 32 80 111 114 116 111 33 ]
 *  ind[ 4 6 12 7 0 3 1 5 8 11 9 10 2 ]
 *  [ 32 32 33
 */
void SortArrayByInd(Data *d1, int ind[]) {
    Stack *stack = DataValSTACK(d1);
    int len = (DataValSTACK(d1))->sp, i;
    for(i = 0; i<len+1;i++) {
        printf("%d ", ind[i]);
    }
    putchar('\n');
    for(i = 0; i<len+1;i++) {
        printf("%d ", ind[i]);
    }
    putchar('\n');
    for (i = 0; i<=len; i++) {
            for(int j = 0; j<len+1;j++) {
                printf("%d ", ind[j]);
            }
            putchar('\n');
            swapData(Read(len-i, stack), Read(len-ind[i], stack));
            int tmp = ind[i]; //swap
            ind[i] = ind[tmp];
            ind[tmp] = tmp;

    }
    for(i = 0; i<len+1;i++) {
        printf("%d ", ind[i]);
    }
    putchar('\n');
}

void SortByArray(Data *d1, Data *d2) {
    Data temp = DataDup(d1);
    MapBlockArray(&temp, d2); //aqui o temp é o data com os valores a comparar
    int ind[(DataValSTACK(&temp))->sp+1];
    createInd(DataValSTACK(&temp), ind); //função que ordene o temp e coloque essa ordenação no ind
    for(int i = 0; i<(DataValSTACK(&temp))->sp+1;i++) {
        printf("%d ", ind[i]);
    }
    putchar('\n');
    Free(&temp);
    SortArrayByInd(d1, ind);
    //função que, pelo ind, cria um novo Data que vai substituir o d1
}

void SortBy(Data *d1, Data *d2, Stack *stack) {
    SortByArray(d1, d2);
}
