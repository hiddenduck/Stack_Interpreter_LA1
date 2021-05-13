/**
 * @headerfile operations.h
 */
#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "data.h"
#include "stack.h"
#include "string_op.h"
#include "logic.h"
#include "array.h"
#include "block.h"

/**
 * \brief Array com todas as operações implementadas.
 */
#define ARIT_MAP {{" ", 0, HandleOne},          \
                {"(", NUMEROS, decre},\
                {")", NUMEROS, incre},\
                {" ", 0, HandleTwo},   \
                {"e<", NUMEROS, LesserBetweenTwo},   \
                {"e>", NUMEROS, GreaterBetweenTwo},   \
                {"=", NUMEROS, equals},           \
                {"<", NUMEROS, lesser},               \
                {">", NUMEROS, greater},\
                {"+", NUMEROS, soma},\
                {"-", NUMEROS, subtr},\
                {"*", NUMEROS, mult},\
                {"/", NUMEROS, divi},\
                {"%", NUMEROS, modulo},\
                {"#", NUMEROS, potencia},\
                {0, 0, NULL} \
                } \


/**
 *  \brief Array com todas as operações implementadas.
 */
#define STACK_MAP { \
{" ", 0, HandleNoArgs}, \
{"p", ANY , PrintTop}, \
{";", ANY, DecrementaSP}, \
{"_", ANY, Underscore},\
{"\\", ANY, Swap},\
{"@", ANY, SwapThree},\
{"l", ANY, ReadLine},            \
{"t", ANY, strAll}, \
{"?", ANY, ifThenElse},  \
{" ", 0, HandleOne}, \
{"!", ANY, notLG},\
{"c", ANY, DataToCHAR},\
{"i", ANY, DataToLONG},\
{"f", ANY, DataToDOUBLE}, \
{"s", ANY, DataToSTRING},\
{" ", 0, HandleTwo},\
{"e&", ANY, andWithShortcut},     \
{"e|", ANY, orWithShortcut},      \
{" ", 0, HandleTwoDiff}, \
{0, 0, NULL}\
} \

/**
 *  \brief Array com todas as operações implementadas.
 */
#define INTEIRO_MAP { \
{" ", 0, HandleNoArgs}, \
{" ", 0, HandleOne},  \
{",", INTEIROS, range},\
{"$", INTEIROS, DollarSign},    \
{"~", INTEIROS, notBW},         \
{" ", 0, HandleTwo},\
{"&", INTEIROS, and},\
{"|", INTEIROS, or},\
{"^", INTEIROS, xor},           \
{" ", 0, HandleTwoDiff}, \
{"<", (STRING | LONG), strGetXStart},   \
{">", (STRING | LONG), strGetXEnd},     \
{"=", (STRING | LONG), strGetInd}, \
{0, 0, NULL}\
} \

/**
 * \brief Array com todas as operações implementadas.
 */
#define STRING_MAP {{" ", 0, HandleOne}, \
                    {",", STRING, StringLength}, \
                    {"(", STRING, strRemoveFirst}, \
                    {")", STRING, strRemoveLast},\
                    {"S/", STRING, strWhiteSpace}, \
                    {"N/", STRING, strNewLine},\
                    {" ", 0, HandleTwo},\
                    {"=", STRING, strEqual}, \
                    {"<", STRING, strLesser},\
                    {">", STRING, strGreater},\
                    {"*", (STRING | INTEIROS), strMult}, \
                    {"+", (STRING | CHAR), strConcat}, \
                    {"/", STRING, strBar}, \
                    {"#", STRING | CHAR, strHashtag}, \
                    {"e<", STRING, strEMenor},  \
                    {"e>", STRING, strEMaior},  \
                    {"+", STRING, strConcat},    \
                    {0, 0, NULL}\
} \

/**
 * \brief Array com todas as operações implementadas.
 */
#define ARRAY_MAP   {{" ", 0, HandleOne}, \
                    {",", STACK, ArrayLength},\
                    {"~", STACK, til},     \
                    {"(", STACK, arrayRemoveFirst}, \
                    {")", STACK, arrayRemoveLast},\
                    {" ", 0, HandleTwoDiff}, \
                    {"*", (STACK | LONG), multArray}, \
                    {"<", (STACK | LONG), arrayGetXStart}, \
                    {">", (STACK | LONG), arrayGetXEnd},\
                    {"=", (STACK | LONG), arrayGetInd},\
                    {" ", 0, HandleTwo}, \
                    {"+", ANY, concatArray}, \
                    {0, 0, NULL} \
} \

/**
 * \brief Array com todas as operações implementadas.
 */
#define BLOCK_MAP {{" ", 0, HandleOne}, \
{"~",BLOCK, ExecuteBlock},              \
{"w",BLOCK, While},              \
{" ", 0, HandleTwoDiff},                \
{"*", (BLOCK | STACK), Fold}, \
{" ", 0, HandleTwo},                    \
{",", (BLOCK | STACK | STRING), filter}, \
{"$", (BLOCK | STACK | STRING), SortBy},\
{"%", (BLOCK | STACK | STRING), MapBlock},\
{0,0,NULL}}\

void DoisArgumentos(Operation operation, Stack *stack);
void UmArgumento(Operation operation, Stack *stack);
void SemArgumentos(Operation operation, Stack *stack);

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
void DollarSign(Data *d1, Stack *stack);
void ReadLine(Stack *stack);
int TwoPoints (Stack *stack, Stack *vars, char token);

#endif
