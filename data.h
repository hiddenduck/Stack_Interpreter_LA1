#ifndef DATA_H
#define DATA_H

/**
 * @headerfile data.h
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

/**
 * \brief Declaração dos Tipos possíveis para os Data.
 */
typedef enum {
    /** Tipo para Data com o valor char*/
    CHAR = 1,
    /** Tipo para Data com o valor long*/
    LONG = 2,
    /** Tipo para Data com o valor double*/
    DOUBLE = 4,
    /** Tipo para Data com o valor string*/
    STRING = 8,
    /** Tipo para Data com o valor stack*/
    STACK = 16
} Tipo;

/** \brief Declaração dos Tipos possíveis para os Data. */
typedef enum {
    /** Máscara com o valor char ou long*/
    INTEIRO = CHAR | LONG,
    /** Máscara com o valor long ou double*/
    NUMERO = LONG | DOUBLE,
    /** */
    TEXTO = CHAR | STRING
} Mask;
//tratar os arrays como "mini-stacks"
//o value de um array passava a ser Stack*

/**
 * \brief Declaração da estrutura de dados Data.
 */
typedef struct data {
    /** Apontador void para o valor guardado na Data. */
    void* value;
    /** Tipo de dados guardado. */
    Tipo tipo;
}Data;

/**\brief Inicialização da função DataValCHAR.*/
#define DataValCHAR(data) \
    (char *) (data)->value

/**\brief Inicialização da função DataValLONG.*/
#define DataValLONG(data) \
    (long *) (data)->value

/**\brief Inicialização da função DataValDOUBLE.*/
#define DataValDOUBLE(data) \
    (double *) (data)->value

/** \brief Inicialização da função DataValSTRING.*/
#define DataValSTRING(data) \
    (char *) (data)->value

/** */
#define DataValSTACK(data) \
    (Stack *) (data)->value

Data CreateDataLONG(long val);
Data CreateDataDOUBLE(double val);
Data CreateDataCHAR(char val);
Data CreateDataSTRING(char* val);
Data CreateDataSTACK(Stack *stack);

void DataToDOUBLE(Data *d1);
void DataToLONG(Data *d1);
void DataToCHAR(Data *d1);

Data DataDup(Data *target);

void PrintData(Data *data);
void SwapDataPointers (Data *d1, Data *d2);

int GetBoolFromData (Data *d1);
#endif
