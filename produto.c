#include "produto.h"
#include <stdio.h>
#include <stdlib.h>

struct produto_t
{
    int codigo;
    char *nome;
    float preco;
};

Produto *CreateProduto(int codigo, char *nome, float preco)
{
    Produto *produto = malloc(sizeof(Produto));

    produto->codigo = codigo;
    produto->nome = nome;
    produto->preco = preco;

    return produto;
}

Produto *ReadProduto()
{
    int codigo = 0;
    char *nome = malloc(256 * sizeof(char));
    float preco = 0;

    printf("QUAL O CODIGO DO PRODUTO?\n");
    scanf(" %d", &codigo);
    printf("QUAL O NOME DO PRODUTO?\n");
    scanf(" %255[^\n]", nome);
    printf("QUAL O PRECO DO PRODUTO?\n");
    scanf(" %f", &preco);

    return CreateProduto(codigo, nome, preco);
}

int GetCodigoProduto(Produto *produto)
{
    return produto->codigo;
}

char *GetNomeProduto(Produto *produto)
{
    return produto->nome;
}

float GetPrecoProduto(Produto *produto)
{
    return produto->preco;
}

void FreeProduto(Produto *produto)
{
    free(produto->nome);
    free(produto);
}

void PrintProduto(Produto *produto)
{
    printf("- PRODUTO -\n");
    printf("CODIGO: %d\n", produto->codigo);
    printf("NOME: %s\n", produto->nome);
    printf("PRECO: %.2f\n", produto->preco);
    printf("-----------\n");
}

int MesmoCodigoProduto(Produto *produto, int codigo)
{
    return produto->codigo == codigo;
}