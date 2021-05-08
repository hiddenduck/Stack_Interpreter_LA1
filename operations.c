/**
 * @file operations.c
 */
#include "operations.h"

//acho que temos de alterar estas funções para serem auxiliares de algébricas
//criar auxiliares para outros tipos, apesar de que as logicas podem usar estas na mesma

/**
 * \brief Função que auxilia funções sem argumentos.
 * @param operation Endereço de uma função sem argumentos.
 * @param stack Endereço da \a stack responsável pelo armazenamento.
 */
void SemArgumentos(Operation operation, Stack *stack) {
    operation(stack);
}

/**
 * \brief Função que auxilia funções de um argumento.
 * @param operation Endereço de uma função com um argumento.
 * @param stack Endereço da \a stack responsável pelo armazenamento.
 */
void UmArgumento(Operation operation, Stack *stack) {
    Data d1 = Pop(stack);
    (*operation)(&d1, stack);
    Push(d1, stack);
}

/**
 * \brief Função que auxilia funções de dois argumentos.
 * @param operation Endereço de uma função com dois argumentos.
 * @param stack Endereço da \a stack responsável pelo armazenamento.
 */
void DoisArgumentos(Operation operation, Stack *stack) {
    Data d2 = Pop(stack), d1 = Pop(stack);
    (*operation)(&d1, &d2, stack);
    Push(d1, stack);
    Free(&d2);
}

/** \brief Função que realiza a soma entre dois Datas LONG LONG.
 *  @param d1 Endereço de um Data LONG LONG.
 *  @param d2 Endereço de um Data LONG LONG.
 */
void somaLongLong(Data *d1, Data *d2) {
    long long a, b;
    NumTestD1
    NumTestD2
    long long res = a + b;
    if (res < LONG_MAX && res > LONG_MIN) {
        if (d1->tipo != LONG)
            DataToLONG(d1);
        *DataValLONG(d1) = (long) res;
    } else {
        if (d1->tipo != LONGLONG)
            DataToLONGLONG(d1);
        *DataValLONGLONG(d1) = res;
    }
}

void somaDouble(Data *d1, Data *d2) {
    double a, b, res;
    NumTestD1
    NumTestD2
    res = a + b;
    if (d1->tipo != DOUBLE)
        DataToDOUBLE(d1);
    *DataValDOUBLE(d1) = res;
}

/**
 * \brief Função que realiza a soma de dois Datas.
 * @param d1 Endereço de um operando.
 * @param d2 Endereço de um operando.
 */
void soma(Data *d1, Data *d2) {
    if ((d1->tipo|d2->tipo) & (LONG | LONGLONG))
        somaLongLong(d1, d2);
    else
        somaDouble(d1, d2);
}

/** \brief Função que realiza a subtração entre dois Datas LONG LONG.
 *  @param d1 Endereço de um Data LONG LONG.
 *  @param d2 Endereço de um Data LONG LONG.
 */
void subtrLongLong(Data *d1, Data *d2) {
    long long a, b;
    NumTestD1
    NumTestD2
    long long res = a - b;
    DataToLONGLONG(d1);
    *DataValLONGLONG(d1) = res;
}

/**
 * \brief Função que realiza a subtração de dois Datas.
 * @param d1 Endereço de um operando.
 * @param d2 Endereço de um operando.
 */
void subtr(Data *d1, Data *d2) {
    if ((d1->tipo&d2->tipo) == LONG) {
        long long a,b,res;
        NumTestD1
        NumTestD2
        res = a - b;
        if (res < LONG_MAX && res > LONG_MIN)
            *DataValLONG(d1) = (long) res;
        else {
            DataToLONGLONG(d1);
            *DataValLONGLONG(d1) = res;
        }
    }
    else if ((d1->tipo|d2->tipo)&LONGLONG)
        subtrLongLong(d1, d2);
    else {
        DataToDOUBLE(d1);
        double a, b, res;
        NumTestD1
        NumTestD2
        res = a - b;
        if (d1->tipo != DOUBLE)
            DataToDOUBLE(d1);
        *DataValDOUBLE(d1) = res;
    }
}

/**
 * \brief Função que realiza a multiplicação de dois Datas LONG LONG.
 * @param d1 Endereço de um operando.
 * @param d2 Endereço de um operando.
 */
