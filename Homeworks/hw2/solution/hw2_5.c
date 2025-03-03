#include <stdio.h>
#include <stdbool.h>


bool checkOneNumber(int (*board)[9], int row, int col);
void checkNineSum(int* sum, bool* flag);
void checkHorse(int (*board)[9], int row, int col, int* target, bool* flag);

int main(){
    int board[9][9];
    bool flag = true;
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            scanf("%d", &board[i][j]);
        }
        getchar();
    }

    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            if (checkOneNumber(board, i, j) == false){
                flag = false;
                break;
            }
        }
    }
    printf("%d", flag);
    
    return 0;
}

bool checkOneNumber(int (*board)[9], int row, int col){
    bool flag = true;
    int sum = 0;
    int target = board[row][col];
    if (target < 1 || target > 9){
        return false;
    }
    for (int i = 0; i < 9; i++){
        int tmp = board[row][i];
        sum += tmp;
        if (target == tmp && i != col){
            return false;
        }
    }
    checkNineSum(&sum, &flag);

    for (int i = 0; i < 9; i++){
        int tmp = board[i][col];
        sum += tmp;
        if (target == tmp && i != row){
            return false;
        }
    }
    checkNineSum(&sum, &flag);

    if (row % 3 == 0 && col % 3 == 0){
        for (int i = row; i < row + 3; i++){
            for (int j = col; j < col + 3; j++){
                int tmp = board[i][j];
                sum += tmp;
                if (target == tmp && (i != row || j != col)){
                    return false;
                }
            }
        }
        checkNineSum(&sum, &flag);
    } 
    checkHorse(board, row - 1, col - 2, &target, &flag);
    checkHorse(board, row - 1, col + 2, &target, &flag);
    checkHorse(board, row + 1, col - 2, &target, &flag);
    checkHorse(board, row + 1, col + 2, &target, &flag);
    checkHorse(board, row - 2, col - 1, &target, &flag);
    checkHorse(board, row - 2, col + 1, &target, &flag);
    checkHorse(board, row + 2, col - 1, &target, &flag);
    checkHorse(board, row + 2, col + 1, &target, &flag);

    return flag;
}


void checkNineSum(int* sum, bool* flag){
    if (*sum != 45){
        *flag = false;
    } else{
        *sum = 0;
    }
}

void checkHorse(int (*board)[9], int row, int col, int* target, bool* flag){
    if (row >= 0 && row < 9 && col >= 0 && col < 9){
        if (board[row][col] == *target){
            *flag = false;
        }
    }
}