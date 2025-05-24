#pragma once

struct produto_t;

typedef struct produto_t Produto;

/**
 * @brief Cria um novo produto com um nome previamente alocado.
 */
Produto *CreateProduto(int codigo, char *nome, float preco);

/**
 * @brief Le um produto de stdin
 */
Produto *ReadProduto();

int GetCodigoProduto(Produto *produto);
char *GetNomeProduto(Produto *produto);
float GetPrecoProduto(Produto *produto);

/**
 * Libera um produto da mememória
 */
void FreeProduto(Produto *produto);
void PrintProduto(Produto *produto);

int MesmoCodigoProduto(Produto *produto, int codigo);