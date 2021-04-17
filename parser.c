
/**
 * @file
 * Ficheiro que diz respeito ao interpretador.
 * Contém a função parse() que serve como interpretador.
 */
#include "parser.h"

/**
 * \brief Função que executa um comando de acordo com o token
 * @param token Endereço do token
 * @param stack Endereço da stack responsável pelo armazenamento.
 */
int operate(char *token, Stack *stack, OperationMap *operationMap, Operation operation) {
    int r = 0;
    if(strlen(token)==1) {
        int i;
        for (i = 0; operationMap[i].simbolo != 0; i++) {
            if (operationMap[i].simbolo == token[0]) {
                (operation)(operationMap[i].op, stack);
                r = 1;
                break;
            }
        }
    }
    return r;
}

/**
 * \brief Função que interpreta o input e altera a stack segundo esse input.
 *
 * @param input String com o \a input.
 * @param stack Endereço da \a stack responsável pelo armazenamento.
 */
void parse(char *input, Stack *stack){
	char *delims = " \t\n";

    OperationMap semArgs[] = {
            {';', DecrementaSP},
            {'_', Underscore},
            {'\\', Swap},
            {'@', SwapThree},
            {'$', DollarSign},
            {'l', ReadLine},
            {0, NULL}
    };

    OperationMap opUmArgs [] = {
            {'(', decre},
            {')', incre},
            {'~', not},
            {'c', DataToCHAR},
            {'i', DataToLONG},
            {'f', DataToDOUBLE}
    };

    OperationMap opDoisArgs [] = {
            {'+', soma},
            {'-', subtr},
            {'*', mult},
            {'/', divi},
            {'%', modulo},
            {'#', potencia},
            {'&', and},
            {'|', or},
            {'^', xor},
            {0, NULL}
    };
    
	for(char *token = strtok(input, delims); token != NULL; token = strtok(NULL, delims)){
		char *resto;
		/* Testar se o valor introduzido é do tipo long. */
		long vall = strtol(token, &resto, 10);

		if(strlen(resto) == 0){
			Push(CreateDataLONG(vall), stack);
		} else {
		    /* Testar se o resto contém um double decimal e somar à parte inteira. */
		    double vald = strtod(resto, &resto);
		    
            if (vall < 0)
                vald = vall - vald;
		    else
		        vald += vall;

		    if (strlen(resto) ==  0)
		        Push(CreateDataDOUBLE(vald), stack);
		    else if (operate(token, stack, opDoisArgs, DoisArgumentos) ||
                     operate(token, stack, opUmArgs, UmArgumento) ||
                     operate(token, stack, semArgs, SemArgumentos)) {}
		}
	}
	PrintStack(stack);
}