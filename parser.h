
/**
 * @headerfile parser.h
 */
#include "operations.h"

void Operator(char *token, Stack  *stack, OperationMap *operationMap, Stack *vars);
void InputParser(char *token, Stack *stack, OperationMap *opMap, Stack *vars);
void InputReader(Stack *stack, Stack *vars);
void Omissions(Stack *vars);
