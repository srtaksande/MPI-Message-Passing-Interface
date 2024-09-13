/*

To run this program please follow the followiung steps:
Withot Vectorization:
    Step 1: gcc matrix_addition.c -o mat_add_omp
    Step 2: ./mat_add n num_of_threads

With Vectorization:
    Step 1: gcc matrix_addition.c -O3 -o mat_add_vec_omp
    Step 2: ./mat_add_vec n num_of_threads

where n is the number of  elements for the 1-D Matrix.
where num_of_threads is the number of threads you want to use

Example1 - Vectorization with OMP:
$ gcc matrix_addition.c -O3 -o mat_add_vec_omp
$ ./mat_add_vec 1000 3

Example2 - Non-Vectorization with OMP:
$ gcc matrix_addition.c -o mat_add_omp
$ ./mat_add 10 4

Note: This Program is developed and tested on following tools:
Ubuntu : 22.04 LTS
gcc : 11.3.0

Note: We used int instead int because of larger numbers
*/


#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include<omp.h>

int main(int argc, char *argv[]) {
    printf("Arguments: %s, %s\n", argv[1], argv[2]);

    // check if input is valid or not
    if (argv[1] == NULL || argv[2] == NULL){
        printf("Invalid Arguments. Please provide a valid inputs\n");
        return 0;
    }

    // Convert command line argument char* to int
    int n = atoi(argv[1]);
    int num_of_threads = atoi(argv[2]);
    printf("Number of Elements: %d\n", n);
    printf("Number of threads: %d\n", num_of_threads);

    int A[n], B[n], C[n];

    for(int i = 0; i < n; i++){
        A[i] = rand() % 10;
        B[i] = rand() % 10;
    }

    // Calculate excecution time for addtion only
    clock_t begin = clock();
    #pragma omp parallel (num_of_threads)
    for(int i = 0; i < n; i++){
        C[i] = A[i] + B[i];
    }
    clock_t end = clock();

    // You can uncomment the following code to print the result.
    // however it is not advised for the large number of elements

    // for(int i = 0; i < n; i++){
    //     printf("%ld + %ld = %ld\n",A[i], B[i], C[i]);
    // }

    // calculate the time and print it
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time taken: %f secs\n", time_spent);
    return 0;
}
