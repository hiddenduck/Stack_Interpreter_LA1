
/**
 * @file data.c
 */
#include "data.h"

/** \brief Inicialização da função CreateDataCHAR.
 *
 * @param val Valor char a colocar no Data.
 * @return Data criado com o valor.
 */
Data CreateDataCHAR(char val) {
        char *vp = (char*) malloc(sizeof(char));
        *vp = val;
        Data op = {vp, CHAR};
        return op;
}
/** \brief Inicialização da função CreateDataLONG.
 *
 * @param val Valor long a colocar no Data.
 * @return Data criado com o valor.
 */
Data CreateDataLONG(long val) {
    long *vp = (long*) malloc(sizeof(long));
    *vp = val;
    Data op = {vp, LONG};
    return op;
}
/** \brief Inicialização da função CreateDataDOUBLE.
 *
 * @param val Valor double a colocar no Data.
 * @return Data criado com o valor.
 */
Data CreateDataDOUBLE(double val) {
    double *vp = (double*) malloc(sizeof(double));
    *vp = val;
    Data op = {vp, DOUBLE};
    return op;
}

/**
 * \brief Função que cria um Data com o Tipo STRING.
 * @param val Endereço da string a se guardar.
 * @return devolve um Data do Tipo STRING.
 */
Data CreateDataSTRING(char *val) {
    char *vp = strdup(val);
    Data op = {vp, STRING};
    return op;
}

/**
 * \brief Função que cria um Data com o Tipo STACK.
 * @param stack Endereço da stack.
 * @return devolve um Data do Tipo STACK.
 */
Data CreateDataSTACK(Stack *stack) {
    //talvez seja preciso fazer um stack dup, ter cuidado com a existência destas
    Data op = {stack, STACK};
    return op;
}

/**
 * \brief Função que cria um Data com o Tipo BLOCK.
 * @param val Endereço da string a se guardar.
 * @return devolve um Data do Tipo BLOCK.
 */
Data CreateDataBLOCK(char *val) {
    char *vp = strdup(val);
    Data op = {vp, BLOCK};
    return op;
}

/**
 * \brief Função que cria um Data com o Tipo LONG LONG.
 * @param val Valor long long a colocar no Data.
 * @return devolve um Data do Tipo LONG LONG.
 */
Data CreateDataLONGLONG(long long val) {
    long long *vp = (long long*) malloc(sizeof(long long));
    *vp = val;
    Data op = {vp, LONGLONG};
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
            break;
        }
        case STRING:{
            val = strtod(DataValCHAR(d), NULL);
            break;
        }
        case LONGLONG: {
            val = (double) *(DataValLONGLONG(d));
            break;
        }
        default:
            return;
    }
    double *vp = (double *) realloc(d->value, sizeof(double));
    *vp = val;
    d->value = vp;
    d->tipo = DOUBLE;
}

/**
 * \brief Função que converte um Data com qualquer Tipo num Data com Tipo LONG.
 * @param d Endereço de um Data
 */
void DataToLONG(Data *d) {
    long val;
    switch (d->tipo){
        case CHAR: {
            val = *DataValCHAR(d);
            break;
        }
        case STRING:{
            val = strtol(DataValCHAR(d), NULL, 10);
            break;
        }
        case DOUBLE: {
            val = *(DataValDOUBLE(d));
            break;
        }
        case LONGLONG: {
            val = *(DataValLONGLONG(d));
            break;
        }
        default:
            return;
    }
    long *vp = (long *) realloc(d->value, sizeof(long));
    *vp = val;
    d->value = vp;
    d->tipo = LONG;
}

void DataToLONGLONG(Data *d) {
    long long val;
    switch (d->tipo){
        case CHAR: {
            val = *DataValCHAR(d);
            break;
        }
        case STRING:{
            val = strtoll(DataValCHAR(d), NULL, 10);
            break;
        }
        case DOUBLE: {
            val = *(DataValDOUBLE(d));
            break;
        }
        case LONGLONG: {
            val = *(DataValLONGLONG(d));
            break;
        }
        case LONG: {
            val = *(DataValLONG(d));
            break;
        }
        default:
            return;
    }
    long long *vp = (long long*) realloc(d->value, sizeof(long long));
    *vp = val;
    d->value = vp;
    d->tipo = LONGLONG;
}

/**
 * \brief Função que converte um Data com qualquer Tipo num Data com Tipo CHAR.
 * @param d Endereço de um data
 */
void DataToCHAR(Data *d) {
    switch (d->tipo) {
        case STRING: {
            char val = *DataValCHAR(d);
            char *vp = (char *) realloc(d->value, sizeof(char));
            *vp = val;
            d->value = vp;
            break;
        }
        case CHAR:
            break;
        default: {
            DataToLONG(d);
            break;
        }
    }
    d->tipo = CHAR;
}

/** \brief Função que auxilia o DataToSTRING.
 *  @param buffer Endereço do buffer.
 *  @param d Endereço do Data a ser convertido.
 */
char *DataToSTRINGaux (char *buffer, Data *d) {
    int i;
    for(i=0; i<= (DataValSTACK(d))->sp; i++) {
        Data d1 = (DataValSTACK(d))->array[i];
        DataToSTRING(&d1);
        strcat(buffer, DataValSTRING(&d1));
    }
    return buffer;
}

