
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
int Operator(char *token, Stack *stack, OperationMap *operationMap) {
    Operation handle = operationMap[0].op;
    int i, r = 1;
    for (i = 1; operationMap[i].simbolo != 0 && r; i++) {
        if (operationMap[i].simbolo[0] == ' ')
            handle = operationMap[i].op;
        if (strcmp(operationMap[i].simbolo, token) == 0) {
            //depois de encontrar tem de chamar uma função que vê se faz sentido essa operação com os
            //elementos que estão na stack
            //para tal fazemos diferentes mapas para cada tipo de operação: aritmética, lógica, etc...

            (handle)(operationMap[i].mask, operationMap[i].op, stack, &r);
            break;
        }
    }
    return r;
}

/**
 * \brief Função que auxilia a função sem argumentos.
 * @param mask Tipo de máscara.
 * @param op Tipo de operador.
 * @param stack Endereço da \a stack responsável pelo armazenamento.
 * @param r Bool que diz se a operação foi ou não realizada.
 */
void HandleNoArgs (int mask, Operation op, Stack *stack, int *r){
    *r = -1;
    if(mask == ANY){
        SemArgumentos(op, stack);
        *r = 0;
    }
}

/**
 * \brief Função que auxilia a função um argumento.
 * @param mask Tipo de máscara.
 * @param op Tipo de operador.
 * @param stack Endereço da \a stack responsável pelo armazenamento.
 * @param r Bool que diz se a operação foi ou não realizada.
 */
void HandleOne(int mask, Operation op, Stack *stack, int *r) {
    if (Read(0, stack)->tipo & mask) {
        UmArgumento(op, stack);
        *r = 0;
    } else
        *r = -1;
}

/**
 * \brief Função que auxilia a função dois argumentos com tipos diferentes.
 * @param mask Tipo de máscara.
 * @param op Tipo de operador.
 * @param stack Endereço da \a stack responsável pelo armazenamento.
 * @param r Bool que diz se a operação foi ou não realizada.
 */
void HandleTwoDiff(int mask, Operation op, Stack *stack, int *r){
    if(((mask ^ Read(0, stack)->tipo) ^ Read(1, stack)->tipo) == 0){
        DoisArgumentos(op, stack);
        *r = 0;
    } else
        *r = -1;
}

/**
 * \brief Função que auxilia a função dois argumentos com tipos iguais.
 * @param mask Tipo de máscara.
 * @param op Tipo de operador.
 * @param stack Endereço da \a stack responsável pelo armazenamento.
 * @param r Bool que diz se a operação foi ou não realizada.
 */
void HandleTwo(int mask, Operation op, Stack *stack, int *r) {
    if ((Read(0, stack)->tipo & mask) && (Read(1, stack)->tipo & mask)) {
        DoisArgumentos(op, stack);
        *r = 0;
    } else
        *r = -1;
}

/** \brief Função que ajuda o parser em dar push às vars
 *  @param token Endereço do token.
 *  @param stack Endereço da stack.
 *  @param vars Endereço das vars.
 *  @param r Endereço do inteiro.
 */
void PaserVars(char *token, Stack *stack, Stack *vars, int *r){
    if(strlen(token)==1 && token[0]>='A' && token[0]<='Z'){
        Push(DataDup(Read(64 - token[0], vars)), stack);
        *r = 0;
    }
}

/**
 * \brief Função que interpreta o input e altera a stack segundo esse input.
 *
 * @param token String com um fragmento do input.
 * @param stack Endereço da stack responsável pelo armazenamento.
 * @param opMap Mapa com as operações.
 * @param vars Endereço da vars responsável pelo armazenamento de variáveis.
 */
int InputParser(char *token, Stack *stack, Stack *vars){
    int r = 1;
    char *resto;

    /* Testar se o valor introduzido é do tipo long. */
    long val = strtol(token, &resto, 10);

    if (strlen(resto) == 0 && val < LONG_MAX && val > LONG_MIN) {
        Push(CreateDataLONG(val), stack);
        r = 0;
    } else if (strlen(resto) == 0 && (val == LONG_MAX || val == LONG_MIN)){
        long long vall = strtoll(token, &resto, 10);
        Push(CreateDataLONGLONG(vall), stack);
        r = 0;
    } else {
        /* Testar se o resto contém um double decimal e somar à parte inteira. */
        double vald = strtod(resto, &resto);
        if (strlen(resto) ==  0) {
            if (val < 0)
                vald = -vald;
            vald += val;
            Push(CreateDataDOUBLE(vald), stack);
            r = 0;
        } else
            PaserVars(token, stack, vars, &r);
    }
    return r;
}

