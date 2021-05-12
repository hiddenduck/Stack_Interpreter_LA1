
/**
 * @file main.c
 * Ficheiro que diz respeito ao main.
 */
#include "main.h"

/**
 * \brief Esta é a função inicial do programa que inicializa a Stack.
 * @return Devolve o valor 0.
 */
int main(){
    Stack *vars = CreateStack(VARS_SIZE, NULL, NULL);
    Omissions(vars);
    Stack *stack = CreateStack(INCREMENTO_STACK, NULL, vars);
    InputReader(stack);
    PrintStack(stack);
    putchar('\n');
    return 0;
}
