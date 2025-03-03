#include <stdio.h>

void convertGe(int m){
    switch (m){
        case 1:
            printf("one");      break;
        case 2:
            printf("two");      break;
        case 3:
            printf("three");    break;
        case 4:
            printf("four");     break;
        case 5:
            printf("five");     break;
        case 6:
            printf("six");      break;
        case 7:
            printf("seven");    break;
        case 8:
            printf("eight");    break;
        case 9:
            printf("nine");     break;
    }
}

void convertShi1(int m){
    switch (m){
        case 10:
            printf("ten");          break;
        case 11:
            printf("eleven");       break;
        case 12:
            printf("twelve");       break;
        case 13:
            printf("thirteen");     break;
        case 14:
            printf("fourteen");     break;
        case 15:
            printf("fifteen");      break;
        case 16:
            printf("sixteen");      break;
        case 17:
            printf("seventeen");    break;
        case 18:
            printf("eighteen");     break;
        case 19:
            printf("nineteen");     break;
    }
}

void convertShi2(int m){
    switch (m){
        case 2:
            printf("twenty");   break;
        case 3:
            printf("thirty");   break;
        case 4:
            printf("forty");    break;
        case 5:
            printf("fifty");    break;
        case 6:
            printf("sixty");    break;
        case 7:
            printf("seventy");  break;
        case 8:
            printf("eighty");   break;
        case 9:
            printf("ninety");   break;
    }
}

int main(){
    int n = 0;
    scanf("%d", &n);

    if (n == 0){
        printf("zero");
    }
    if (n / 100000){
        convertGe(n / 100000);
        printf(" hundred");
        n = n % 100000;
        if (n / 10000){
            printf(" and ");
        }else{
            printf(" thousand ");
            if (!(n / 100) && n){
                printf("and ");
            }
        }
    }
    if (n / 10000){
        if (n / 10000 == 1){
            convertShi1(n / 1000);
        }else{
            convertShi2(n / 10000);
            n = n % 10000;
            if (n / 1000){
                printf("-");    
            }else{
                printf(" thousand");
            }
        }
    }
    if (n / 1000){
        convertGe(n / 1000);
        printf(" thousand");
        n = n % 1000;
        if (n){
            printf(" ");
            if (!(n / 100)){
                printf("and ");
            }
        }
    }
    
    if (n / 100){
        convertGe(n / 100);
        printf(" hundred");
        n = n % 100;
        if (n){
            printf(" and ");
        }
    }
    if (n / 10){
        if (n / 10 == 1){
            convertShi1(n);
        }else{
            convertShi2(n / 10);
            if (n % 10){
                printf("-");
                convertGe(n % 10);
            }
        }
    }else{
        convertGe(n);
    }


    return 0;
}