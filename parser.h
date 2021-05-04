
/**
 * @headerfile parser.h
 */
#include "operations.h"

int Operator(char *token, Stack  *stack, OperationMap *operationMap);
void HandleOne(int mask, Operation op, Stack *stack, int *r);
void HandleTwo(int mask, Operation op, Stack *stack, int *r);
void HandleTwoDiff(int mask, Operation op, Stack *stack, int *r);
int InputParser(char *token, Stack *stack, Stack *vars);
void InputReader(Stack *stack, Stack *vars);
void Omissions(Stack *vars);
char *getToken(char *linha, char **resto);
Stack *eval(char *line, Stack *stack_ini, Stack *vars, ColectionOperationMaps *collec);

