
/**
 * @file
 * Ficheiro que diz respeito ao interpretador.
 * Contém a função parse() que serve como interpretador.
 */
#include "parser.h"

/**
 * \brief Função que interpreta o input e altera a stack segundo esse input
 *
 * Recebe uma string com o \a input e lê-a até encontrar um dos delimitadores definidos.
 * Converte a string lida do \a input em long até encontrar um caracter impossível de converter, guardando o resto noutra string.
 *
 * Se o resto for vazio, a string lida representa um número inteiro.
 * Então, este valor é guardado na stack pela função Push(), do stack.h.
 *
 * Se o resto não é vazio, a string lida pode representar uma operação.
 * Então, essa string é comparada com as operações implementadas até então.
 * Se encontrar uma correspondência, executa a operação pretendida.
 *
 * O processo é repetido com o resto da string do \a input após o delimitador até esta terminar.
 * No fim, a função PrintStack() do stack.h é invocada.
 *
 * @param input String com o \a input.
 * @param stack Endereço da \a stack responsável pelo armazenamento.
 */
void parse(char *input, STACK *stack){
	char *delims = " \t\n";
	for(char *token = strtok(input, delims); token != NULL; token = strtok(NULL, delims)){
		char *resto;
		long val = strtol(token, &resto, 10);
		if(strlen(resto) == 0){
			Push(val, stack);
		}else{
            if(strlen(token)==1) {
                switch (token[0]) {
                    case '+': {
                        long y = Pop(stack);
                        long x = Pop(stack);
                        Push(x+y, stack);
                        break;
                    }
                    case '-': {
                        long y = Pop(stack);
                        long x = Pop(stack);
                        Push(x-y, stack);
                        break;
                    }
                    case '*': {
                        long y = Pop(stack);
                        long x = Pop(stack);
                        Push(x*y, stack);
                        break;
                    }
                    case '/': {
                        long y = Pop(stack);
                        long x = Pop(stack);
                        Push(x / y, stack);
                        break;
                    }
                    case '(': {
                        long x = Pop(stack);
                        Push(x-1, stack);
                        break;
                    }
                    case ')': {
                        long x = Pop(stack);
                        Push(x+1, stack);
                        break;
                    }
                    case '%': {
                        long y = Pop(stack);
                        long x = Pop(stack);
                        Push(x%y, stack);
                        break;
                    }
                    case '#': {
                        long y = Pop(stack);
                        long x = Pop(stack);
                        Push((long)pow(x,y), stack);
                        break;
                    }
                    case '&': {
                        long y = Pop(stack);
                        long x = Pop(stack);
                        Push(x&y, stack);
                        break;
                    }
                    case '|': {
                        long y = Pop(stack);
                        long x = Pop(stack);
                        Push(x|y, stack);
                        break;
                    }
                    case '^': {
                        long y = Pop(stack);
                        long x = Pop(stack);
                        Push(x^y, stack);
                        break;
                    }
                    case '~': {