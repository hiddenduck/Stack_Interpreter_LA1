
/**
 * @file parser.c
 * Ficheiro que diz respeito ao interpretador.
 * Contém a função parse() que serve como interpretador.
 */
#include "parser.h"

/**
 * \brief Função que executa um comando de acordo com o token.
 * @param token Endereço do token.
 * @param stack Endereço da stack responsável pelo armazenamento.
 * @param operationMap Endereço do primeiro elemento do operationMap.
 * @param vars Endereço da vars responsável pelo armazenamento de variáveis.
 */
void Operator(char *token, Stack *stack, OperationMap *operationMap, Stack *vars) {
    Operation operation = operationMap[0].op;
    int i;
    for (i = 1; operationMap[i].simbolo != 0; i++) {
        if (operationMap[i].simbolo[0] == ' ')
            operation = operationMap[i].op;
        if (strcmp(operationMap[i].simbolo, token) == 0) {
            //depois de encontrar tem de chamar uma função que vê se faz sentido essa operação com os
            //elementos que estão na stack

            //para tal fazemos diferentes mapas para cada tipo de operação: aritmética, lógica, etc...

            (operation)(operationMap[i].op, stack);
            break;
        }
    }
    if(token[0]==':')
        TwoPoints(stack, vars, token[1]);
}

/**
 * \brief Função que interpreta o input e altera a stack segundo esse input.
 *
 * @param token String com um fragmento do input.
 * @param stack Endereço da stack responsável pelo armazenamento.
 * @param opMap Mapa com as operações.
 * @param vars Endereço da vars responsável pelo armazenamento de variáveis.
 */
void InputParser(char *token, Stack *stack, OperationMap *opMap, Stack *vars){

    char *resto;

    /* Testar se o valor introduzido é do tipo long. */
    long vall = strtol(token, &resto, 10);

    if (strlen(resto) == 0) {
        Push(CreateDataLONG(vall), stack);
    } else {
        /* Testar se o resto contém um double decimal e somar à parte inteira. */
        double vald = strtod(resto, &resto);
        if (strlen(resto) ==  0) {
            if (vall < 0)
                vald = -vald;
            vald += vall;
            Push(CreateDataDOUBLE(vald), stack);
        } else if(strlen(token)==1 && token[0]>='A' && token[0]<='Z'){
            //limpar isto (MI)
            Data *letter = Read(64 - token[0], vars);
            Push(DataDup(letter), stack);
        } else
            Operator(token, stack, opMap, vars);
    }
}

/**
 * \brief Função que recebe o input do utilizador e invoca o InputParser.
 * @param stack Endereço da stack responsável pelo armazenamento.
 * @param vars Endereço da vars responsável pelo armazenamento de variáveis.
 */
void InputReader(Stack *stack, Stack *vars) {
    char input[MAX_LENGTH_INPUT];

    assert(fgets(input, MAX_LENGTH_INPUT, stdin) != NULL);
    assert(input[strlen(input) - 1] == '\n');

    OperationMap opMap[] = OPERATION_MAP;

    eval(input, stack);
    //char *delims = " \t\n";
    //for(char *token = strtok(input, delims); token != NULL; token = strtok(NULL, delims)) //tirar isto?
    //    //char *getToken(linha, resto)
    //    //recebe a linha e faz sscanf(%s, %[^\n^])
    //    //fazer um Reader que lê a linha, devolve o token com tudo que esteja entre dois delimitadores
    //    //ver onde começa um [ e soma 1 a um long quando vê um ] subtrai 1 a um long
    //    //quando esse long for 0 o array acabou
//
    //    //função eval recebe a linha e a stack inicial e cria a stack se não existir (?)
    //    //funciona como o parser e pode ser chamada recursivamente para os arrays
    //    InputParser(token, stack, opMap, vars);
}

/** \brief Função que atribui os valores por omissão das variáveis.
 *  @param vars Endereço da vars responsável pelo armazenamento de variáveis.
 */
void Omissions(Stack *vars){
    int i;
    for(i=1; i<=6; i++){
        *Read(-i, vars) = CreateDataLONG(9+i);
    }
    *Read(-14, vars) = CreateDataCHAR('\n');
    *Read(-19, vars) = CreateDataCHAR(' ');
    *Read(-24, vars) = CreateDataLONG(0);
    *Read(-25, vars) = CreateDataLONG(1);
    *Read(-26, vars) = CreateDataLONG(2);
}

/**
 *
 * @param linha
 * @param resto
 * @return
 */
char *getToken(char *linha, char **resto) {
    int i;
    for (i = 0; linha[i] == ' ' || linha[i] == '\n' || linha[i] == '\t'; i++);
    for (i; linha[i] != '\0' && linha[i] != ' ' && linha[i] != '\n' && linha[i] != '\t'; i++);
    if (linha[i] != '\0') {
        linha[i] = '\0';
        *resto = linha+i+1;
    }
    else
        *resto = NULL;
    return linha;
}

/**
 *
 * @param line
 * @param seps
 * @param rest
 * @return
 */
char *get_delimited(char *line, char *seps, char **rest) {
    char end, start = '\0';
    if (seps[1] != '\0') {
        start = seps[0];
        end = seps[1];
    } else {
        end = seps[0];
    }

    int i, count;
    for (i = 0, count = 1, line++; count; i++) {
        if (line[i] == end)
            count--;
        else if (start != '\0' && line[i] == start)
            count++;
    }

    line[i-1] = '\0';

    *rest = line+i+1;
    return line;
}

/**
 *
 * @param line
 * @param stack_ini
 * @return
 */
Stack *eval(char *line, Stack *stack_ini /*leva o vars?*/) {
    if (stack_ini == NULL)
        stack_ini = CreateStack(INCREMENTO_STACK);

    while (line[0] != '\0') {
        char *token = getToken(line, &line);

        if (token[1] == '\0' && token[0] == '\"')
            Push(CreateDataSTRING(get_delimited(line, "\"", &line)), stack_ini);
        else if (token[1] == '\0' && token[0] == '[')
            Push(CreateDataSTACK(eval(get_delimited(line, "[]", &line), NULL)), stack_ini);

        else if (PushTokenParser(token, stack_ini)) {}
        else if (Operator(token))
    }

    return stack_ini;
}
