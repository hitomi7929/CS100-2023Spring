#include <stdio.h>
#include <string.h>
#define SIZE 1100000

void decrypt(long Key, char* ciphertext);

int main(){
    long key;
    char ciphertext[SIZE] = "";
    scanf("%ld", &key);
    getchar();
    fgets(ciphertext, SIZE, stdin);
    
    decrypt(key, ciphertext);

    return 0;
}


void decrypt(long Key, char* ciphertext){
    int key;
    for (int i = 0; i < strlen(ciphertext); i++){
        char c = ciphertext[i];
        if (c >= 'a' && c <= 'z'){
            key = Key - 26 * (Key / 26);
            if (-key > 'z' - c){
                key += 26;
            }
            c -= key;
            if (c < 'a'){
                c += 26;
            }
        } else if (c >= 'A' && c <= 'Z'){
            key = Key - 26 * (Key / 26);
            c -= key;
            if (c < 'A'){
                c += 26;
            } else if (c > 'Z'){
                c -= 26;
            }
        } else if (c >= '0' && c <= '9'){
            key = Key - 10 * (Key / 10);
            c -= key;
            if (c < '0'){
                c += 10;
            } else if (c > '9'){
                c -= 10;
            }
        }
        printf("%c", c);
    }
}