void multLongLong(Data *d1, Data *d2){
    long long a, b;
    NumTestD1
    NumTestD2
    long long res = a * b;
    DataToLONGLONG(d1);
    *DataValLONGLONG(d1) = res;
}

/** \brief Função que realiza a soma entre dois Datas LONG LONG.
 *  @param d1 Endereço de um Data LONG LONG.
 *  @param d2 Endereço de um Data LONG LONG.
 */
void mult(Data *d1, Data *d2) {
    if ((d1->tipo&d2->tipo) == LONG) {
        long long a,b,res;
        NumTestD1
        NumTestD2
        res = a * b;
        if (res < LONG_MAX && res > LONG_MIN)
            *DataValLONG(d1) = (long) res;
        else {
            DataToLONGLONG(d1);
            *DataValLONGLONG(d1) = res;
        }
    }
    else if ((d1->tipo|d2->tipo)&LONGLONG)
        multLongLong(d1, d2);
    else {
        DataToDOUBLE(d1);
        double a, b, res;
        NumTestD1
        NumTestD2
        res = a * b;
        if (d1->tipo != DOUBLE)
            DataToDOUBLE(d1);
        *DataValDOUBLE(d1) = res;
    }
}


/**
 * \brief Função que realiza a divisão de dois Datas LONG LONG.
 * @param d1 Endereço do dividendo.
 * @param d2 Endereço do divisor.
 */

void diviLongLong(Data *d1, Data *d2){
    long long a, b;
    NumTestD1
    NumTestD2
    long long res = a / b;
    DataToLONGLONG(d1);
    *DataValLONGLONG(d1) = res;
}

/** \brief Função que realiza a soma entre dois Datas.
 *  @param d1 Endereço de um Data.
 *  @param d2 Endereço de um Data.
 */
void divi(Data *d1, Data *d2) {
    if ((d1->tipo&d2->tipo) == LONG) {
        long long a,b,res;
        NumTestD1
        NumTestD2
        res = a / b;
        if (res < LONG_MAX && res > LONG_MIN)
            *DataValLONG(d1) = (long) res;
        else {
            DataToLONGLONG(d1);
            *DataValLONGLONG(d1) = res;
        }
    }
    else if ((d1->tipo|d2->tipo)&LONGLONG)
        diviLongLong(d1, d2);
    else {
        DataToDOUBLE(d1);
        double a, b, res;
        NumTestD1
        NumTestD2
        res = a / b;
        if (d1->tipo != DOUBLE)
            DataToDOUBLE(d1);
        *DataValDOUBLE(d1) = res;
    }
}

/**
 * \brief Função que incrementa um Data por 1.
 * @param d1 Endereço de um Data cujo valor vai ser incrementado.
 */
void incre(Data *d1) {
    switch (d1->tipo) {
        case LONG:
            (*DataValLONG(d1))+=1;
            break;
        case DOUBLE:
            (*DataValDOUBLE(d1))+=1;
            break;
        case LONGLONG:
            (*DataValLONGLONG(d1))+=1;
            break;
        case CHAR:
            (*DataValCHAR(d1))+=1;
        default:
            break;
        }
}

/**
 * \brief Função que decrementa um Data por 1.
 * @param d1 Endereço de um Data cujo valor vai ser decrementado.
 */
void decre(Data *d1) {
    switch (d1->tipo) {
        case LONG:
            (*DataValLONG(d1))-=1;
            break;
        case DOUBLE:
            (*DataValDOUBLE(d1))-=1;
            break;
        case LONGLONG:
            (*DataValLONGLONG(d1))-=1;
            break;
        case CHAR:
            (*DataValCHAR(d1))-=1;
        default:
            break;
    }
}

/**
 * \brief Função que faz o E Bitwise.
 * @param d1 Endereço de um Data.
 * @param d2 Endereço de um Data.
 */
void and(Data *d1, Data *d2) {
    long a, b;
    NumTestD1
    NumTestD2
    DataToLONG(d1);
    *(DataValLONG(d1)) = (a & b);
}
/**
 * \brief Função que faz o OU Bitwise.
 * @param d1 Endereço de um Data.
 * @param d2 Endereço de um Data.
 */
