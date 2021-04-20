
/**
 * @file parser.c
 * Ficheiro que diz respeito ao interpretador.
 * Contém a função parse() que serve como interpretador.
 */
#include "parser.h"

/**
 * \brief Função que executa um comando de acordo com o token
 * @param token Endereço do token
 * @param stack Endereço da stack responsável pelo armazenamento.
 * @param operationMap
 */
void operate(char *token, Stack *stack, OperationMap *operationMap) {
    Operation operation = operationMap[0].op;
    if(strlen(token)==1) {
        int i;
        for (i = 1; operationMap[i].simbolo != 0; i++) {
            if (operationMap[i].simbolo == ' ')
                operation = operationMap[i].op;
            if (operationMap[i].simbolo == token[0]) {
                (operation)(operationMap[i].op, stack);
                break;
            }
        }
    }
}

/**
 * \brief Função que interpreta o input e altera a stack segundo esse input.
 *
 * @param input String com o \a input.
 */
void parse(char *token, Stack *stack, OperationMap opMap[]){

    char *resto;

    /* Testar se o valor introduzido é do tipo long. */
    long vall = strtol(token, &resto, 10);

    if (strlen(resto) == 0) {
        Push(CreateDataLONG(vall), stack);
    } else {
        /* Testar se o resto contém um double decimal e somar à parte inteira. */
        double vald = strtod(resto, &resto);
        if (strlen(resto) ==  0) {
            if (vall < 0)
                vald = -vald;
            vald += vall;
            Push(CreateDataDOUBLE(vald), stack);
        } else
            operate(token, stack, opMap);
    }
}
