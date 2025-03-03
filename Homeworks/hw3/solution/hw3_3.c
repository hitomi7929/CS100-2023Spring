#include <stdio.h>
#include <stdbool.h>
#define SIZEARRAY 100


int Year(int s[8]);
int Month(int s[8]);
int Day(int s[8]);


int main(){
    int m;
    int months[SIZEARRAY];
    int start[8];
    int end[8];
    scanf("%d", &m);
    for (int i = 0; i < m; i++){
        scanf("%d", &months[i]);
    }
    getchar();
    for (int i = 0; i < 8; i++){
        scanf("%1d", &start[i]);
    }
    getchar();
    for (int i = 0; i < 8; i++){
        scanf("%1d", &end[i]);
    }

    int ans = 0;
    int year = Year(start), tmp = Year(start), yearEnd = Year(end);
    while (year < yearEnd){
        if (year == tmp){
            int month = 10 * start[3] + start[2];
            if (month >= Month(start) && month <= m){
                if (month > Month(start)){
                    int day = 10 * start[1] + start[0];
                    if (day > 0 && day <= months[month - 1]){
                        ans++;
                    }
                } else{
                    int day = 10 * start[1] + start[0];
                    if (day > 0 && day >= Day(start)){
                        ans++;
                    }
                }
            }
        } else{
            int month = 10 * start[3] + start[2];
            if (month > 0 && month <= m){
                int day = 10 * start[1] + start[0];
                if (day > 0 && day <= months[month - 1]){
                    ans++;
                }
            }
        }
        year++;
        start[0] = year / 1000;
        start[1] = (year / 100) % 10;
        start[2] = (year / 10) % 10;
        start[3] = year % 10;
    }
    
    if (year == Year(end)){
        if (year == tmp){
            int month = 10 * start[3] + start[2];
            if (month >= Month(start) && month <= Month(end)){
                if (month > Month(start)){
                    int day = 10 * start[1] + start[0];
                    if (day > 0){
                        if (month < Month(end) && day <= months[month - 1]){
                            ans++;
                        } else if (month == Month(end) && day <= Day(end)){
                            ans++;
                        }
                    }
                } else{
                    int day = 10 * start[1] + start[0];
                    if (day > 0 && day >= Day(start)){
                        ans++;
                    }
                }
            }
        } else{
            int month = 10 * start[3] + start[2];
            if (month > 0 && month <= Month(end)){
                int day = 10 * start[1] + start[0];
                if (month == Month(end)){
                    if (day > 0 && day <= Day(end)){
                        ans++;
                    }
                } else{
                    if (day > 0 && day <= months[month - 1]){
                        ans++;
                    }
                }
            }
        }
    }
    
    printf("%d", ans);
    return 0;
}


int Year(int s[8]) { return (1000 * s[0] + 100 * s[1] + 10 * s[2] + s[3]); }
int Month(int s[8]) { return (10 * s[4] + s[5]); }
int Day(int s[8]) { return (10 * s[6] + s[7]); }