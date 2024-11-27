#pragma once
#include <stddef.h>

void quick_sort(void *arr, int n, size_t elem_size, int (*cmp)(void*, void*));
void swap(void *a, void *b, size_t size);