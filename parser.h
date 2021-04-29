
/**
 * @headerfile parser.h
 */
#include "operations.h"

int Operator(char *token, Stack  *stack, OperationMap *operationMap, Handle handle);
int PushTokenParser(char *token, Stack *stack, Stack *vars);
void InputReader(Stack *stack, Stack *vars);
void Omissions(Stack *vars);
char *getToken(char *linha, char **resto);
char *get_delimited(char *line, char *seps, char **rest);
Stack *eval(char *line, Stack *stack_ini, Stack *vars, ColectionOperationMaps *collec);

int Handle_Aritm();
