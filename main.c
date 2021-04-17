
/**
 * @file
 * Ficheiro que diz respeito ao main.
 */
#include "main.h"

/**
 * \brief Esta é a função inicial do programa que recebe o \a input.
 *
 *  É inicializada uma estrutura Stack através da função CreateStack(), provenientes de stack.h.
 *
 *  O input é recebido através da função fgets() e guardada numa string de tamanho 10240,
 *  utilizando a função assert() para:\n
 *  ㅤㅤㅤverificar se o input não é NULL;\n
 *  ㅤㅤㅤverificar se o último elemento da string é '\\n';\n
 *  abortando o programa se algum caso não se verificar.
 *
 *  A função parse() é invocada com os argumentos line e o endereço da \a stack.
 *
 * @return Devolve o valor 0.
 */
int main(){
    char input[MAX_LENGTH_INPUT];
    Stack *stack = CreateStack();
    OperationMap opMap[] = {
            {' ', SemArgumentos},
            {';', DecrementaSP},
            {'_', Underscore},
            {'\\', Swap},
            {'@', SwapThree},
            {'$', DollarSign},
            {'l', ReadLine},
            {' ', UmArgumento},
            {'(', decre},
            {')', incre},
            {'~', not},
            {'c', DataToCHAR},
            {'i', DataToLONG},
            {'f', DataToDOUBLE},
            {' ', DoisArgumentos},
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

    assert(fgets(input, MAX_LENGTH_INPUT, stdin) != NULL);
    assert(input[strlen(input) - 1] == '\n');

    char *delims = " \t\n";
    for(char *token = strtok(input, delims); token != NULL; token = strtok(NULL, delims))
        parse(token, stack, opMap);

    PrintStack(stack);
    return 0;
}
