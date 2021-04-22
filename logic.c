
#include "logic.h"

/** \brief Macro para preparar o d1 para receber resultados*/
#define LogicTestD1 \
    if (d1->tipo == LONG)\
        a = *DataValLONG(d1);\
    else {\
        a = *DataValDOUBLE(d1);\
        DataToLONG(d1);\
    }               \

/** \brief Macro para conseguir o valor de d2 */
#define LogicTestD2 \
if (d2->tipo == LONG)\
    b = *DataValLONG(d2);\
else\
    b = *DataValDOUBLE(d2);\


/** \brief Função que verifica se o valor de dois Data é igual.
 *
 * @param d1 Data que guarda o resultado
 * @param d2 Data a operar
 */
void equals(Data *d1, Data *d2) {
    double a,b;
    LogicTestD1
    LogicTestD2
    *DataValLONG(d1) = (long) (a == b);
}

/** \brief Função que verifica se o valor de um Data é menor do que o segundo Data.
 *
 * @param d1 Data que guarda o resultado
 * @param d2 Data a operar
 */
void lesser(Data *d1, Data *d2) {
    double a,b;
    LogicTestD1
    LogicTestD2
    *DataValLONG(d1) = (long) (a < b);
}

/** \brief Função que verifica se o valor de um Data é maior do que o segundo Data.
 *
 * @param d1 Data que guarda o resultado
 * @param d2 Data a operar
 */
void greater(Data *d1, Data *d2) {
    double a,b;
    LogicTestD1
    LogicTestD2
    *DataValLONG(d1) = (long) (a > b);
}

/** \brief Função que nega o valor de um Data.
 *
 * @param d1 Data que guarda o resultado
 */
void notLG(Data *d1) {
    double a;
    LogicTestD1
    *DataValLONG(d1) = (long) !a;
}
