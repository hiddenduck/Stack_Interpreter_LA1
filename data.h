#ifndef DATA_H
#define DATA_H

/**
 * @headerfile data.h
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * \brief Declaração dos Tipos possíveis para os Data.
 *
 */
typedef enum {CHAR = 1, LONG = 2, DOUBLE = 4, STRING = 8} Tipo;

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

/**
 * \brief Macro que assiste na Declaração das funcões DataVal.
*/
#define DataValProto(_name, _type)       \
    _type *DataVal##_name(Data *val);    \

/** \brief Declaração da função DataValLONG.*/
DataValProto(LONG, long)
/** \brief Declaração da função DataValDOUBLE.*/
DataValProto(DOUBLE, double)
/** \brief Declaração da função DataValCHAR.*/
DataValProto(CHAR, char)
/** \brief Declaração da função DataValSTRING.*/
DataValProto(STRING, char)

/**
 * \brief Macro que assiste na declaração das funções CreateData.
*/
#define CreateDataProto(_name, _type)    \
    Data CreateData##_name(_type val);   \

/** \brief Declaração da função CreateDataLONG.*/
CreateDataProto(LONG, long)
/** \brief Declaração da função CreateDataDOUBLE.*/
CreateDataProto(DOUBLE, double)
/** \brief Declaração da função CreateDataCHAR.*/
CreateDataProto(CHAR, char)
/** \brief Declaração da função CreateDataSTRING.*/
CreateDataProto(STRING, char *)

void DataToDOUBLE(Data *d1);
void DataToLONG(Data *d1);
void DataToCHAR(Data *d1);

Data DataDup(Data *target);

void PrintData(Data *data);
void SwapDataPointers (Data *d1, Data *d2);
#endif
