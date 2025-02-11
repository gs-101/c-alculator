/* c-alculator --- Simple calculator using C
   @file operations.c
   @brief Definition of the operations for c-alculator.

Copyright (C) 2025 Gabriel Santos

Author: Gabriel Santos
URL: https://github.com/gs-101/c-alculator
Mirror: https://codeberg.org/gs-101/c-alculator
SPDX-License-Identifier: GPL-3.0-or-later

 This file is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License
 (at your option) any later version.

 This file is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this file.  If not, see <https://www.gnu.org/licenses/>.

Commentary:

 File holding all the operations suppored by c-alculator.

Code:
 */

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
