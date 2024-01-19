#include <stdio.h>

/**
 * add - adds tow integers
 * @a: first int
 * @b: second int
 * return: answer
 */
int add(int a, int b) {
    return a + b;
}

/**
 * sub - subtracts tow integers
 * @a: first int
 * @b: second int
 * return: answer
 */
int sub(int a, int b) {
    return a - b;
}

/**
 * mul - multipliess tow integers
 * @a: first int
 * @b: second int
 * return: answer
 */
int mul(int a, int b) {
    return a * b;
}

/**
 * div - divides tow integers
 * @a: first int
 * @b: second int
 * return: answer
 */
int div(int a, int b) {
    if (b == 0) {
        printf("Error: Division by zero\n");
        return 0;
    }
    return a / b;
}

/**
 * mod - modulos of tow integers
 * @a: first int
 * @b: second int
 * return: answer
 */
int mod(int a, int b) {
    if (b == 0) {
        printf("Error: Modulo by zero\n");
        return 0;
    }
    return a % b;
}
