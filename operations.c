/**
 * @file
 */
#include "operations.h"

/**
 * blanc
*/
#define CreateOpAlgebrica(_name, _op)                                                              \
void _name(Data *d1, Data *d2) {                                                                   \
    switch ((d1->tipo)&(d2->tipo)) {                                                               \
        case LONG:                                                                                 \
            *(DataValLONG(d2)) = ((*(DataValLONG(d1))) _op (*(DataValLONG(d2))));                  \
            break;                                                                                 \
        default:                                                                                   \
            DataToDOUBLE(d2);                                                                      \
            switch(d1->tipo) {                                                                     \
                case LONG:                                                                         \
                    *(DataValDOUBLE(d2)) = ((*(DataValLONG(d1))) _op (*(DataValDOUBLE(d2))));      \
                    break;                                                                         \
                case DOUBLE:                                                                       \
                    *(DataValDOUBLE(d2)) = ((*(DataValDOUBLE(d1))) _op (*(DataValDOUBLE(d2))));    \
                    break;                                                                         \
                default:                                                                           \
                    break;                                                                         \
            }                                                                                      \
        break;                                                                                     \
    }                                                                                              \
}

/** blank */
CreateOpAlgebrica(soma, +)

/** blank */
CreateOpAlgebrica(subtr, -)

/** blank */
CreateOpAlgebrica(mult, *)

/** blank */
CreateOpAlgebrica(divi, /)

/**
 * \brief Função que calcula a potência de base Data d1 e expoente Data d2.
 * @param d1 Endereço da base.
 * @param d2 Endereço do expoente.
 */
void potencia(Data *d1, Data *d2) {
    DataToDOUBLE(d2);
    switch (d1->tipo) {
        case LONG:
            *(DataValDOUBLE(d2)) = (pow(*(DataValLONG(d1)), *(DataValDOUBLE(d2))));
            break;
        case DOUBLE:
            *(DataValDOUBLE(d2)) = (pow(*(DataValDOUBLE(d1)), *(DataValDOUBLE(d2))));
            break;
        default:
            break;
    }
}

/** blank */
#define CreateOpIncremento(_name, _op)    \
void _name(Data *d1) {                    \
    switch (d1->tipo) {                   \
        case LONG:                        \
            (*DataValLONG(d1))_op;        \
            break;                        \
        case DOUBLE:                      \
            (*DataValDOUBLE(d1))_op;      \
            break;                        \
        case CHAR:                        \
            (*DataValCHAR(d1))_op;        \
        default:                          \
            break;                        \
        }                                 \
}

/** blank */
CreateOpIncremento(incre, ++)
/** blank */
CreateOpIncremento(decre, --)

/** blank */
#define CreateOpBitwise(_name, _op)                                  \
void _name(Data *d1, Data *d2) {                                     \
    *(DataValLONG(d2)) = (*DataValLONG(d1) _op *DataValLONG(d2));    \
}

/** blank */
CreateOpBitwise(and, &)
/** blank */
CreateOpBitwise(or, |)
/** blank */
CreateOpBitwise(xor, ^)
/** blank */
CreateOpBitwise(modulo, %)

/**
 * \brief Função que inverte os bits de um certo Data do Tipo LONG.
 * @param d Endereço de um Data do Tipo LONG.
*/
void not(Data *d) {
    *DataValLONG(d) = ~*(DataValLONG(d));
}