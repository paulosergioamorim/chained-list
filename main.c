#include "list.h"
#include <stdio.h>
#include <time.h>

int ReadOperation();

void PrintMenu();

void SwitchOperation(List *list, int op);

int main(int argc, char const *argv[])
{
    List *list = CreateList();

    while (1)
    {
        PrintMenu();

        int op = ReadOperation();

        if (op == 0)
            break;

        SwitchOperation(list, op);
    }

    FreeList(list);

    return 0;
}

void PrintMenu()
{
    printf("--- MENU ---\n");
    printf("0 - SAIR\n");
    printf("1 - CADASTRAR PRODUTO NO INICIO\n");
    printf("2 - CADASTRAR PRODUTO NO FIM\n");
    printf("3 - CADASTRAR PRODUTO NO MEIO\n");
    printf("4 - REMOVER PRODUTO\n");
    printf("5 - QUANTIDADE DE PRODUTOS\n");
    printf("6 - IMPRIMIR PRODUTOS\n");
    printf("7 - LIMPAR LISTA\n");
    printf("8 - BUSCAR PRODUTO\n");
    printf("------------\n");
}

int ReadOperation()
{
    int op = 0;
    scanf("%d", &op);

    return op;
}

void SwitchOperation(List *list, int op)
{
    Produto *produto = NULL;
    int codigo = 0;
    int index = 0;

    switch (op)
    {
    case 0:
        return;
    case 1:
        produto = ReadProduto();
        Prepend(list, produto);
        return;
    case 2:
        produto = ReadProduto();
        Append(list, produto);
        return;
    case 3:
        produto = ReadProduto();
        printf("INSIRA O ÍNDICE PARA INSERIR (0 a %d)\n", Count(list));
        scanf("%d", &index);
        Insert(list, produto, index);
        return;
    case 4:
        printf("INSIRA O CODIGO DO PRODUTO PARA REMOVER\n");
        scanf("%d", &codigo);
        Remove(list, codigo);
        return;
    case 5:
        printf("QUANTIDADE DE PRODUTOS: %d\n", Count(list));
        return;
    case 6:
        PrintList(list);
        return;
    case 7:
        Clear(list);
        return;
    case 8:
        printf("INSIRA O CODIGO DO PRODUTO PARA BUSCAR\n");

        scanf("%d", &codigo);

        produto = Find(list, codigo);

        if (!produto)
        {
            printf("PRODUTO NÃO ENCONTRADO\n");
            return;
        }

        PrintProduto(produto);
        return;
    }
}