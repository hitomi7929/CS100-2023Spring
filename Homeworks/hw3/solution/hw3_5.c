#include <stdio.h>
#define SIZE 500


void moveU(int* r, int* c, char s, int step);
void moveD(int* r, int* c, char s, int step);
void moveR(int* r, int* c, char s, int step);
void moveL(int* r, int* c, char s, int step);


int main(){
    int row, col, r, c;
    long q;
    scanf("%d %d %ld", &row, &col, &q);
    char hamsters[SIZE][SIZE];
    int found[SIZE][SIZE];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            scanf(" %c", &hamsters[i][j]);
            found[i][j] = 1;
        }
    }
    scanf("%d %d", &r, &c);
    r--;
    c--;
    
    for (int i = 0; i < q; i++){
        char hint, character;
        int step;
        getchar();
        scanf("%c", &hint);
        while ((character = getchar()) != ' '){
        }
        scanf("%d", &step);

        switch (hamsters[r][c]){
            case 'U':
                moveU(&r, &c, hint, step);
                break;
            case 'D':
                moveD(&r, &c, hint, step);
                break;
            case 'R':
                moveR(&r, &c, hint, step);
                break;
            case 'L':
                moveL(&r, &c, hint, step);
                break;
        }
        if (r >= 0 && c >= 0 && found[r][c] != 0){
            found[r][c] = 0;
            printf("(%d, %d)\n", r+1, c+1);
        } else{
            printf("Mistake!");
            break;
        }
    }

    return 0;
}


void moveU(int* r, int* c, char s, int step){
    switch (s){
        case 'F':   *r = *r - step;   break;
        case 'B':   *r = *r + step;   break;
        case 'L':   *c = *c - step;   break;
        case 'R':   *c = *c + step;   break;
    }
}


void moveD(int* r, int* c, char s, int step){
    switch (s){
        case 'F':   *r = *r + step;   break;
        case 'B':   *r = *r - step;   break;
        case 'L':   *c = *c + step;   break;
        case 'R':   *c = *c - step;   break;
    }
}


void moveR(int* r, int* c, char s, int step){
    switch (s){
        case 'F':   *c = *c + step;   break;
        case 'B':   *c = *c - step;   break;
        case 'L':   *r = *r - step;   break;
        case 'R':   *r = *r + step;   break;
    }
}


void moveL(int* r, int* c, char s, int step){
    switch (s){
        case 'F':   *c = *c - step;   break;
        case 'B':   *c = *c + step;   break;
        case 'L':   *r = *r + step;   break;
        case 'R':   *r = *r - step;   break;
    }
}