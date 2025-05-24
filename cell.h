#pragma once

#include "produto.h"

struct cell_t;

/**
 * @brief Guarda o produto e encadeia o proximo produto
 */
typedef struct cell_t Cell;

/**
 * @brief Cria uma celula de lista encadeada alocada dinamicamente.
 * @param value Produto previamente criado
 * @returns Celula que deve ser liberada no futuro
 */
Cell *CreateCell(Produto *value);

/**
 * @param cell Celula previamente criada
 * @returns O produto que a celula guarda
 */
Produto *GetValue(Cell *cell);

/**
 * @param cell Celula previamente criada
 * @returns A proxima celula da celula atual
 */
Cell *GetNext(Cell *cell);

/**
 * @brief Define o produto de uma celula
 * @param cell Celula previamente criada
 * @param value Produto criado
 */
void SetValue(Cell *cell, Produto *value);

/**
 * @brief Define a proxima celula de uma celula atual
 * @param cell Celula previamente criada
 * @param next Proxima celula a ser encadeada
 */
void SetNext(Cell *cell, Cell *next);

/**
 * @param cell Celula que ainda nao foi liberada
 */
void FreeCell(Cell *cell);

/**
 * @param cell Celula previamente criada
 * @returns Se a celula e a ultima em uma lista encadeada
 */
int IsLast(Cell *cell);