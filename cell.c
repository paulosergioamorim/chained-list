#include "cell.h"

#include <stdlib.h>

struct cell_t
{
    Produto *value;
    Cell *next;
};

Cell *CreateCell(Produto *value)
{
    Cell *cell = malloc(sizeof(Cell));
    cell->value = value;
    cell->next = NULL;

    return cell;
}

Produto *GetValue(Cell *cell)
{
    return cell->value;
}

Cell *GetNext(Cell *cell)
{
    return cell->next;
}

void SetValue(Cell *cell, Produto *value)
{
    cell->value = value;
}

void SetNext(Cell *cell, Cell *next)
{
    cell->next = next;
}

void FreeCell(Cell *cell)
{
    FreeProduto(cell->value);
    free(cell);
}

int IsLast(Cell *cell)
{
    return !cell->next;
}