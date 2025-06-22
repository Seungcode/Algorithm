#include <stdio.h>

int a[3] = { 0 };

int main() {
    int b; 
    int i, j; 

    scanf("%d %d %d", &a[0], &a[1], &a[2]);

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2 - i; j++) {
            if (a[j] > a[j + 1]) {
                b = a[j];
                a[j] = a[j + 1];
                a[j + 1] = b;
            }
        }
    }

    if (a[0] == a[1] && a[1] == a[2]) {
        printf("%d", 10000 + a[0] * 1000);
    }
    else if (a[0] == a[1] || a[1] == a[2] || a[0] == a[2]) {
        printf("%d", 1000 + a[1] * 100);
    }
    else {
        printf("%d", a[2] * 100);
    }

    return 0;
}