/* c-alculator --- Simple calculator using C

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

 Simple calculator created using C.

Code:
 */

#include "c-alculator.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    main_menu();
}

int main_menu(void)
{
    char input;
    char buf[256], *endptr;

    while (1)
    {
        printf(INTRO);

        if (NO_INPUT)
        {
            return FAILURE;
        }

        input = buf[0];

        if (input == 'c')
        {
            operation();
            return SUCCESS;
        }
        else if (input == 'q')
        {
            printf("Quitting...");
            return FAILURE;
        }
        else
        {
            printf("Input should either be 'c' or 'q'.\n");
        }
    }
    return SUCCESS;
}

int operation(void)
{
    int op, success;
    char buf[256], *endptr;

    while (1)
    {
        printf(OPERATION_MENU);

        if (NO_INPUT)
            return FAILURE;

        op = strtol(buf, &endptr, 10);

        switch (op)
        {
        case 1:
            addition();
            return SUCCESS;
        case 2:
            subtraction();
            return SUCCESS;
        case 3:
            multiplication();
            return SUCCESS;
        case 4:
            division();
            return SUCCESS;
        default:
            printf("Input should be in the range of the provided operations.\n");
        }
    }
    return SUCCESS;
}

int addition(void)
{
    GET_NUMBERS;

    printf("The result is: %lf.\n", x + y);
    printf(QUIT_OPERATION);
    return SUCCESS;
}

int subtraction(void)
{
    GET_NUMBERS;

    printf("The result of the operations is: %lf.\n", x - y);
    printf(QUIT_OPERATION);
    return SUCCESS;
}

int multiplication(void)
{
    GET_NUMBERS;

    printf("The result of the operation is: %lf.\n", x * y);
    printf(QUIT_OPERATION);
    return SUCCESS;
}

int division(void)
{
    GET_NUMBERS;

    printf("The result of the operation is: %lf.\n", x / y);
    return SUCCESS;
}
