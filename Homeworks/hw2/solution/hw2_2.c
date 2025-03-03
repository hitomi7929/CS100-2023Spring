#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define EPSILON  0.0000001


int main(){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (a != 0){
        double a1 = a, b1 = b, c1 = c;
        double delta = b1*b1 - 4*a1*c1;
        if (delta > 0){
            double x1 = (-b1 + sqrt(delta)) / (2*a1);
            double x2 = (-b1 - sqrt(delta)) / (2*a1);
            if (x1 > x2){
                double tmp = x1;
                x1 = x2;
                x2 = tmp;
            }
            printf("x1 = %.3lf, x2 = %.3lf", x1, x2);
        } else if (delta < EPSILON && delta > -EPSILON){
            double x = -b1 / (2*a1);
            printf("x1 = x2 = %.3lf", x);
        } else{
            printf("No solution.");
        }
    } else{
        if (b != 0){
            double b1 = b, c1 = c;
            printf("x = %.3lf", (-c1 / b1));
        } else{
            if (c != 0){
                printf("No solution.");
            } else{
                printf("x\\in\\mathbb{R}");
            }
        }
    }

    return 0;
}