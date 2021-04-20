
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
    Stack *stack = CreateStack();
    InputReader(stack);
    PrintStack(stack);
    return 0;
}
