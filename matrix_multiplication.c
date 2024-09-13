/*

To run this program please follow the followiung steps:
Withot Vectorization:
    Step 1: gcc matrix_addition.c -o mat_mul 
    Step 2: ./mat_mul m n p

With Vectorization:
    Step 1: gcc matrix_addition.c -O3 -o mat_mul_vec
    Step 2: ./mat_mul_vec m n p

where n is the number of  elements for the 1-D Matrix.

Example1 - Vectorization:
$ gcc matrix_addition.c -O3 -o mat_mul_vec
$ ./mat_mul_vec 500 650 600

Example2 - Non-Vectorization:
$ gcc matrix_addition.c -o mat_mul
$ ./mat_mul 3 4 2

Note: This Program is developed and tested on following tools:
Ubuntu : 22.04 LTS
gcc : 11.3.0

Note: We used long long instead int because of larger numbers

*/

#include<stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    printf("Arguments: m=%s, n=%s, p=%s\n", argv[1], argv[2], argv[3]);

    // check if input is valid or not
    if (argv[1] == NULL || argv[2] == NULL || argv[3] == NULL){
        printf("Invalid Arguments. Please provide A valid arguments\n");
        return 0;
    }

    long long m = atoi(argv[1]);
    long long n = atoi(argv[2]);
    long long p = atoi(argv[3]);

    long long A[m][n], B[n][p], C[m][p];

    for (long long i = 0; i < m; i++) {
        for (long long j = 0; j < n; j++) {
            A[i][j] = rand() % 50;
        }
    }

    for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < p; j++) {
            B[i][j] = rand() % 50;
        }
    }

    // Calculate excecution time for multiplication only
    clock_t begin = clock();
    for (long long i = 0; i < m; i++) {
        for (long long j = 0; j < p; j++) {
            C[i][j] = 0;
            for (long long k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    clock_t end = clock();

    // You can uncomment the following code to print the result.
    // however it is not advised for the large number of elements
    // printf("The product of the two matrices is: \n");
    // for (long long i = 0; i < n; i++) {
    //     for (long long j = 0; j < n; j++) {
    //         printf("%ld\t", C[i][j]);
    //     }
    //     printf("\n");
    // }

    // calculate the time and print it
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time taken: %f secs\n", time_spent);
    return 0;
}