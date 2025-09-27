#include <stdio.h>

/*
    Task:
    Write a function int sum_to_n(int n) that computes
    the sum of all integers from 1 up to n using a for loop.

    In main():
      - Ask user for a positive integer n
      - If n < 1, print an error
      - Otherwise, call sum_to_n and print the result
*/

int sum_to_n(int n) {
    // TODO: implement sum with a for loop
    int total = 0;
    for (int i = 1; i <= n; i++) {
        total += i;
    }
    return total;
}

int main(void) {
    int n;

    printf("Enter a positive integer n: ");
    scanf("%d", &n);

    // TODO: validate input, call function, and print result
    if (n < 1) {
        printf("Invalid input! Please enter a number greater than 0.\n");
    } else {
        int total = sum_to_n(n);
        printf("Total sum from 1 to %d = %d\n", n, total);
    }

    return 0;
}