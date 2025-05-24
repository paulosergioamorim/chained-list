#include "list.h"
#include "cell.h"
#include <stdlib.h>
#include <stdio.h>

struct list_t
{
    Cell *first;
    Cell *last;
};

int IsEmpty(List *list)
{
    return !list->first;
}

int Count(List *list)
{
    if (IsEmpty(list))
    {
        return 0;
    }

    int count = 0;
    Cell *cur = list->first;

    while (1)
    {
        count++;

        if (IsLast(cur))
        {
            break;
        }

        cur = GetNext(cur);
    }

    return count;
}

List *CreateList()
{
    List *list = malloc(sizeof(List));
    list->first = list->last = NULL;

    return list;
}

void Append(List *list, Produto *value)
{
    Cell *cell = CreateCell(value);

    if (!list->last)
    {
        list->first = list->last = cell;
        return;
    }

    SetNext(list->last, cell);
    list->last = cell;
}

void Prepend(List *list, Produto *value)
{
    Cell *cell = CreateCell(value);

    if (!list->first)
    {
        list->first = list->last = cell;
        return;
    }

    SetNext(cell, list->first);
    list->first = cell;
}

void Insert(List *list, Produto *value, int index)
{
    if (index == 0)
    {
        Prepend(list, value);
        return;
    }

    int count = Count(list);

    if (index >= count)
    {
        Append(list, value);
        return;
    }

    Cell *prev = NULL;
    Cell *cur = list->first;
    Cell *newCell = CreateCell(value);

    for (int i = 0; i < index; i++)
    {
        prev = cur;
        cur = GetNext(cur);
    }

    SetNext(prev, newCell);
    SetNext(newCell, cur);
}

void Remove(List *list, int codigo)
{
    if (IsEmpty(list))
    {
        return; // list is empty
    }

    Cell *prev = NULL;
    Cell *cur = list->first;

    while (1)
    {
        if (MesmoCodigoProduto(GetValue(cur), codigo))
            break;

        if (IsLast(cur))
            return; // not found element

        prev = cur;
        cur = GetNext(cur);
    }

    if (cur == list->first)
    {
        list->first = GetNext(cur);
        FreeCell(cur);
        return;
    } // first element

    if (cur == list->last)
    {
        list->last = prev;
        SetNext(prev, NULL);
        FreeCell(cur);
        return;
    } // last element

    SetNext(prev, GetNext(cur));
    FreeCell(cur); // middle element
}

Produto *Find(List *list, int codigo)
{
    if (IsEmpty(list))
    {
        return NULL; // list is empty
    }

    Cell *prev = NULL;
    Cell *cur = list->first;

    while (1)
    {
        if (MesmoCodigoProduto(GetValue(cur), codigo))
            break;

        if (IsLast(cur))
            return NULL; // not found element

        prev = cur;
        cur = GetNext(cur);
    }

    return GetValue(cur);
}

Produto *GetFirst(List *list)
{
    return GetValue(list->first);
}

Produto *GetLast(List *list)
{
    return GetValue(list->last);
}

void PrintList(List *list)
{
    for (Cell *cur = list->first; cur; cur = GetNext(cur))
    {
        PrintProduto(GetValue(cur));
    }

    printf("\n");
}

void FreeList(List *list)
{
    Clear(list);
    free(list);
}

void Clear(List *list)
{
    if (IsEmpty(list))
    {
        return;
    }

    Cell *prev = NULL;
    Cell *cur = list->first;

    while (1)
    {
        if (IsLast(cur))
        {
            FreeCell(cur);
            break;
        }

        prev = cur;
        cur = GetNext(cur);
        FreeCell(prev);
    }

    list->first = NULL;
}
