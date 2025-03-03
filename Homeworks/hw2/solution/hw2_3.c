#include <stdio.h>
#define SIZE 55


int calculateLen(char* s);
void reverse(char* s, int len);
int value(char* s);
char character(int n);
void add(char* a, char* b, char* c, int La, int Lb);
void sub(char* a, char* b, char* c, int La);

int main(){
    char a[SIZE];
    char b[SIZE];
    char c[SIZE] = "";
    char symbol;
    scanf("%c", &symbol);
    getchar();
    fgets(a, SIZE, stdin);
    fgets(b, SIZE, stdin);
    int La = calculateLen(a);
    int Lb = calculateLen(b);
    reverse(a, La);
    reverse(b, Lb);

    if (symbol == '+'){
        add(a, b, c, La, Lb);
    } else if (symbol == '-'){
        sub(a, b, c, La);
    }

    int Lc = calculateLen(c);
    int max = La;
    if (Lb > max){
        max = Lb;
    }
    if (Lc > max){
        max = Lc;
    }
    max++;

    for (int i = 0; i < max - La; i++){
        printf(" ");
    }
    reverse(a, La);
    printf("%s%c", a, symbol);
    for(int i = 0; i < max - Lb - 1; i++){
        printf(" ");
    }
    reverse(b, Lb);
    printf("%s", b);
    for (int i = 0; i < max; i++){
        printf("-");
    }
    printf("\n");
    for (int i = 0; i < max - Lc; i++){
        printf(" ");
    }
    reverse(c, Lc);
    printf("%s", c);

    return 0;
}

int calculateLen(char* s){
    int ans = 0, i = 0;
    while (s[i] != '\n' && s[i] != '\0' && s[i] != '\000'){
        ans++;
        i++;
    }
    return ans;
}


void reverse(char* s, int len){
    for (int i = 0; i < len / 2; i++){
        char tmp = s[i];
        s[i] = s[len - i -1];
        s[len - i - 1] = tmp;
    }
}


int value(char* s){
    switch (*s){
        case '0':   return 0;
        case '1':   return 1;
        case '2':   return 2;
        case '3':   return 3;
        case '4':   return 4;
        case '5':   return 5;
        case '6':   return 6;
        case '7':   return 7;
        case '8':   return 8;
        case '9':   return 9;
        case 'a':   return 10;
        case 'b':   return 11;
        case 'c':   return 12;
        case 'd':   return 13;
        case 'e':   return 14;
        case 'f':   return 15;
        default:    return 0;
    }
}


char character(int n){
    switch (n){
        case 0:     return '0';
        case 1:     return '1';
        case 2:     return '2';
        case 3:     return '3';
        case 4:     return '4';
        case 5:     return '5';
        case 6:     return '6';
        case 7:     return '7';
        case 8:     return '8';
        case 9:     return '9';
        case 10:    return 'a';
        case 11:    return 'b';
        case 12:    return 'c';
        case 13:    return 'd';
        case 14:    return 'e';
        case 15:    return 'f';
        default:    return '\0';
    }
}


void add(char* a, char* b, char* c, int La, int Lb){
    int adder = 0, sum;
    int L = (La >= Lb) ? La : Lb;
    for (int i = 0; i < L; i++){
        int va = value(a+i);
        int vb = value(b+i);
        sum = va + vb + adder;
        c[i] = character(sum % 16);
        adder = sum / 16;
    }
}

void sub(char* a, char* b, char* c, int La){
    int suber = 0, ans;
    for (int i = 0; i < La; i++){
        int va = value(a+i);
        int vb = value(b+i);
        ans = va - vb - suber;
        if (ans >= 0){
            c[i] = character(ans);
            suber = 0;
        } else{
            c[i] = character(ans + 16);
            suber = 1;
        }
    }
    for (int i = La - 1; i > 0; i--){
        if (c[i] == '0'){
            c[i] = ' ';
            continue;
        }
        break;
    }
}