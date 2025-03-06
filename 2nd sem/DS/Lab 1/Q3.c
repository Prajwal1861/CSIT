/*3. Write a program that takes a real number and produces is ceiling and floor integers as output.*/

#include <stdio.h>
int main() {
    double num;
    int floor, ceiling;
    printf("Enter a decimal number: ");
    scanf("%lf", &num);
    floor = (int)num;
    if (num < 0 && floor!= num) {
        floor= floor-1;
    }
    ceiling = (int)num;
    if (num > 0 && ceiling!= num) {
        ceiling= ceiling+1;
    } else if (num < 0 && ceiling!= num) {
        ceiling= (int)num;
    }
    printf("Floor integer of %.2f is: %d\n", num, floor);
    printf("Ceiling integer of %.2f is: %d\n", num, ceiling);
    return 0;
}
