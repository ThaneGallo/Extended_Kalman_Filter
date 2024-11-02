#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include <stdint.h>


typedef struct Matrix
{
    uint8_t rows;
    uint8_t cols;
    double **m;
} Matrix;


Matrix *create_matrix(int rows, int cols);

void free_matrix(Matrix *M, int rows);

Matrix *add_matrix(Matrix *a, Matrix *b);

Matrix *transpose_matrix(Matrix *input);

Matrix *multiply_matrix(Matrix *a, Matrix *b);

void print_matrix(Matrix *M);
