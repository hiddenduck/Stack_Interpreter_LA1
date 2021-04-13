
/**
 * @headerfile
 */
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/**
 * \brief Definição do incremento da stack.
 */
#define INCREMENTO_STACK 100

/**
 * \brief São enunciados os tipos possiveis.
 */
typedef enum {CHAR = 1, LONG = 2, DOUBLE = 4, STRING = 8} Tipo;

/**
 * \brief É criado o tipo de dados Data.
 */
typedef struct data {
    Tipo tipo;
    void* value;
}Data;

/**
 * \brief É criado o tipo de dados Stack
 */
typedef struct stack {
    Data *array;
    int size;
    int sp;
}Stack;


Stack *CreateStack();

Data Pop(Stack *stack);
void Push(Data operando, Stack *stack);
Data *Read(long deslocamento, Stack *stack);

void PrintStack(Stack *stack);

/** 
 * \brief Macro que assiste na inicialização das funcões DataVal. 
*/
#define DataValProto(_name, _type)       \
    _type *DataVal##_name(Data *val);    \

DataValProto(LONG, long)
DataValProto(DOUBLE, double)
DataValProto(CHAR, char)
DataValProto(STRING, char)

/** 
 * \brief Macro que assiste na inicialização das funções CreateData. 
*/
#define CreateDataProto(_name, _type)    \
    Data CreateData##_name(_type val);   \

CreateDataProto(LONG, long)
CreateDataProto(DOUBLE, double)
CreateDataProto(CHAR, char)
CreateDataProto(STRING, char *)