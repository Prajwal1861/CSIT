/*5. Write a program to find and implement the Chinese Remainder Theorem.*/

#include <stdio.h>
int extended_gcd(int a, int b, int *x, int *y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }

    int x1, y1;
    int gcd = extended_gcd(b, a % b, &x1, &y1);

    *x = y1;
    *y = x1 - (a / b) * y1;

    return gcd;
}

int mod_inverse(int a, int m) {
    int x, y;
    int gcd = extended_gcd(a, m, &x, &y);
    if (gcd != 1) {
        return -1;
    } else {
        return (x % m + m) % m;
    }
}

int chinese_remainder_theorem(int num[], int rem[], int k) {
    int prod = 1;
    for (int i = 0; i < k; i++) {
        prod *= num[i];
    }

    int result = 0;
    for (int i = 0; i < k; i++) {
        int pp = prod / num[i];
        int inv = mod_inverse(pp, num[i]);
        result += rem[i] * inv * pp;
    }

    return result % prod;
}

int main() {
    int k;
    printf("Enter the number of congruences: ");
    scanf("%d", &k);

    int num[k], rem[k];
    for (int i = 0; i < k; i++) {
        printf("Enter modulus and remainder for congruence %d: ", i + 1);
        scanf("%d %d", &num[i], &rem[i]);
    }

    int result = chinese_remainder_theorem(num, rem, k);
    printf("The solution of the system of congruences is: %d\n", result);

    return 0;
}
