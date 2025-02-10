#include "c-alculator.h"
#include <stdio.h>
#include <stdlib.h>

int addition(void)
{
    GET_NUMBERS;

    printf("The result is: %lf.\n", x + y);
    printf(QUIT_OPERATION);
    exit(EXIT_SUCCESS);
}

int subtraction(void)
{
    GET_NUMBERS;

    printf("The result of the operations is: %lf.\n", x - y);
    printf(QUIT_OPERATION);
    exit(EXIT_SUCCESS);
}

int multiplication(void)
{
    GET_NUMBERS;

    printf("The result of the operation is: %lf.\n", x * y);
    printf(QUIT_OPERATION);
    exit(EXIT_SUCCESS);
}

int division(void)
{
    GET_NUMBERS;

    if (y == 0)
    {
        fprintf(stderr, "Can't divide by zero.\n");
        exit(EXIT_FAILURE);
    }

    printf("The result of the operation is: %lf.\n", x / y);
    printf(QUIT_OPERATION);
    exit(EXIT_SUCCESS);
}

double pow(double x, double y)
{
    double result = 1;

    if (y == 1)
    {
        return x;
    }
    else
    {

        while (y >= 1)
        {
            y--;
            result *= x;
        }

        return result;
    }
}

int power(void)
{
    GET_NUMBERS;

    printf("The result of the operation is %lf.\n", pow(x, y));
    printf(QUIT_OPERATION);
    exit(EXIT_SUCCESS);
}

double factor(double x)
{
    double result = 1;
    for (double i = 1; i <= x; i++)
    {
        result *= i;
    }

    return result;
}

int factorial(void)
{
    GET_NUMBER;

    printf("The result of the operation is %lf.\n", (factor(x)));
    printf(QUIT_OPERATION);
    exit(EXIT_SUCCESS);
}
