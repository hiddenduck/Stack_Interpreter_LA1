
/**
 * @file
 * Ficheiro que diz respeito ao interpretador.
 * Contém a função parse() que serve como interpretador.
 */
#include "parser.h"

#define NUMERO_OPERATIONS_DOISARGS 9

/**
 * \brief Função que executa um comando de acordo com o token
 * @param token Endereço do token
 * @param stack Endereço da stack responsável pelo armazenamento.
 */
void operate(char *token, Stack *stack, OperationMap *opDoisArgs) {
    if(strlen(token)==1) {
        int i;
        for (i = 0; opDoisArgs[i].simbolo != 0; i++) {
            if (opDoisArgs[i].simbolo == token[0]) {
                DoisArgumentos(opDoisArgs[i].fun, stack);
                i = NUMERO_OPERATIONS_DOISARGS;
            }
        }
        switch (token[0]) {
            //case '+': {
            //    DoisArgumentos(soma, stack);
            //    break;
            //}
            //case '-': {
            //    DoisArgumentos(subtr, stack);
            //    break;
            //}
            //case '*': {
            //    DoisArgumentos(mult, stack);
            //    break;
            //}
            //case '/': {
            //    DoisArgumentos(divi, stack);
            //    break;
            //}
            case '(': {
                UmArgumento(decre,stack);
                break;
            }
            case ')': {
                UmArgumento(incre,stack);
                break;
            }
            //case '%': {
            //    DoisArgumentos(modulo, stack);
            //    break;
            //}
            //case '#': {
            //    DoisArgumentos(potencia, stack);
            //    break;
            //}
            //case '&': {
            //    DoisArgumentos(and, stack);
            //    break;
            //}
            //case '|': {
            //    DoisArgumentos(or, stack);
            //    break;
            //}
            //case '^': {
            //    DoisArgumentos(xor, stack);
            //    break;
            //}
            case '~': {
                UmArgumento(not,stack);
                break;
            }
            case ';': {
                Pop(stack);
                break;
            }
            case '_': {
                Data *x = Read(0, stack);
                Data y = DataDup(x);
                Push(y, stack);
                break;
            }
            case '\\': {
                Data x, y;
                PopN(stack, 2, &y, &x);
                PushN(stack, 2, y, x);
                break;
            }
            case '@': {
                Data x, y, z;
                PopN(stack, 3, &z, &y, &x);
                PushN(stack, 3, y, z, x);
                break;
            }
            case '$': {
                Data indice = Pop(stack);
                long deslocamento = *DataValLONG(&indice);
                Data *x = Read(deslocamento, stack);
                Data y = DataDup(x);
                Push(y, stack);
                free(indice.value);
                break;
            }
            case 'c': {
                UmArgumento(DataToCHAR, stack);
                break;
            }
            case 'l': {
                char linha[MAX_LENGTH_INPUT];
                assert(fgets(linha, MAX_LENGTH_INPUT, stdin) != NULL);
                assert(linha[strlen(linha) - 1] == '\n');
                Push(CreateDataSTRING(linha), stack);
                break;
            }
            case 'i': {
                UmArgumento(DataToLONG,stack);
                break;
            }
            case 'f':{
                UmArgumento(DataToDOUBLE,stack);
                break;
            }
        }
    }
}

/**
 * \brief Função que interpreta o input e altera a stack segundo esse input.
 *
 * @param input String com o \a input.
 * @param stack Endereço da \a stack responsável pelo armazenamento.
 */
void parse(char *input, Stack *stack){
	char *delims = " \t\n";

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
		    else
		        operate(token, stack, opDoisArgs);

		}
	}
	PrintStack(stack);
}
