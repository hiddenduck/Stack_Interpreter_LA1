
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

/** \brief Função
 *  \param stack Endereço da \a stack responsável pelo armazenamento.
 */
void ifThenElse(Stack *stack){
    Data elseOperator = Pop(stack);
    Data thenOperator = Pop(stack);
    Data logicValue = Pop(stack);
    switch(logicValue.tipo){
        case LONG:
            if(*DataValLONG(&logicValue)){
                Push(thenOperator, stack);
                free(elseOperator.value);
                free(logicValue.value);
            }
            else{
                Push(elseOperator, stack);
                free(thenOperator.value);
                free(logicValue.value);
            }
            break;
        case DOUBLE:
            if(*DataValDOUBLE(&logicValue)){
                Push(thenOperator, stack);
                free(elseOperator.value);
                free(logicValue.value);
            }
            else{
                Push(elseOperator, stack);
                free(thenOperator.value);
                free(logicValue.value);
            }
        default:
            break;
    }
}

/** \brief
*
*/
void LesserBetweenTwo(Stack *stack){
    Data d2 = Pop(stack);
    Data d1 = Pop(stack);
    switch (d1.tipo&d2.tipo) {
        case LONG:
            if(*DataValLONG(&d1)>*DataValLONG(&d2)){
                Push(d2, stack);
                free(d1.value);
            }
            else{
                Push(d1, stack);
                free(d2.value);
            }
            break;
        default:
            DataToDOUBLE(&d1);
            double *p = DataValDOUBLE(&d1);
            switch (d2.tipo) {
                case LONG:
                    if(*p>*DataValLONG(&d2)){
                        Push(d2, stack);
                        free(d1.value);
                    }
                    else{
                        Push(d1, stack);
                        free(d2.value);
                        }
                    break;
                case DOUBLE:
                    if(*p>*DataValDOUBLE(&d2)){
                        Push(d2, stack);
                        free(d1.value);
                    }
                    else{
                        Push(d1, stack);
                        free(d2.value);
                    }
                    break;
                default:
                    break;
            }
            break;
    }
}

/** \brief
*
*/
void GreaterBetweenTwo(Stack *stack){
    Data d2 = Pop(stack);
    Data d1 = Pop(stack);
    switch (d1.tipo&d2.tipo) {
        case LONG:
            if(*DataValLONG(&d1)<*DataValLONG(&d2)){
                Push(d2, stack);
                free(d1.value);
            }
            else{
                Push(d1, stack);
                free(d2.value);
            }
            break;
        default:
            DataToDOUBLE(&d1);
            double *p = DataValDOUBLE(&d1);
            switch (d2.tipo) {
                case LONG:
                    if(*p<*DataValLONG(&d2)){
                        Push(d2, stack);
                        free(d1.value);
                    }
                    else{
                        Push(d1, stack);
                        free(d2.value);
                        }
                    break;
                case DOUBLE:
                    if(*p<*DataValDOUBLE(&d2)){
                        Push(d2, stack);
                        free(d1.value);
                    }
                    else{
                        Push(d1, stack);
                        free(d2.value);
                    }
                    break;
                default:
                    break;
            }
            break;
    }
}