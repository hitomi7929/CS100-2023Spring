#include <stdio.h>
#include <stdbool.h>
#define SIZEARRAY 100


int Year(long n);
int Month(long n);
int Day(long n);
int getMonth(int year);
int getDay(int year);


int main(){
    int m;
    int months[SIZEARRAY];
    long start, end;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &months[i]);
    }
    getchar();
    scanf("%ld\n%ld", &start, &end);

    printf("\n%d\n", m);
    for (int i = 0; i < m; i++) {
        printf("%d ", months[i]);
    }
    printf("\n");
    printf("%ld\n%ld", start, end);
    printf("\n%d\n%d\n%d", Year(start), Month(start), Day(start));
    
    int tmp = Year(start);
    int startYear = Year(start), startMonth = Month(start), startDay = Day(start);
    int endYear = Year(end), endMonth = Month(end), endDay = Day(end);
    if (startYear = endYear) {
        int month = getMonth(startYear);
        if (month > startMonth && month < endMonth) {
            int day = getDay(startYear);
            if (day <= months[month]);
        }
    }
    while(tmp < endYear) { }
    if (tmp = endYear) {
        int month = getMonth(tmp);
    }

    return 0;
}


int Year(long n) { return n / 10000; }
int Month(long n) { return (n / 100) % 100; }
int Day(long n) { return n % 100; }


int getMonth(int year) { return (10 * (year % 10) + ((year % 100) / 10)); }
int getDay(int year) { return (10 * ((year / 100) % 10) + (year / 1000)); }