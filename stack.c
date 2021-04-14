
/**
 * @file
 * Ficheiro relativo à estrutura Stack e às funções correspondentes.
 */
#include "stack.h"

/**
 * \brief Função que devolve uma \a stack padrão
 *
 * sp é igual a -1 para simbolizar uma stack vazia.
 *
 * @return A Stack inicializada na função.
 */
Stack *CreateStack() {
    Stack *s = (Stack *) malloc(sizeof(Stack));
    assert(s != NULL);
    s->size = INCREMENTO_STACK;
    s->sp = -1;
    s->array = (Data *) calloc(s->size, sizeof(Data));
    return s;
}

/**
 * \brief Função que devolve o elemento na posição sp da \a stack e decrementa sp.
 *
 * @param stack Endereço da \a stack responsável pelo armazenamento.
 * @return Devolve o elemento do tipo Data na última posiçao.
 */
Data Pop(Stack *stack) {
    return stack->array[(stack->sp)--];
}

/**
 * \brief Função que aumenta o sp da \a stack e coloca um elemento nessa posição.
 *
 * @param data Elemento do tipo Data a colocar na \a stack.
 * @param stack Endereço da \a stack responsável pelo armazenamento.
 */
void Push(Data data, Stack *stack) {
    if(stack->size == (stack->sp)-1) {
        stack->size +=INCREMENTO_STACK;
        stack->array = (Data *) realloc(stack->array, stack->size * sizeof(Data));
    }
    stack->sp++;
    stack->array[(stack->sp)] = data;
}

/**
 * \brief Função que lê um elemento a uma certa distância do sp.
 *
 * @param deslocamento Distância em relação ao sp.
 * @param stack Endereço da \a stack responsável pelo armazenamento.
 * @return Devolve um elemento do tipo Data.
 */
Data *Read(long deslocamento, Stack *stack) {
    Data *val = &stack->array[stack->sp-deslocamento];
    return val;
}

/**
 * \brief Função que imprime um certo elemento de acordo com o seu Tipo.
 *
 * @param data Elemento a imprimir.
 */
void PrintData(Data *data) {
    switch (data->tipo) {
        case LONG:
            printf("%ld", *(long*)(data->value));
            break;
        case DOUBLE:
            printf("%g", *(double*)(data->value));
            break;
        case CHAR:
            printf("%c", *((char*)(data->value)));
            break;
        case STRING:
            printf("%s", (char*)data->value);
            break;
    }
}

/**
 * \brief Função que imprime todos os elementos da \a stack até ao elemento na posição sp.
 *
 * @param stack Endereço da \a stack responsável pelo armazenamento.
 */
void PrintStack(Stack *stack) {
    for (int i = 0 ; i <= stack -> sp; i++){
        PrintData(&stack->array[i]);
    }
    putchar('\n');
}

/**
 * \brief Macro que assiste na inicialização das funções DataVal.
 * Devolve um apontador para o valor convertido do void* respetivo ao data recebido.
 */
#define DataVal(_name, _type)              \
    _type *DataVal##_name(Data *data) {    \
        return (_type*) data->value;       \
    }

/** Inicialização da função DataValCHAR. */
DataVal(CHAR, char)
/** Inicialização da função algorítmica DataValLONG. */
DataVal(LONG, long)
/** Inicialização da função algorítmica DataValDOUBLE. */
DataVal(DOUBLE, double)
/** Inicialização da função algorítmica DataValSTRING. */
DataVal(STRING, char)

/**
 * \brief Macro que assiste na inicialização das funções CreateData.
 * Devolve um Data com o argumento val guardado na memória de endereço void*,
 * e com o tipo respetivo à função.
 */
#define CreateData(_name, _type)                       \
    Data CreateData##_name(_type val) {                \
        _type *vp = (_type*) malloc(sizeof(_type));    \
        *vp = val;                                     \
        Data op = {_name, vp};                         \
        return op;                                     \
    }
/** Inicialização da função algorítmica CreateDataCHAR. */
CreateData(CHAR, char)
/** Inicialização da função algorítmica CreateDataLONG. */
CreateData(LONG, long)
/** Inicialização da função algorítmica CreateDataDOUBLE. */
CreateData(DOUBLE, double)

/**
 * \brief Função que cria um Data com o Tipo STRING.
 * @param val Endereço da string a se guardar.
 * @return devolve um Data do Tipo STRING.
 */
Data CreateDataSTRING(char *val) {
    char *vp = strdup(val);
    Data op = {STRING, vp};
    return op;
}

/**
 * \brief Função que converte um Data com qualquer Tipo num Data com Tipo DOUBLE.
 * @param d Endereço de um Data.
 */
void DataToDOUBLE(Data *d) {
    double val;
    switch (d->tipo){
    case CHAR:
    case LONG:{
        val = (double) *(DataValLONG(d));
        *d = CreateDataDOUBLE(val);
        break;
    }
    case STRING:{
        val = strtod(DataValCHAR(d), NULL);
        *d = CreateDataDOUBLE(val);
        break;
    }
    default:
        d->tipo = DOUBLE;
        break;
    }
}

/**
 *\brief Função que converte um Data com qualquer Tipo num Data com Tipo LONG.
 * @param d Endereço de um Data
 */
void DataToLONG(Data *d) {
    long val;
    switch (d->tipo){
        case STRING:{
            val = strtol(DataValCHAR(d), NULL, 10);
            *d = CreateDataLONG(val);
            break;
        }
        case DOUBLE: {
            val = (long) *(DataValDOUBLE(d));
            *d = CreateDataLONG(val);
            break;
        }
        default:
            d->tipo = LONG;
            break;
    }
}

/**
 * \brief Função que duplica um Data.
 *
 * @param target Endereço de um Data.
 * @return Devolve o duplo do Data.
 */
Data DataDup(Data *target) {
    Data data;
    switch (target->tipo) {
        case LONG: {
            long val = *DataValLONG(target);
            data = CreateDataLONG(val);
            break;
        }
        case DOUBLE: {
            double val = *DataValDOUBLE(target);
            data = CreateDataDOUBLE(val);
            break;
        }
        case CHAR: {
            char val = *DataValCHAR(target);
            data = CreateDataCHAR(val);
            break;
        }
        case STRING: {
            char* val = DataValSTRING(target);
            data = CreateDataSTRING(val);
            break;
        }
    }
    return data;
}