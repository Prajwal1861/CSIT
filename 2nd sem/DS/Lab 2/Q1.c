/*1. Write a program to implement Euclidean and Extended Euclidean algorithms*/

#include <stdio.h>

int euclidean_gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int extended_euclidean(int a, int b, int *x, int *y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }

    int x1, y1;
    int gcd = extended_euclidean(b, a % b, &x1, &y1);


    *x = y1;
    *y = x1 - (a / b) * y1;

    return gcd;
}

int main() {
    int a, b;
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    int gcd = euclidean_gcd(a, b);
    printf("GCD of %d and %d using Euclidean algorithm is: %d\n", a, b, gcd);

    int x, y;
    gcd = extended_euclidean(a, b, &x, &y);
    printf("GCD of %d and %d using Extended Euclidean algorithm is: %d\n", a, b, gcd);
    printf("Coefficients x and y are: %d and %d\n", x, y);

    return 0;
}
