
#include "logic.h"

/** \brief Macro para conseguir o valor de d2*/
#define LogicTestD1 \
    if (d1->tipo == LONG)\
        a = *DataValLONG(d1);\
    else {\
        a = *DataValDOUBLE(d1);\
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
    DataToLONG(d1);
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
    DataToLONG(d1);
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
    DataToLONG(d1);
    *DataValLONG(d1) = (long) (a > b);
}

/** \brief Função que nega o valor de um Data.
 *
 * @param d1 Data que guarda o resultado
 */
void notLG(Data *d1) {
    double a;
    LogicTestD1
    DataToLONG(d1);
    *DataValLONG(d1) = (long) !a;
}

/** \brief Função
 *  \param stack Endereço da \a stack responsável pelo armazenamento.
 */
void ifThenElse(Stack *stack){
    Data elseOperator = Pop(stack);
    Data thenOperator = Pop(stack);
    Data *d1 = Read(0, stack);
    double a;
    LogicTestD1
    if(a)
        SwapDataPointers(d1, &thenOperator);
    else
        SwapDataPointers(d1, &elseOperator);

    free(elseOperator.value);
    free(thenOperator.value);
}

/** \brief Função que coloca o menor dos 2 valores na stack.
*   @param d1 Endereço de um Data.
*   @param d2 Endereço de um Data.
*/
void LesserBetweenTwo(Data *d1, Data *d2){
    double a,b;
    LogicTestD1;
    LogicTestD2;
    if(a>b)
        SwapDataPointers(d1, d2);
}

/** \brief Função que coloca o maior dos 2 valores na stack.
*   @param d1 Endereço de um Data.
*   @param d2 Endereço de uma Data.
*/  
void GreaterBetweenTwo(Data *d1, Data *d2){
    double a,b;
    LogicTestD1;
    LogicTestD2;
    if(a<b)
        SwapDataPointers(d1, d2);
}

/** \brief Função que realiza o E lógico com shortcut.
 *  @param d1 Endereço de um data.
 *  @param d2 Endereço de um data.
 */
void andWithShortcut(Data *d1, Data *d2){
    double a;
    LogicTestD1;
    if(a)
        SwapDataPointers(d1, d2);
}

/** \brief Função que realiza o OU lógico com shortcut.
 *  @param d1 Endereço de um data.
 *  @param d2 Endereço de um data.
 */
void orWithShortcut(Data *d1, Data *d2){
    double a;
    LogicTestD1;
    if(!a)
        SwapDataPointers(d1, d2);
}
