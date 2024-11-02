#include <math.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <time.h>

#include "matrix.h"



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
    int i, j;
    srand(time(NULL));
    Matrix *M1 = create_matrix(5, 5);

    Matrix *M2 = create_matrix(5, 5);

    double mu = 0;
    double sigma = 1;

    for (i = 0; i < M1->rows; i++)
    {
        for (j = 0; j < M1->cols; j++)
        {

            M1->m[i][j] = 1;
        }
    }

    for (i = 0; i < M2->rows; i++)
    {
        for (j = 0; j < M2->cols; j++)
        {

            M2->m[i][j] = 2;
        }
    }

    print_matrix(M1);



    return 0;
}