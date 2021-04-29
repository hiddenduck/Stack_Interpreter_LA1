/**
 * @headerfile operations.h
 */
#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "logic.h"
#include "array.h"
#include "stringOp.h"

/**
 * \brief Definição do tamanho máximo da line de input.
 */
#define MAX_LENGTH_INPUT 10240

/**
 * \brief Array com todas as operações implementadas
 */
#define OPERATION_MAP {{" ", DefaultOperate}, \
                {";", DecrementaSP}, \
                {"_", Underscore},\
                {"\\", Swap},\
                {"@", SwapThree},\
                {"$", DollarSign},\
                {"l", ReadLine},            \
                {"?", ifThenElse},           \
                {" ", UmArgumento},          \
                {"!", notLG},\
                {"(", decre},\
                {")", incre},\
                {"~", notBW},\
                {"c", DataToCHAR},\
                {"i", DataToLONG},\
                {"f", DataToDOUBLE},\
                {" ", DoisArgumentos},   \
                {"e<", LesserBetweenTwo},   \
                {"e>", GreaterBetweenTwo},   \
                {"e&", andWithShortcut},     \
                {"e|", orWithShortcut},      \
                {"=", equals},               \
                {"<", lesser},               \
                {">", greater},\
                {"+", soma},\
                {"-", subtr},\
                {"*", mult},\
                {"/", divi},\
                {"%", modulo},\
                {"#", potencia},\
                {"&", and},\
                {"|", or},\
                {"^", xor},\
                {0, NULL} \
                }

/**
 * \brief Tipo de dados que funciona como apontador para uma função operação.
 */
typedef void (*Operation)();

/**
 *
 */
typedef int (*Handle)();

/**
 * \brief Tipo de dados que armazena um simbolo (tipo char) e uma função operação (Operation).
 */
typedef struct OPMAP{
    /** char responsável pela identificação da operação*/
    char *simbolo;
    /** Apontador para uma função*/
    Operation op;
} OperationMap;

/**
 *
 */
typedef struct COLLEC {
    /** */
    OperationMap *Arit;
    /** */
    OperationMap *Logic;
    /** */
    OperationMap *String;
    /** */
    OperationMap *Array;
} ColectionOperationMaps;

void DoisArgumentos(Operation operation, Stack *stack, int *res, Handle handle);
void UmArgumento(Operation operation, Stack *stack, int *res, Handle handle);
void DefaultOperate(Operation operation, Stack *stack, int *res, Handle handle);

void soma(Data *d1, Data *d2);
void subtr(Data *d1, Data *d2);
void mult(Data *d1, Data *d2);
void divi(Data *d1, Data *d2);

void incre(Data *d1);
void decre(Data *d1);

void and(Data *d1, Data *d2);
void or(Data *d1, Data *d2);
void xor(Data *d1, Data *d2);
void modulo(Data *d1, Data *d2);

void notBW(Data *d);
void potencia(Data *d1, Data *d2);

void Underscore(Stack *stack);
void Swap(Stack *stack);
void SwapThree(Stack *stack);
void DollarSign(Stack *stack);
void ReadLine(Stack *stack);
int TwoPoints (Stack *stack, Stack *vars, char token);

#endif
