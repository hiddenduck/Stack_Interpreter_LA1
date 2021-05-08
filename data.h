#ifndef DATA_H
#define DATA_H

/**
 * @headerfile data.h
 */
#include "stack.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <math.h>

/**
 * \brief Definição do tamanho máximo da line de input.
 */
#define MAX_LENGTH_INPUT 10240

/**
 * \brief Declaraçção de um stack.
 */
typedef struct stack Stack;

/**
 * \brief Declaração dos Tipos possíveis para os Data.
 */
typedef enum {
    /**Tipo de um data com o tipo de dado char*/
    CHAR = 1,
    /**Tipo de um data com o tipo de dado long*/
    LONG = 2,
    /**Tipo de um data com o tipo de dado double*/
    DOUBLE = 4,
    /**Tipo de um data com o tipo de dado string*/
    STRING = 8,
    /**Tipo de um data com o tipo de dado Stack */
    STACK = 16,
    /**Tipo de um data com tipo de dado Stack */
    BLOCK = 32
} Tipo;

/**
 * \brief Declaração das masks possíveis para os Tipos.
 */
typedef enum {
    /**Máscara para NUMEROS, ou seja, LONG, CHAR e DOUBLE */
    NUMEROS = (LONG | DOUBLE | CHAR),
    /**Máscara para  INTEIROS, ou seja, LONG e CHAR*/
    INTEIROS = (LONG | CHAR),
    /**Máscara para todos os Tipos */
    ANY = (CHAR | LONG | DOUBLE | STRING | STACK)
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

/**\brief Inicialização da função DataValStack*/
#define DataValSTACK(data) \
    (Stack *) (data)->value

Data CreateDataLONG(long val);
Data CreateDataDOUBLE(double val);
Data CreateDataCHAR(char val);
Data CreateDataSTRING(char* val);
Data CreateDataSTACK(Stack *stack); //não funciona até o stack.h estiver aqui
Data CreateDataBLOCK(char *val);

void DataToDOUBLE(Data *d1);
void DataToLONG(Data *d1);
void DataToCHAR(Data *d1);
void DataToSTRING(Data *d);
char *DataToSTRINGaux (char *buffer, Data *d);

Data DataDup(Data *target);

void PrintData(Data *data);
void swapData (Data *d1, Data *d2);

int GetBoolFromData (Data *d1);

void swapDataFree(Data *d1, Data *d2);
void NullifyData(Data *d1);
int CompareData(Data *d1, Data *d2);

#endif
