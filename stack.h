#ifndef STACK_H
#define STACK_H

/**
 * @headerfile stack.h
 */
#include <assert.h>
#include <math.h>
#include "data.h"

#define STACK_MAP { \
            {" ", SemArgumentos}, \
            {";", DecrementaSP}, \
            {"_", Underscore},\
            {"\\", Swap},\
            {"@", SwapThree},\
            {"$", DollarSign},\
            {"l", ReadLine},            \
            {"?", ifThenElse},       \
};

#define INTEIRO_MAP { \
{" ", SemArgumentos}, \
{"$", DollarSign},    \
{" ", UmArgumento},\
{"~", notBW},         \
{" ", DoisArgumentos},\
{"&", and},\
{"|", or},\
{"^", xor},\
};

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

Stack *CreateStack(int size);

Data Pop(Stack *stack);
void DecrementaSP(Stack *stack);
void Push(Data operando, Stack *stack);
Data *Read(long deslocamento, Stack *stack);

void PrintStack(Stack *stack);

#endif
