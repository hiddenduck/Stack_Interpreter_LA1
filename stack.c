
/**
 * @file
 * Ficheiro relativo à estrutura STACK e às funções correspondentes.
 */
#include "stack.h"

/**
 * \brief Função que devolve uma \a stack padrão
 *
 * sp é igual a -1 para simbolizar uma stack vazia.
 *
 * @return A Stack inicializada na função.
 */
STACK CreateStack() {
    STACK s;
    s.sp = -1;
    return s;
}

/**
 * \brief Função que devolve o elemento na posição sp da \a stack e decrementa sp.
 *
 * @param stack Endereço da \a stack responsável pelo armazenamento.
 * @return Inteiro do tipo long na posição do ponteiro do stack.
 */
long Pop(STACK *stack) {
    return stack->array[(stack->sp)--];
}

/**
 * \brief Função que aumenta o sp da \a stack e coloca um elemento nessa posição.
 *
 * @param val Inteiro do tipo long a colocar na stack.
 * @param stack Endereço da \a stack responsável pelo armazenamento.
 */
void Push(long val, STACK *stack) {
    stack->array[++(stack->sp)] = val;
}

/**