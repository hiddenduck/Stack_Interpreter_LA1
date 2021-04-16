
/**
 * @headerfile
 */
#include <assert.h>
#include <math.h>
#include <stdarg.h>
#include "data.h"

/**
 * \brief Definição do incremento da stack.
 */
#define INCREMENTO_STACK 100

/**
 * \brief Declaração da estrutura de dados Stack
 */
typedef struct stack {
    /** Array de Data */
    Data *array;
    /** Tamanho do array da Stack */
    int size;
    /** Apontador para o último elemento da Stack*/
    int sp;
}Stack;

Stack *CreateStack();

Data Pop(Stack *stack);
void PopN(Stack *stack, int nData, ...);
void Push(Data data, Stack *stack);
void PushN(Stack *stack, int nData, ...);
Data *Read(long deslocamento, Stack *stack);

void PrintStack(Stack *stack);
