#include "quick_sort_declars.h"
#include "quick_sort_cmps.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void fill_arr_int(int *arr_int, size_t size); 
void fill_arr_float(float *arr_float, size_t size);
void fill_arr_char(char *arr_char, size_t size);
int is_sorted_int(int *arr_int, size_t size); 
int is_sorted_float(float *arr_float, size_t size);
int is_sorted_char(char *arr_char, size_t size);

int main()
{
    srand(time(NULL));
    int size = rand() % 10000 + 1;
    int *arr_int = malloc(size * sizeof(int));
	float *arr_float = malloc(size * sizeof(float));
	char *arr_char = malloc(size * sizeof(char));

    fill_arr_int(arr_int, size);
	fill_arr_float(arr_float, size);
	fill_arr_char(arr_char, size);
    
	quick_sort(arr_int, size, sizeof(int), compare_int);
	quick_sort(arr_float, size, sizeof(float), compare_float);
	quick_sort(arr_char, size, sizeof(char), compare_char);
    
	printf("%d\n", is_sorted_int(arr_int, size));
	printf("%d\n", is_sorted_float(arr_float, size));
	printf("%d\n", is_sorted_char(arr_char, size));

    char *string_array[] = {"banana", "tsar-bimba", "orange", "fignya", "chechevitsa"};
    int string = sizeof(string_array) / sizeof(string_array[0]);
    quick_sort(string_array, string, sizeof(char *), compare_string);
    printf("Sorted strings: ");
    for (int i = 0; i < string; i++) 
    {
        printf("%s ", string_array[i]);
    }

    free(arr_int);
	free(arr_float);
	free(arr_char);

    return 0;
}

void fill_arr_int(int *arr_int, size_t size)
{
    for (int i = 0; i < size; i++)
    {
        arr_int[i] = rand() % 100;
    }
}

void fill_arr_float(float *arr_float, size_t size)
{
	for (int i = 0; i < size; i++)
	{
		arr_float[i] = rand() % 100;
	}
}

void fill_arr_char(char *arr_char, size_t size)
{
	for (int i = 0; i < size; i++)
	{
		arr_char[i] = rand() % 100;
	}
}

int is_sorted_int(int *arr_int, size_t size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (((int*)arr_int)[i] > ((int*)arr_int)[i + 1])
        {
            return 0;  // фигня
        }
    }
    return 1; // чётко
}

int is_sorted_float(float *arr_float, size_t size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (((float*)arr_float)[i] > ((float*)arr_float)[i + 1])
        {
            return 0;  // фигня
        }
    }
    return 1; // чётко
}

int is_sorted_char(char *arr_char, size_t size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (((char*)arr_char)[i] > ((char*)arr_char)[i + 1])
        {
            return 0;  // фигня
        }
    }
    return 1; // чётко
}