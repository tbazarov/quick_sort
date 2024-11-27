#include "quick_sort_declars.h"
#include "quick_sort_cmps.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void quick_sort(void* arr, int n, size_t elem_size, int (*cmp)(void*, void*)) 
{
    if (n <= 1) return;
    void* pivot = arr;
    int i = 1;
    int j = n - 1;
    while (i <= j) 
    {
        while (i <= j && cmp((char*)arr + i * elem_size, pivot) <= 0) i++;
        while (i <= j && cmp((char*)arr + j * elem_size, pivot) > 0) j--;
        if (i <= j) swap((char*)arr + i * elem_size, (char*)arr + j * elem_size, elem_size);
        i++;
        j--;
    }
    swap((char*)arr, (char*)arr + j * elem_size, elem_size);
    quick_sort(arr, j, elem_size, cmp);
    quick_sort((char*)arr + (j + 1) * elem_size, n - j - 1, elem_size, cmp);
}

void swap(void *a, void *b, size_t size) {
    void *temp = malloc(size);
    if (temp == NULL) {
        perror("Ошибка выделения памяти");
        exit(EXIT_FAILURE);
    }
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
    free(temp);
}
