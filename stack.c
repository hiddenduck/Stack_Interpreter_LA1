
/**
 * @file stack.c
 * Ficheiro relativo à estrutura Stack e às funções correspondentes.
 */
#include "stack.h"

/**
 * \brief Função que devolve uma \a stack padrão
 *
 * sp é igual a -1 para simbolizar uma stack vazia.
 *
 * @return A Stack inicializada na função.
 */
Stack *CreateStack(int size) {
    Stack *s = (Stack *) malloc(sizeof(Stack));
    assert(s != NULL);
    s->size = size;
    s->sp = -1;
    s->array = (Data *) calloc(s->size, sizeof(Data));
    return s;
}

/**
 * \brief Função que devolve o elemento na posição sp da \a stack e decrementa sp.
 *
 * @param stack Endereço da \a stack responsável pelo armazenamento.
 * @return Devolve o elemento do tipo Data na última posiçao.
 */
Data Pop(Stack *stack) {
    return stack->array[(stack->sp)--];
}

/**
 * \brief Função que decrementa o sp e liberta o Data que o stack pointer estava a apontar.
 * @param stack Endereço da \a stack responsável pelo armazenamento.
 */
void DecrementaSP(Stack *stack) {
    if (stack->sp != -1)
        free(stack->array[(stack->sp)--].value);
}

/**
 * \brief Função que aumenta o sp da \a stack e coloca um elemento nessa posição.
 *
 * @param data Elemento do tipo Data a colocar na \a stack.
 * @param stack Endereço da \a stack responsável pelo armazenamento.
 */
void Push(Data data, Stack *stack) {
    if(stack->size == (stack->sp)-1) {
        stack->size +=INCREMENTO_STACK;
        stack->array = (Data *) realloc(stack->array, stack->size * sizeof(Data));
    }
    stack->sp++;
    stack->array[(stack->sp)] = data;
}

/**
 * \brief Função que lê um elemento a uma certa distância do sp.
 *
 * @param deslocamento Distância em relação ao sp.
 * @param stack Endereço da \a stack responsável pelo armazenamento.
 * @return Devolve um elemento do tipo Data.
 */
Data *Read(long deslocamento, Stack *stack) {
    Data *val = &stack->array[stack->sp-deslocamento];
    return val;
}

/**
 * \brief Função que imprime todos os elementos da \a stack até ao elemento na posição sp.
 *
 * @param stack Endereço da \a stack responsável pelo armazenamento.
 */
void PrintStack(Stack *stack) {
    for (int i = 0 ; i <= stack -> sp; i++){
        PrintData(&stack->array[i]);
    }
    putchar('\n');
}

/**
 *
 * @param stack
 * @return
 */
Data CreateDataSTACK(Stack *stack) {
    Data op = {stack, STACK};
    return op;
}
