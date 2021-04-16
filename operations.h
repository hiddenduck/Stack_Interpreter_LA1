/**
 * @headerfile
 */
#include "stack.h"

/**
 * \brief Definição do tamanho máximo da line de input.
 */
#define MAX_LENGTH_INPUT 10240

typedef void (*Operation)();

/**
 *
 */
typedef struct {
    char simbolo;
    Operation op;
}OperationMap;

void DoisArgumentos(Operation operation, Stack *stack);
void UmArgumento(Operation operation, Stack *stack);
void SemArgumentos(Operation operation, Stack *stack);

/** 
 * \brief Macro que assiste na declaração das Funções CreateOpAlgebrica.
 */
#define CreateOpAlgebricaProto(_name) \
void _name(Data *d1, Data *d2);

/** Declaração da função soma.*/
CreateOpAlgebricaProto(soma)
/** Declaração da função subtr.*/
CreateOpAlgebricaProto(subtr)
/** Declaração da função mult.*/
CreateOpAlgebricaProto(mult)
/** Declaração da função divi.*/
CreateOpAlgebricaProto(divi)

/** 
 * \brief Macro que assiste na declaração das Funções CreateOpIncremento.
 */
#define CreateOpIncrementoProto(_name) \
void _name(Data *d1);

/** Declaração da função incre.*/
CreateOpIncrementoProto(incre)
/** Declaração da função decre.*/
CreateOpIncrementoProto(decre)

/** 
 *  \brief Macro que assiste na declaração das Funções CreateOpBitwise.
 */
#define CreateOpBitwiseProto(_name) \
void _name(Data *d1, Data *d2);

/** Declaração da função and.*/
CreateOpBitwiseProto(and)
/** Declaração da função or.*/
CreateOpBitwiseProto(or)
/** Declaração da função xor.*/
CreateOpBitwiseProto(xor)
/** Declaração da função modulo.*/
CreateOpBitwiseProto(modulo)

void not(Data *d1);
void potencia(Data *d1, Data *d2);


/*Funções sem Macros coitadinhas*/
void Underscore(Stack *stack);
void Swap(Stack *stack);
void SwapThree(Stack *stack);
void DollarSign(Stack *stack);
void ReadLine(Stack *stack);
