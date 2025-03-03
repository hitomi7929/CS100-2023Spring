#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#define SIZE 1100000


void lower(char* s);
void upper(char* s);


int main(){
    char keyword[105] = "";
    char ciphertext[SIZE] = "";
    int characters[26];
    memset(characters, 0, 26*sizeof(int));
    char keys[26] = "";

    fgets(keyword, 105, stdin);
    fgets(ciphertext, SIZE, stdin);
    int words = strlen(keyword), key = 0, index = 0;

    for (int i = 0; i < words; i++){
        char c = keyword[i];
        lower(&c);
        if (characters[c - 'a'] == 0){
            keys[key++] = c;
            index = c - 'a';
            if (index < 0){
                index += 'a' - 'A';
            }
        }
        characters[c - 'a']++;
    }
    for (int i = index + 1; i < 26; i++){
        if (characters[i] == 0){
            keys[key++] = 'a' + i;
        }
    }
    for (int i = 0; i < index; i++){
        if (characters[i] == 0){
            keys[key++] = 'a' + i;
        }
    }

    int i = 0;
    while (ciphertext[i] != '\n'){
        char c = ciphertext[i];
        if (islower(c)){
            int n = strchr(keys, c) - keys;
            char ans = 'a' + n;
            printf("%c", ans);
        } else if (isupper(c)){
            lower(&c);
            int n = strchr(keys, c) - keys;
            char ans = 'A' + n;
            printf("%c", ans);
        } else{
            printf("%c", c);
        }
        i++;
    }

    return 0;
}


void lower(char* s){
    if (*s >= 'A' && *s <= 'Z'){
        *s = *s + 'a' - 'A';
    }
}


void upper(char* s){
    if (*s >= 'a' && *s <= 'z'){
        *s = *s + 'A' - 'a';
    }
}