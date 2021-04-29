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
    Data *d1 = Read(0, stack);
    (*operation)(d1);
}

/**
 * \brief Função que auxilia funções de dois argumentos.
 * @param operation Endereço de uma função com dois argumentos.
 * @param stack Endereço da \a stack responsável pelo armazenamento.
 */
void DoisArgumentos(Operation operation, Stack *stack) {
    Data d2 = Pop(stack), d1 = Pop(stack);
    (*operation)(&d1, &d2);
    Push(d1, stack);
    free(d2.value);
}

/**
 * \brief Função que realiza a soma de dois Datas.
 * @param d1 Endereço de um operando.
 * @param d2 Endereço de um operando.
 */
void soma(Data *d1, Data *d2) {
    switch ((d1->tipo)&(d2->tipo)) {
        case LONG:
            *(DataValLONG(d1)) = ((*(DataValLONG(d1))) + (*(DataValLONG(d2))));
            break;
        default:
            DataToDOUBLE(d1);
            switch(d2->tipo) {
                case LONG:
                    *(DataValDOUBLE(d1)) = ((*(DataValDOUBLE(d1))) + (*(DataValLONG(d2))));
                    break;
                case DOUBLE:
                    *(DataValDOUBLE(d1)) = ((*(DataValDOUBLE(d1))) + (*(DataValDOUBLE(d2))));
                    break;
                default:
                    break;
            }
        break;
    }
}

/**
 * \brief Função que realiza a subtração de dois Datas.
 * @param d1 Endereço de um operando.
 * @param d2 Endereço de um operando.
 */
void subtr(Data *d1, Data *d2) {
    switch ((d1->tipo)&(d2->tipo)) {
        case LONG:
            *(DataValLONG(d1)) = ((*(DataValLONG(d1))) - (*(DataValLONG(d2))));
            break;
        default:
            DataToDOUBLE(d1);
            switch(d2->tipo) {
                case LONG:
                    *(DataValDOUBLE(d1)) = ((*(DataValDOUBLE(d1))) - (*(DataValLONG(d2))));
                    break;
                case DOUBLE:
                    *(DataValDOUBLE(d1)) = ((*(DataValDOUBLE(d1))) - (*(DataValDOUBLE(d2))));
                    break;
                default:
                    break;
            }
            break;
    }
}

/**
 * \brief Função que realiza a multiplicação de dois Datas.
 * @param d1 Endereço de um operando.
 * @param d2 Endereço de um operando.
 */
void mult(Data *d1, Data *d2) {
    switch ((d1->tipo)&(d2->tipo)) {
        case LONG:
            *(DataValLONG(d1)) = ((*(DataValLONG(d1))) * (*(DataValLONG(d2))));
            break;
        default:
            DataToDOUBLE(d1);
            switch(d2->tipo) {
                case LONG:
                    *(DataValDOUBLE(d1)) = ((*(DataValDOUBLE(d1))) * (*(DataValLONG(d2))));
                    break;
                case DOUBLE:
                    *(DataValDOUBLE(d1)) = ((*(DataValDOUBLE(d1))) * (*(DataValDOUBLE(d2))));
                    break;
                default:
                    break;
            }
            break;
    }
}

/**
 * \brief Função que realiza a divisão de dois Datas.
 * @param d1 Endereço do dividendo.
 * @param d2 Endereço do divisor.
 */
void divi(Data *d1, Data *d2) {
    switch ((d1->tipo)&(d2->tipo)) {
        case LONG:
            *(DataValLONG(d1)) = ((*(DataValLONG(d1))) / (*(DataValLONG(d2))));
            break;
        default:
            DataToDOUBLE(d1);
            switch(d2->tipo) {
                case LONG:
                    *(DataValDOUBLE(d1)) = ((*(DataValDOUBLE(d1))) / (*(DataValLONG(d2))));
                    break;
                case DOUBLE:
                    *(DataValDOUBLE(d1)) = ((*(DataValDOUBLE(d1))) / (*(DataValDOUBLE(d2))));
                    break;
                default:
                    break;
            }
            break;
    }
}

/**
 * \brief Função que incrementa um Data por 1.
 * @param d1 Endereço de um Data cujo valor vai ser incrementado.
 */
void incre(Data *d1) {
    switch (d1->tipo) {
        case LONG:
            (*DataValLONG(d1))++;
            break;
        case DOUBLE:
            (*DataValDOUBLE(d1))++;
            break;
        case CHAR:
            (*DataValCHAR(d1))++;
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
            (*DataValLONG(d1))--;
            break;
        case DOUBLE:
            (*DataValDOUBLE(d1))--;
            break;
        case CHAR:
            (*DataValCHAR(d1))--;
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
    *(DataValLONG(d1)) = (*DataValLONG(d1) & *DataValLONG(d2));
}
/**
 * \brief Função que faz o OU Bitwise.
 * @param d1 Endereço de um Data.
 * @param d2 Endereço de um Data.
 */
void or(Data *d1, Data *d2) {
    *(DataValLONG(d1)) = (*DataValLONG(d1) | *DataValLONG(d2));
}
/**
 * \brief Função que faz o XOR Bitwise.
 * @param d1 Endereço de um Data.
 * @param d2 Endereço de um Data.
 */
void xor(Data *d1, Data *d2) {
    *(DataValLONG(d1)) = (*DataValLONG(d1) ^ *DataValLONG(d2));
}
/** \brief Inicialização da função modulo.
 *
 * @param d1 Endereço do Dividendo.
 * @param d2 Endereço do divisor.
 */
void modulo(Data *d1, Data *d2) {
    *(DataValLONG(d1)) = (*DataValLONG(d1) % *DataValLONG(d2));
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
void notBW(Data *d) {
    *DataValLONG(d) = ~*(DataValLONG(d));
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
void DollarSign(Stack *stack) {
    Data indice = Pop(stack);
    Data *x = Read(*(DataValLONG(&indice)), stack);
    Data y = DataDup(x);
    Push(y, stack);
    free(indice.value);
}

/**
 * \brief Função que lê uma nova linha e coloca-a na \a stack.
 * @param stack Endereço da \a stack responsável pelo armazenamento.
 */
void ReadLine(Stack *stack) {
    char linha[MAX_LENGTH_INPUT];
    assert(fgets(linha, MAX_LENGTH_INPUT, stdin) != NULL);
    assert(linha[strlen(linha) - 1] == '\n');
    Push(CreateDataSTRING(linha), stack);
}

/** \brief Função que copia o topo da stack à variável.
 *  @param stack Endereço da \a stack responsável pelo armazenamento.
 *  @param vars Endereço da \a vars responsável pelo armazenamento das variáveis.
 *  @param token Char correspondente à variável.
*/
void TwoPoints (Stack *stack, Stack *vars, char token){
    //limpar isto (MI)
    Data *letter = Read(64 - token, vars);
    Data *valor = Read(0,stack);
    *letter = DataDup(valor);
}
