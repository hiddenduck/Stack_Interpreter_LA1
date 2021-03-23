
/**
 * @file
 */
#include <stdio.h>

/**
 * \brief Tamanho máximo do array de uma stack.
 */
#define MAX_LENGTH 10240

/**
 * \brief Estrutura STACK para representar uma stack.
 * Definida por um array do tipo long e por um inteiro sp.
 */
typedef struct {
    /**
     * \param array Array do tipo long de tamanho MAX_LENGTH para armazenar.
     */
    long array[MAX_LENGTH];
    /**
     * \param sp Inteiro que representa o indíce do último elemento da stack.
     */
    int sp;
}STACK;

STACK CreateStack();

long Pop(STACK *stack);

void Push(long val, STACK *stack);

void PrintStack(STACK *stack);