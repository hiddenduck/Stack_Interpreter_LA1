
/**
 * @headerfile parser.h
 */
#include "operations.h"

void Operator(char *token, Stack  *stack, OperationMap *operationMap, Stack *vars);
void InputParser(char *token, Stack *stack, OperationMap *opMap, Stack *vars);
void InputReader(Stack *stack, Stack *vars);
void Omissions(Stack *vars);
char *getToken(char *linha, char **resto);
char *get_delimited(char *line, char *seps, char **rest);
Stack *eval(char *line, Stack *stack_ini, Stack *vars, OperationMap *opMap);