/**
 * \brief Função que converte um Data com qualquer Tipo num Data com Tipo STRING.
 * @param d Endereço de um data
 */
void DataToSTRING(Data *d) {
    char buffer[MAX_LENGTH_INPUT] = "\0";
    switch (d->tipo) {
        case LONG: {
            sprintf(buffer, "%ld", *DataValLONG(d));
            break;
        }
        case DOUBLE: {
            sprintf(buffer, "%f", *DataValDOUBLE(d));
            break;
        }
        case CHAR: {
            buffer[0] = *DataValCHAR(d);
            break;
        }
        case STACK: {
            strcpy(buffer, DataToSTRINGaux(buffer, d));
            break;
        }
        case LONGLONG: {
            sprintf(buffer, "%lld", *DataValLONGLONG(d));
            break;
        }
        default:
            return;
    }
    char *value;
    value = strdup(buffer);
    d->value = value;
    d->tipo = STRING;
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
            data = CreateDataLONG(*DataValLONG(target));
            break;
        }
        case DOUBLE: {
            data = CreateDataDOUBLE(*DataValDOUBLE(target));
            break;
        }
        case CHAR: {
            data = CreateDataCHAR(*DataValCHAR(target));
            break;
        }
        case STRING: {
            data = CreateDataSTRING(DataValSTRING(target));
            break;
        }
        case STACK: {
            Stack *stack = DupStack(DataValSTACK(target));
            data = CreateDataSTACK(stack);
            break;
        }
        case BLOCK: {
            data = CreateDataBLOCK(DataValSTRING(target));
            break;
        }
        case LONGLONG: {
            data = CreateDataLONGLONG(*DataValLONGLONG(target));
            break;
        }
    }
    return data;
}

/**
 * \brief Função que imprime um certo elemento de acordo com o seu Tipo.
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
            printf("%s", DataValSTRING(data));
            break;
        case STACK:
            PrintStack(DataValSTACK(data));
            break;
        case BLOCK:
            printf("{%s}", DataValSTRING(data));
            break;
        case LONGLONG:
            printf("%lld", *DataValLONGLONG(data));
            break;
    }
}

/** \brief Função que Troca dois Datas.
 *  @param d1 Endereço de um Data.
 *  @param d2 Endereço de um Data.
*/  
void swapData (Data *d1, Data *d2){
    Data temp = *d1;
    *d1 = *d2;
    *d2 = temp; 
}

/** \brief Função que devolve um valor booleano correspondente ao valor do Data dado.
 *
 * @param d1 Endereço de um Data.
 * @return Inteiro booleano.
 */
int GetBoolFromData (Data *d1) {
    long r;
    switch (d1->tipo) {
        case LONG:
            r = (*DataValLONG(d1) != 0);
            break;
        case CHAR:
            r = (*DataValCHAR(d1) != 0);
            break;
        case DOUBLE:
            r = (*DataValDOUBLE(d1) != 0);
            break;
        case STRING:
            r = (strcmp(DataValSTRING(d1), ""));
            break;
        case STACK:
            r = ((DataValSTACK(d1))->sp != -1);
            break;
        case LONGLONG:
            r = (*DataValLONGLONG(d1) != 0);
            break;
        default:
            r = 1;
            break;
    }
    return r;
}

/** \brief Função que prepara o retorno de Datas ao libertar o espaço do primeiro e colocar nele o conteúdo do segundo.
 *
 * @param d1 Data que serve como espaço a se colocar.
 * @param d2 Data a ser guardado.
 */
void swapDataFree(Data *d1, Data *d2) {
    Free(d1);
    //d1->DATA d2(d1)->DATA
    *d1 = *d2;
}

/** \brief Função que dá free a um data e coloca o apontador a NULL.
 *  @param d1 Endereço de um data.
 */
void NullifyData(Data *d1) {
    Free(d1);
    d1 = NULL;
}

/** \brief Função que compara o valor de dois Datas NUMEROS.
 *  @param d1 Endereço de um Data.
 *  @param d2 Endereço de um Data.
 *  @return Diferença entre os valores.
 */
int CompareDataNUMERO(Data *d1, Data *d2) {
    double a, b;
    NumTestD1
    NumTestD2
    return (a-b);
}

/** \brief Função que compara o valor de dois Datas STRING.
 *  @param d1 Endereço de um Data.
 *  @param d2 Endereço de um Data.
 *  @return Diferença entre os valores.
 */
int CompareDataSTRING(Data *d1, Data *d2) {
    return strcmp(DataValSTRING(d1), DataValSTRING(d2));
}

/** \brief Função que compara o valor de dois Datas.
 *  @param d1 Endereço de um Data.
 *  @param d2 Endereço de um Data.
 *  @return Diferença entre os valores.
 */
int CompareData(Data *d1, Data *d2) {
    int r = 0;
    if (d1->tipo == STRING)
        r = CompareDataSTRING(d1, d2);
    else
        r = CompareDataNUMERO(d1,d2);
    return r;
}
