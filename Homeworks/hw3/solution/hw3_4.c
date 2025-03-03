#include <stdio.h>
#define SIZE 2100000
#define SSIZE 11000000


int main(){
    long n, p, t, totalPrice = 0;
    long games[SIZE];
    char names[SSIZE];
    scanf("%ld", &n);
    for (long i = 0; i < n; i++){
        scanf(" (%[^,],%ld,%ld)", names, &p, &t);
        games[t] += p;
        totalPrice += p;
    }
    totalPrice /= 2;
    for (long i = 0; i < SIZE; i++){
        if (games[i] > totalPrice){
            printf("%ld", i);
            break;
        }
    }

    return 0;
}