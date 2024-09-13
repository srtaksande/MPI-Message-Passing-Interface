#include <stdio.h>
#include <stdlib.h>

int main(){

    int n=50;
    int odd[n], even[n], prime[n];
    int temp = 0;

    printf("Input\tEven\tOdd\tPrime\n");
    for(int i = 0; i < n; i++){
        int prime_flag = 0;
        temp = rand() % 100000;

        // find even or odd
        if (temp % 2 == 0){
            odd[i] = 0;
            even[i] = 1;
        }else {
            odd[i] = 1;
            even[i] = 0;
        }

        // find prime number
        if (temp == 0 || temp == 1) {
            prime_flag = 1;
        }

        for (int j = 2; j <= temp / 2; ++j) {

            // if n is divisible by j, then n is not prime
            // change flag to 1 for non-prime number
            if (temp % j == 0) {
                prime_flag = 1;
                break;
            }
        }
        if (prime_flag == 0)
            prime[i] = 1;
        else
            prime[i] = 0;
        printf("%d\t%d\t%d\t%d\n", temp, even[i], odd[i], prime[i]);
    }

}