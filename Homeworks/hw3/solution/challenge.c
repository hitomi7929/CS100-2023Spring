#include <stdio.h>
#define SIZE 11000000


int main(){
    long n, p, t, type = 0, totalPrice = 0;
    char name[SIZE];
    scanf("%ld", &n);
    for (long i = 0; i < n; i++){
        scanf(" (%[^,],%ld,%ld)", name, &p, &t);
        if (t == type){
            totalPrice += p;
        } else{
            totalPrice -= p;
            if (totalPrice <= 0){
                totalPrice = -totalPrice;
                type = t;
            }
        }
    }
    printf("%ld", type);

    return 0;
}