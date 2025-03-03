#include <stdio.h>


int main(){
    int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
    double k, b;
    scanf("(%d, %d)\n", &x1, &y1);
    scanf("(%d, %d)", &x2, &y2);

    printf("%d %d %d %d", x1, y1, x2, y2);

    if ((x2 -x1) != 0){
        double y = y2 - y1;
        double x = x2 - x1;
        k = y / x;
        b = y1 - k * x1;
        if (b >= 0){
            printf("y = %.2fx + %.2f", k, b);
        }else{
            b = -b;
            printf("y = %.2fx - %.2f", k, b);
        }   
    }else{
        b = x1;
        printf("x = %.2f", b);
    }


    return 0;
}