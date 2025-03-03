#include <stdio.h>


int hw4_islower(int ch);
int hw4_isupper(int ch);
int hw4_isalpha(int ch);
int hw4_isdigit(int ch);
int hw4_tolower(int ch);
int hw4_toupper(int ch);
size_t hw4_strlen(const char *str);
char *hw4_strchr(const char *str, int ch);
char *hw4_strcpy(char *dest, const char *src);
char *hw4_strcat(char *dest, const char *src);
int hw4_strcmp(const char *lhs, const char *rhs);


int hw4_islower(int ch){
    return (ch >= 'a' && ch <= 'z') ? 1 : 0;
}


int hw4_isupper(int ch){
    return (ch >= 'A' && ch <= 'Z') ? 1 : 0;
}


int hw4_isalpha(int ch){
    return (hw4_islower(ch) || hw4_isupper(ch)) ? 1 : 0;
}


int hw4_isdigit(int ch){
    return (ch >= '0' && ch <= '9') ? 1 : 0;
}


int hw4_tolower(int ch){
    return hw4_isupper(ch) ? ch + 'a' - 'A' : ch;
}


int hw4_toupper(int ch){
    return hw4_islower(ch) ? ch + 'A' - 'a' : ch;
}


size_t hw4_strlen(const char *str){
    size_t i = 0;
    while (str[i] != '\0'){
        i++;
    }
    return i;
}


char *hw4_strchr(const char *str, int ch){
    if (ch == '\0'){
        return (char*)str;
    }
    for (size_t i = 0; str[i] != '\0'; i++){
        if (str[i] == ch){
            return (char*)(str + i);
        }
    }
    return NULL;
}


char *hw4_strcpy(char *dest, const char *src){
    size_t i;
    for (i = 0; src[i] != '\0'; i++){
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return (char*)dest;
}


char *hw4_strcat(char *dest, const char *src){
    size_t len = hw4_strlen(dest), i;
    for (i = 0; src[i] != '\0'; i++){
        dest[len + i] = src[i];
    }
    dest[len + i] = '\0';
    return (char*)dest;
}


int hw4_strcmp(const char *lhs, const char *rhs){
    size_t i;
    for (i = 0; lhs[i] != '\0' && rhs[i] != '\0'; i++){
        if (lhs[i] != rhs[i]){
            return lhs[i] - rhs[i];
        }
    }
    return lhs[i] - rhs[i];
}