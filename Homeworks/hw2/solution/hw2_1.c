#include <stdio.h>
#define N 100


int main(){
    int n, ans = 0;
    long num;
    scanf("%d", &n);

    long array[N];
    for (int i = n - 1; i >= 0; i--){
        scanf("%ld", &num);
        if (num > 0){
            array[i] = num * num;
            ans++;
        } else{
            array[i] = num;
        }
    }
    for (int i = 0; i < n; i++){
        num = array[i];
        if (num > 0){
            printf("%ld\n", num);
        }
    }
    printf("%d", ans);

    return 0;
}