void or(Data *d1, Data *d2) {
    long a, b;
    NumTestD1
    NumTestD2
    DataToLONG(d1);
    *(DataValLONG(d1)) = (a | b);
}
/**
 * \brief Função que faz o XOR Bitwise.
 * @param d1 Endereço de um Data.
 * @param d2 Endereço de um Data.
 */
void xor(Data *d1, Data *d2) {
    long a, b;
    NumTestD1
    NumTestD2
    DataToLONG(d1);
    *(DataValLONG(d1)) = (a ^ b);
}
/** \brief Inicialização da função modulo.
 *
 * @param d1 Endereço do Dividendo.
 * @param d2 Endereço do divisor.
 */
void modulo(Data *d1, Data *d2) {
    long a, b;
    NumTestD1
    NumTestD2
    DataToLONG(d1);
    *(DataValLONG(d1)) = (a % b);
}

/**
 * \brief Função que calcula a potência de base Data d1 e expoente Data d2 e guarda o resultado no d2.
 * @param d1 Endereço da base.
 * @param d2 Endereço do expoente.
 */
void potencia(Data *d1, Data *d2) {
    //cuidado em manter os dois tipos intactos se forem ambos long
    switch (d1->tipo&d2->tipo) {
        case LONG:
            *(DataValLONG(d1)) = (long) pow(*DataValLONG(d1), *DataValLONG(d2));
            break;
        default:
            DataToDOUBLE(d1);
            double *p = DataValDOUBLE(d1);
            switch (d2->tipo) {
                case LONG:
                    *p = pow(*p, *DataValLONG(d2));
                    break;
                case DOUBLE:
                    *p = pow(*p, *DataValDOUBLE(d2));
                    break;
                default:
                    break;
            }
            break;
    }
}

/**
 * \brief Função que inverte os bits de um certo Data do Tipo LONG.
 * @param d Endereço de um Data do Tipo LONG.
*/
void notBW(Data *d1) {
    long a;
    NumTestD1
    DataToLONG(d1);
    *DataValLONG(d1) = ~a;
}

/**
 * \brief Função que duplica o elemento no topo da \a stack.
 * @param stack Endereço da \a stack responsável pelo armazenamento.
 */
void Underscore(Stack *stack) {
    Data *x = Read(0, stack);
    Data y = DataDup(x);
    Push(y, stack);
}

/**
 * \brief Função que troca o elemento do topo da \a stack com o elemento na posição sp-1.
 * @param stack Endereço da \a stack responsável pelo armazenamento.
 */
void Swap(Stack *stack) {
    Data y = Pop(stack);
    Data x = Pop(stack);
    Push(y, stack);
    Push(x, stack);
}

/**
 * \brief Função que troca o elemento do topo da \a stack, o da posição sp-1 e o da posição sp-2.
 * @param stack Endereço da \a stack responsável pelo armazenamento.
 */
void SwapThree(Stack *stack) {
    Data z = Pop(stack);
    Data y = Pop(stack);
    Data x = Pop(stack);
    Push(y, stack);
    Push(z, stack);
    Push(x, stack);
}

/**
 * \brief Função que coloca no topo da \a stack o elemento no indice n.
 * @param stack Endereço da \a stack responsável pelo armazenamento.
 */
void DollarSign(Data *d1, Stack *stack) {
    long a;
    NumTestD1
    Data *x = Read(a, stack);
    Data y = DataDup(x);
    swapDataFree(d1, &y);
}

/**
 * \brief Função que lê uma nova linha e coloca-a na \a stack.
 * @param stack Endereço da \a stack responsável pelo armazenamento.
 */
void ReadLine(Stack *stack) {
    char linha[MAX_LENGTH_INPUT];
    assert(fgets(linha, MAX_LENGTH_INPUT, stdin) != NULL);
    int len = strlen(linha) - 1;
    assert(linha[len] == '\n');
    linha[len] = '\0';
    Push(CreateDataSTRING(linha), stack);
}

/** \brief Função que copia o topo da stack à variável.
 *  @param stack Endereço da \a stack responsável pelo armazenamento.
 *  @param vars Endereço da \a vars responsável pelo armazenamento das variáveis.
 *  @param token Char correspondente à variável.
*/
int TwoPoints (Stack *stack, Stack *vars, char token){
    Data *letter = Read(64 - token, vars);
    Data *valor = Read(0,stack);
    Data temp = DataDup(valor);
    swapDataFree(letter, &temp);
    return 1;
}
