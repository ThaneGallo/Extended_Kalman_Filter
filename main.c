#include <math.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <time.h>

typedef struct Matrix
{
    uint8_t rows;
    uint8_t cols;
    double **m;
} Matrix;

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

double generate_gaussian_noise(double mu, double sigma)
{


    double u1 = (double)rand() / RAND_MAX; // Uniform random number in (0,1)
    double u2 = (double)rand() / RAND_MAX; // Another uniform random number in (0,1)

    // Box-Muller transform
    double z0 = sqrt(-2.0 * log(u1)) * cos(2.0 * M_PI * u2);
    // Transform to desired mean and standard deviation
    return z0 * sigma + mu;
}


int main()
{
    int i,j;
    srand(time(NULL));
    Matrix* M = create_matrix(5, 5);
    double mu = 0;
    double sigma = 1;


    for(i = 0; i < M->rows; i++){
        for(j = 0; j < M->cols; j++){

            M->m[i][j] = generate_gaussian_noise(mu, sigma);

        }
    }


    print_matrix(M);



    return 0;
}