/**
 * @headerfile
 */
#include "stack.h"

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
void DoisArgumentos(void (*fun)(Data *d1, Data *d2), Stack *stack);
void UmArgumento(void (*fun)(Data *d1), Stack *stack);