/** \brief Função que efetua parse a arrays, strings e blocos.
 *  @param line Linha recebida.
 *  @param seps Separadores do Data.
 *  @param rest Resto da linha.
 *  @return Parte da linha que contém o array/string/bloco.
 */
char *get_delimited(char *line, char *seps, char **resto) {

    int i, count;
    for (i = 1, count = 1; count; i++) {
        if (line[i] == seps[1])
            count--;
        else if (line[i] == seps[0])
            count++;
    }

    line[i-1] = '\0';
    *resto = line+i+1;
    return line;
}

/** \brief Função auxiliar do getToken que trata de qualquer caso sem ser as delimitadas
 *
 * @param linha Linha do Input
 * @param resto Resto da Linha
 */
void getTokenAux(char *linha, char **resto) {
    int i;
    for (i = 0; linha[i] != '\0' && linha[i] != ' ' && linha[i] != '\n' && linha[i] != '\t'; i++);
    linha[i] = '\0';
    *resto = linha+i+1;
}

/** \brief Função que que separa um token do resto do input.
 *  @param linha Linha de input.
 *  @param resto Resto da linha.
 *  @return Token obtido.
 */
char *getToken(char *linha, char **resto) {
    for (; *linha == ' ' || *linha == '\n' || *linha == '\t'; linha++);
    switch (*linha) {
        case '\"':
            linha = get_delimited(linha, "\"\"", resto);
            break;
        case '[':
            linha = get_delimited(linha, "[]", resto);
            break;
        case '{':
            linha = get_delimited(linha, "{}", resto);
            break;
        case '\0':
            *resto = linha;
            break;
        default:
            getTokenAux(linha, resto);
            break;
    }
    return linha;
}

/**
 * \brief Função que recebe o input do utilizador e invoca o InputParser.
 * @param stack Endereço da stack responsável pelo armazenamento.
 * @param vars Endereço da vars responsável pelo armazenamento de variáveis.
 */
void InputReader(Stack *stack) {
    char input[MAX_LENGTH_INPUT];

    assert(fgets(input, MAX_LENGTH_INPUT, stdin) != NULL);
    assert(input[strlen(input) - 1] == '\n');

    OperationMap aritMap[] = ARIT_MAP;
    OperationMap stackMap[] = STACK_MAP;
    OperationMap inteiroMap[] = INTEIRO_MAP;
    OperationMap stringMap[] = STRING_MAP;
    OperationMap arrayMap[] = ARRAY_MAP;
    OperationMap blockMap[] = BLOCK_MAP;
    ColectionOperationMaps collec = {stackMap,aritMap,inteiroMap,stringMap,arrayMap, blockMap};
    stack->collec = &collec;
    eval(input,stack);
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

/** \brief Função que avalia uma linha.
 *  @param line Linha a ser avaliada.
 *  @param stack_ini Endereço da stack.
 *  @return Apontador para a stack.
 */
Stack *eval(char *line, Stack *stack_ini) {
    Stack *vars = (stack_ini->vars);
    ColectionOperationMaps *collec = stack_ini->collec;

    while (*line != '\0') {
        char *token = getToken(line, &line);

        if (token[0] == '\"')
            Push(CreateDataSTRING(++token), stack_ini);
        else if (token[0] == '[') {
            Stack *temp = CreateStack(10);
            temp->collec = collec;
            temp->vars = vars;
            temp = (eval(++token, temp));
            CleanupStack(temp);
            Push(CreateDataSTACK(temp), stack_ini);
        }
        else if (token[0] == '{')
            Push(CreateDataBLOCK(++token), stack_ini);
        else if (token[0] != '\0' &&
            (token[0] != ':' || TwoPoints(stack_ini, vars, token[1])) &&
            InputParser(token, stack_ini, vars) &&
            Operator(token, stack_ini, collec->Arit) &&
            Operator(token, stack_ini, collec->StackManip) &&
            Operator(token, stack_ini, collec->Inteiro) &&
            Operator(token, stack_ini, collec->String) &&
            Operator(token, stack_ini, collec->Array) &&
            Operator(token, stack_ini, collec->Block)) {}
    }

    return stack_ini;
}
