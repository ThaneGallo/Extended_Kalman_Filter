

#include "matrix.h"

Matrix *create_matrix(int rows, int cols)
{
    Matrix *M;
    int i;

    M = malloc(sizeof(Matrix));
    if (!M)
    {
        printf("Malloc Failed on line %d", __LINE__);
        free(M);
        return NULL;
    }

    M->m = malloc(sizeof(double *) * rows);
    if (!M->m)
    {
        printf("Malloc Failed on line %d", __LINE__);
        free(M->m);
        return NULL;
    }
    for (i = 0; i < rows; i++)
    {
        M->m[i] = malloc(sizeof(double) * cols);
        if (!M->m[i])
        {
            printf("Malloc Failed on line %d", __LINE__);
            for (i = 0; i < rows; i++)
            {
                free(M->m[i]);
            }
            free(M->m);
            free(M);
        }
    }

    M->rows = rows;
    M->cols = cols;

    return M;
}

void free_matrix(Matrix *M, int rows)
{
    if (M)
    {
        for (int i = 0; i < rows; i++)
        {
            free(M->m[i]);
        }
        free(M->m);
        free(M);
    }
}

Matrix *add_matrix(Matrix *a, Matrix *b)
{
    Matrix *res = create_matrix(a->rows, a->cols);

    for (int i = 0; i < a->rows; i++)
    {
        for (int j = 0; j < a->cols; j++)
        {
            res->m[i][j] = a->m[i][j] + b->m[i][j];
        }
    }

    return res;
}

Matrix *transpose_matrix(Matrix *input)
{
    Matrix *res = create_matrix(input->rows, input->cols);

    // Fill the transposed matrix
    for (int i = 0; i < input->rows; i++)
    {
        for (int j = 0; j < input->cols; j++)
        {
            res->m[j][i] = input->m[i][j];
        }
    }

    return res;
}

Matrix *multiply_matrix(Matrix *a, Matrix *b)
{
    Matrix *res = create_matrix(a->rows, b->cols);

    if (a->cols != b->rows)
    {
        printf("Matricies cannot be multiplied");
        return NULL;
    }

    // Perform matrix multiplication
    for (int i = 0; i < res->rows; i++)
    {
        for (int j = 0; j < res->cols; j++)
        {
            for (int k = 0; k < a->cols; k++)
            {
                res->m[i][j] += a->m[i][k] * b->m[k][j];
            }
        }
    }

    return res;
}

void print_matrix(Matrix *M)
{
    if (M)
    {
        for (int i = 0; i < M->rows; i++)
        {
            for (int j = 0; j < M->cols; j++)
            {
                printf("%f ", M->m[i][j]);
            }
            printf("\n");
        }
    }
}
