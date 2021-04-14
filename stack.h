
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
 * \brief Declaração dos Tipos possíveis para os Data.
 */
typedef enum {CHAR = 1, LONG = 2, DOUBLE = 4, STRING = 8} Tipo;

/**
 * \brief Declaração da estrutura de dados Data.
 */
typedef struct data {
    /** Tipo de dados guardado. */
    Tipo tipo;
    /** Apontador void para o valor guardado na Data. */
    void* value;
}Data;

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
void Push(Data operando, Stack *stack);
Data *Read(long deslocamento, Stack *stack);

void PrintStack(Stack *stack);

/** 
 * \brief Macro que assiste na Declaração das funcões DataVal.
*/
#define DataValProto(_name, _type)       \
    _type *DataVal##_name(Data *val);    \

/** Declaração da função DataValLONG.*/
DataValProto(LONG, long)
/** Declaração da função DataValDOUBLE.*/
DataValProto(DOUBLE, double)
/** Declaração da função DataValCHAR.*/
DataValProto(CHAR, char)
/** Declaração da função DataValSTRING.*/
DataValProto(STRING, char)

/** 
 * \brief Macro que assiste na declaração das funções CreateData.
*/
#define CreateDataProto(_name, _type)    \
    Data CreateData##_name(_type val);   \

/** Declaração da função CreateDataLONG.*/
CreateDataProto(LONG, long)
/** Declaração da função CreateDataDOUBLE.*/
CreateDataProto(DOUBLE, double)
/** Declaração da função CreateDataCHAR.*/
CreateDataProto(CHAR, char)
/** Declaração da função CreateDataSTRING.*/
CreateDataProto(STRING, char *)

void DataToDOUBLE(Data *d1);
void DataToLONG(Data *d1);

Data DataDup(Data *target);