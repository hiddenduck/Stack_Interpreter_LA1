
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
    Stack *stack = CreateStack(INCREMENTO_STACK);
    Stack *vars = CreateStack(VARS_SIZE);
    Omissions(vars);
    InputReader(stack, vars);
    PrintStack(stack);
    putchar('\n');
    return 0;
}
