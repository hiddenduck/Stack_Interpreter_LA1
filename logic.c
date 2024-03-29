
#include "logic.h"

/** \brief Função que verifica se o valor de dois Data é igual.
 *
 * @param d1 Data que guarda o resultado
 * @param d2 Data a operar
 */
void equals(Data *d1, Data *d2) {
    double a,b;
    NumTestD1
    NumTestD2
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
    NumTestD1
    NumTestD2
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
    NumTestD1
    NumTestD2
    DataToLONG(d1);
    *DataValLONG(d1) = (long) (a > b);
}

/** \brief Função que nega o valor de um Data.
 *
 * @param d1 Data que guarda o resultado
 */
void notLG(Data *d1) {
    long a = GetBoolFromData(d1);
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
    long a = GetBoolFromData(d1);
    if(a) {
        swapDataFree(d1, &thenOperator);
        Free(&elseOperator);
    }
    else {
        swapDataFree(d1, &elseOperator);
        Free(&thenOperator);
    }
}

/** \brief Função que coloca o menor dos 2 valores na stack.
*   @param d1 Endereço de um Data.
*   @param d2 Endereço de um Data.
*/
void LesserBetweenTwo(Data *d1, Data *d2){
    double a,b;
    NumTestD1;
    NumTestD2;
    if(a>b)
        swapData(d1,d2);
}

/** \brief Função que coloca o maior dos 2 valores na stack.
*   @param d1 Endereço de um Data.
*   @param d2 Endereço de uma Data.
*/  
void GreaterBetweenTwo(Data *d1, Data *d2){
    double a,b;
    NumTestD1;
    NumTestD2;
    if(a<b)
        swapData(d1,d2);
}

/** \brief Função que realiza o E lógico com shortcut.
 *  @param d1 Endereço de um data.
 *  @param d2 Endereço de um data.
 */
void andWithShortcut(Data *d1, Data *d2){
    long a = GetBoolFromData(d1);
    if(a)
        swapData(d1, d2);
}

/** \brief Função que realiza o OU lógico com shortcut.
 *  @param d1 Endereço de um data.
 *  @param d2 Endereço de um data.
 */
void orWithShortcut(Data *d1, Data *d2){
    long a = GetBoolFromData(d1);
    if(!a)
        swapData(d1, d2);
}
