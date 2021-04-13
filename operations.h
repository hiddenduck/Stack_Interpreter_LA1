/**
 * @headerfile
 */
#include "stack.h"

/** 
 * \brief Macro que assiste na inicialização das Funções CreateOpAlgebrica.
 */
#define CreateOpAlgebricaProto(_name) \
void _name(Data *d1, Data *d2);

CreateOpAlgebricaProto(soma)
CreateOpAlgebricaProto(subtr)
CreateOpAlgebricaProto(mult)
CreateOpAlgebricaProto(divi)

void potencia(Data *d1, Data *d2);

/** 
 * \brief Macro que assiste na inicialização das Funções CreateOpIncremento.
 */
#define CreateOpIncrementoProto(_name) \
void _name(Data *d1);

CreateOpIncrementoProto(incre)
CreateOpIncrementoProto(decre)

/** 
 *  \brief Macro que assiste na inicialização das Funções CreateOpBitwise.
 */
#define CreateOpBitwiseProto(_name) \
void _name(Data *d1, Data *d2);

CreateOpBitwiseProto(and)
CreateOpBitwiseProto(or)
CreateOpBitwiseProto(xor)
CreateOpBitwiseProto(modulo)
void not(Data *d1);