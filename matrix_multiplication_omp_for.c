/*

To run this program please follow the followiung steps:
Withot Vectorization:
    Step 1: gcc matrix_multiplication_omp.c -o mat_mul_omp 
    Step 2: ./mat_mul_omp m n p t

With Vectorization:
    Step 1: gcc matrix_multiplication_omp.c -O3 -o mat_mul_vec_omp
    Step 2: ./mat_mul_vec_omp m n p t

where n is the number of  elements for the 1-D Matrix.
where t is the number of threads to be used

Example1 - Vectorization with OMP for:
$ gcc matrix_multiplication_omp.c -O3 -o mat_mul_vec_omp
$ ./mat_mul_vec_omp 500 650 600 3

Example2 - Non-Vectorization with OMP for:
$ gcc matrix_multiplication_omp.c -o mat_mul_omp
$ ./mat_mul_omp 3 4 2 3

Note: This Program is developed and tested on following tools:
Ubuntu : 22.04 LTS
gcc : 11.3.0

*/

#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include<omp.h>

int main(int argc, char *argv[]) {
    printf("Arguments: m=%s, n=%s, p=%s, t=%s\n", argv[1], argv[2], argv[3], argv[4]);

    // check if input is valid or not
    if (argv[1] == NULL || argv[2] == NULL || argv[3] == NULL|| argv[4] == NULL){
        printf("Invalid Arguments. Please provide A valid arguments\n");
        return 0;
    }

    int m = atoi(argv[1]);
    int n = atoi(argv[2]);
    int p = atoi(argv[3]);
    int num_of_threads = atoi(argv[4]);

    int A[m][n], B[n][p], C[m][p];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = rand() % 50;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            B[i][j] = rand() % 50;
        }
    }

    // Calculate excecution time for multiplication only
    clock_t begin = clock();
    #pragma omp parallel for (num_of_threads)
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    clock_t end = clock();

    // You can uncomment the following code to print the result.
    // however it is not advised for the large number of elements
    // printf("The product of the two matrices is: \n");
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         printf("%ld\t", C[i][j]);
    //     }
    //     printf("\n");
    // }

    // calculate the time and print it
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time taken: %f secs\n", time_spent);
    return 0;
}