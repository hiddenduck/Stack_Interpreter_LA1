
/**
 * @file parser.c
 * Ficheiro que diz respeito ao interpretador.
 * Contém a função parse() que serve como interpretador.
 */
#include "parser.h"

/**
 * \brief Função que executa um comando de acordo com o token.
 * @param token Endereço do token.
 * @param stack Endereço da stack responsável pelo armazenamento.
 * @param operationMap Endereço do primeiro elemento do operationMap.
 */
void Operator(char *token, Stack *stack, OperationMap *operationMap) {
    Operation operation = operationMap[0].op;
    if(strlen(token)==1) {
        int i;
        for (i = 1; operationMap[i].simbolo != 0; i++) {
            if (operationMap[i].simbolo == ' ')
                operation = operationMap[i].op;
            if (operationMap[i].simbolo == token[0]) {
                //depois de encontrar tem de chamar uma função que vê se faz sentido essa operação com os
                //elementos que estão na stack

                //para tal fazemos diferentes mapas para cada tipo de operação: aritmética, lógica, etc...

                (operation)(operationMap[i].op, stack);
                break;
            }
        }
    }
}

/**
 * \brief Função que interpreta o input e altera a stack segundo esse input.
 *
 * @param token String com um fragmento do input
 * @param stack Endereço da stack responsável pelo armazenamento.
 * @param opMap Mapa com as operações
 */
void InputParser(char *token, Stack *stack, OperationMap *opMap){

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
            Operator(token, stack, opMap);
    }
}

/**
 * \brief Função que recebe o input do utilizador e invoca o InputParser.
 * @param stack Endereço da stack responsável pelo armazenamento.
 */
void InputReader(Stack *stack) {
    char input[MAX_LENGTH_INPUT];

    assert(fgets(input, MAX_LENGTH_INPUT, stdin) != NULL);
    assert(input[strlen(input) - 1] == '\n');

    OperationMap opMap[] = OPERATION_MAP;

    char *delims = " \t\n";
    for(char *token = strtok(input, delims); token != NULL; token = strtok(NULL, delims)) //tirar isto?
        //char *getToken(linha, resto)
        //recebe a linha e faz sscanf(%s, %[^\n^])
        //fazer um Reader que lê a linha, devolve o token com tudo que esteja entre dois delimitadores
        //ver onde começa um [ e soma 1 a um long quando vê um ] subtrai 1 a um long
        //quando esse long for 0 o array acabou

        //função eval recebe a linha e a stack inicial e cria a stack se não existir (?)
        //funciona como o parser e pode ser chamada recursivamente para os arrays
        InputParser(token, stack, opMap);
}
