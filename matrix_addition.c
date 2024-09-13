/*

To run this program please follow the followiung steps:
Withot Vectorization:
    Step 1: gcc matrix_addition.c -o mat_add 
    Step 2: ./mat_add n

With Vectorization:
    Step 1: gcc matrix_addition.c -O3 -o mat_add_vec
    Step 2: ./mat_add_vec n

where n is the number of  elements for the 1-D Matrix.

Example1 - Vectorization:
$ gcc matrix_addition.c -O3 -o mat_add_vec
$ ./mat_add_vec 1000

Example2 - Non-Vectorization:
$ gcc matrix_addition.c -o mat_add
$ ./mat_add 10

Note: This Program is developed and tested on following tools:
Ubuntu : 22.04 LTS
gcc : 11.3.0

Note: We used long instead int because of larger numbers
*/


#include<stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    printf("Arguments: %s\n", argv[1]);

    // check if input is valid or not
    if (argv[1] == NULL){
        printf("Invalid Argument. Please provide a valid number\n");
        return 0;
    }

    // Convert command line argument char* to int
    long n = atoi(argv[1]);
    printf("Number of Elements: %ld\n", n);

    long A[n], B[n], C[n];

    for(long i = 0; i < n; i++){
        A[i] = rand() % 10;
        B[i] = rand() % 10;
    }

    // Calculate excecution time for addtion only
    clock_t begin = clock();
    for(long i = 0; i < n; i++){
        C[i] = A[i] + B[i];
    }
    clock_t end = clock();

    // You can uncomment the following code to print the result.
    // however it is not advised for the large number of elements

    // for(long i = 0; i < n; i++){
    //     printf("%ld + %ld = %ld\n",A[i], B[i], C[i]);
    // }

    // calculate the time and print it
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time taken: %f secs\n", time_spent);
    return 0;
}
