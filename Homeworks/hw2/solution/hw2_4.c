#include <stdio.h>
#define LMAX 100


int twoLen(long long n);

int main(){
    long long x;
    int m;
    scanf("%lld %d", &x, &m);
    int xb[LMAX];
    int len = twoLen(x);
    int tmp = 0;
    while (x > 0){
        xb[tmp++] = x % 2;
        x = x / 2;
    }

    long long multipler = 1, ans = 0; 
    int firOne = -1;
    for (int j = m + 1; j < len; j++){
        ans += xb[j] * multipler;
        multipler *= 2;
        if (firOne == -1 && xb[j] == 1){
            firOne = j;
        }
    }
    for (int j = 0; j <= m; j++){
        ans += xb[j] * multipler;
        multipler *= 2;
        if (firOne == -1 && xb[j] == 1){
            firOne = j;
        }
    }
    int y = (firOne - m - 1 >= 0) ? firOne - m - 1 : firOne; 
    printf("%lld %d", ans, y);

    return 0;
}

int twoLen(long long n){
    int ans = 0;
    while(n > 0){
        ans++;
        n = n / 2;
    }
    return ans;
}