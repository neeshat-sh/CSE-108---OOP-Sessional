#include <stdio.h>

void swapnum(int& i, int& j) {
    int temp = i;
    i = j;
    j = temp;
}

void swap_with_pointers(int* i, int* j) {
    int temp = *i;
    *i = *j;
    *j = temp;
}

int main(void) {
    int a = 10;
    int b = 20;

    swapnum(a, b);
    printf("A is %d and B is %d\n", a, b);

    swap_with_pointers(&a, &b);
    printf("A is %d and B is %d\n", a, b);

    if (a < b) {
        printf("A is less than B\n");
    } else {
        printf("A is greater than B\n");
    }

    return 0;
}