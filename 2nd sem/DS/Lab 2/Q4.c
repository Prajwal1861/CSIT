/*4. Write a program to implement the concept of linear congruence.*/

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
void solve_linear_congruence(int a, int b, int m) {
    int inv = mod_inverse(a, m);
    if (inv == -1) {
        printf("No solution exists\n");
    } else {
        int x = (b * inv) % m;
        printf("Solution to the linear congruence %dx = %d (mod %d) is x = %d (mod %d)\n", a, b, m, x, m);
    }
}

int main() {
    int a, b, m;
    printf("Enter values for a, b, and m (for the equation ax = b (mod m)): ");
    scanf("%d %d %d", &a, &b, &m);

    solve_linear_congruence(a, b, m);

    return 0;
}
