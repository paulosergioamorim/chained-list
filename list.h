#pragma once
#include "produto.h"

struct list_t;

typedef struct list_t List;

List *CreateList();

int IsEmpty(List *list);

int Count(List *list);

void Append(List *list, Produto *value);

void Prepend(List *list, Produto *value);

void Insert(List *list, Produto *value, int index);

void Remove(List *list, int codigo);

Produto *Find(List *list, int codigo);

Produto *GetFirst(List *list);

Produto *GetLast(List *list);

void PrintList(List *list);

void FreeList(List *list);

void Clear(List *list);
