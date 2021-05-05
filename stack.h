#ifndef STACK_H
#define STACK_H

/**
 * @headerfile stack.h
 */

#include "data.h"

/**
 * \brief Tipo de dados que funciona como apontador para uma função operação.
 */
typedef void (*Operation)();

/**
 * \brief Tipo de dados que armazena um simbolo (tipo char) e uma função operação (Operation).
 */
typedef struct {
    /** char responsável pela identificação da operação*/
    char *simbolo;
    /** inteiros responsável pela identificação da máscara */
    int mask;
    /** Apontador para uma função*/
    Operation op;
}OperationMap;

/**
 *  \brief Tipo que guarda todos os mapas.
 */
typedef struct COLLEC {
    /**Mapa de Stacks */
    OperationMap *StackManip;
    /**Mapa aritmético */
    OperationMap *Arit;
    /**Mapa de inteiros */
    OperationMap *Inteiro;
    /**Mapa de strings */
    OperationMap *String;
    /**Mapa de arrays */
    OperationMap *Array;
    /**Mapa de Blocos */
    OperationMap *Block;
} ColectionOperationMaps;

/** forward declaration */
typedef struct data Data;
typedef struct stack Stack;

/**
 * \brief Definição do incremento da stack.
 */
#define INCREMENTO_STACK 50



/**
 * \brief Declaração da estrutura de dados Stack
 */
typedef struct stack {
    /** */
    ColectionOperationMaps collec;
    /** */
    Stack *vars;
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

void Free (Data *data);
void CleanupStack(Stack *stack);
Stack *DupStack(Stack *target);

#endif
