/**
 * @file
 */
#include "operations.h"

/**
 * \brief Macro que assiste na inicialização das funções algébricas.
 * Este tipo de função recebe dois Data,
 * converte-os para o tipo necessário,
 * efetua a operação algébrica respetiva,
 * e guarda o resultado no segundo Data.
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

/** Inicialização da função algorítmica soma. */
CreateOpAlgebrica(soma, +)
/** Inicialização da função algorítmica subtr. */
CreateOpAlgebrica(subtr, -)
/** Inicialização da função algorítmica mult. */
CreateOpAlgebrica(mult, *)
/** Inicialização da função algorítmica divi. */
CreateOpAlgebrica(divi, /)

/**
 * \brief Macro que assiste na inicialização das funções de incremento.
 * Este tipo de função recebe um Data,
 * e efetua uma operação de incremento no valor desse Data.
*/
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

/** Inicialização da função de incremento incre. */
CreateOpIncremento(incre, ++)
/** Inicialização da função de incremento decre. */
CreateOpIncremento(decre, --)

/**
 * \brief Macro que assiste na inicialização das funções de incremento.
 * Este tipo de função recebe dois Data,
 * efetua a operação bitwise respetiva entre eles,
 * e guarda o resultado no segundo Data.
*/
#define CreateOpBitwise(_name, _op)                                  \
void _name(Data *d1, Data *d2) {                                     \
    *(DataValLONG(d2)) = (*DataValLONG(d1) _op *DataValLONG(d2));    \
}

/** Inicialização da função bitwise and. */
CreateOpBitwise(and, &)
/** Inicialização da função bitwise or. */
CreateOpBitwise(or, |)
/** Inicialização da função bitwise xor. */
CreateOpBitwise(xor, ^)
/** Inicialização da função bitwise modulo. */
CreateOpBitwise(modulo, %)

/**
 * \brief Função que calcula a potência de base Data d1 e expoente Data d2 e guarda o resultado no d2.
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

/**
 * \brief Função que inverte os bits de um certo Data do Tipo LONG.
 * @param d Endereço de um Data do Tipo LONG.
*/
void not(Data *d) {
    *DataValLONG(d) = ~*(DataValLONG(d));
}

/**
 *
 * @param fun
 * @param stack
 */
void DoisArgumentos(void (*fun)(Data*, Data*), Stack *stack) {
    Data d2 = Pop(stack);
    Data d1 = Pop(stack);
    (*fun)(&d1, &d2);
    Push(d2, stack);
    free(d1.value);
}

/**
 *
 * @param fun
 * @param stack
 */
void UmArgumento(void (*fun)(Data*), Stack *stack) {
    Data d1 = Pop(stack);
    (*fun)(&d1);
    Push(d1, stack);
}