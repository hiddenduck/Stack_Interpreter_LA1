#ifndef DATA_H
#define DATA_H

/**
 * @headerfile data.h
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** \brief Declaração dos Tipos possíveis para os Data. */
typedef enum {CHAR = 1, LONG = 2, DOUBLE = 4, STRING = 8, STACK = 16} Tipo;

/** \brief Declaração dos Tipos possíveis para os Data. */
typedef enum {INTEIRO = CHAR | LONG, NUMERO = LONG | DOUBLE} Mask;
//tratar os arrays como "mini-stacks"
//o value de um array passava a ser Stack*

/**
 * \brief Declaração da estrutura de dados Data.
 */
typedef struct data {
    /** Tipo de dados guardado. */
    Tipo tipo;
    /** Apontador void para o valor guardado na Data. */
    void* value;
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

Data CreateDataLONG(long val);
Data CreateDataDOUBLE(double val);
Data CreateDataCHAR(char val);
Data CreateDataSTRING(char* val);

void DataToDOUBLE(Data *d1);
void DataToLONG(Data *d1);
void DataToCHAR(Data *d1);

Data DataDup(Data *target);

void PrintData(Data *data);
void SwapDataPointers (Data *d1, Data *d2);
#endif
