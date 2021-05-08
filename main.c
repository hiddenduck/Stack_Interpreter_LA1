
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
    printf("%d\n", INT_MAX);
    printf("%ld\n", LONG_MAX);
    Stack *vars = CreateStack(VARS_SIZE);
    Stack *stack = CreateStack(INCREMENTO_STACK);
    Omissions(vars);
    stack->vars = vars;
    InputReader(stack);
    PrintStack(stack);
    putchar('\n');
    return 0;
}
