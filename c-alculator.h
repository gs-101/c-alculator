/* c-alculator --- Simple calculator using C
   @file c-alculator.h
   @brief Functionality for c-alculator.

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

 Functionality for c-alculator.

Code:
 */

#include <stdio.h>
#define EXIT_SUCCESS 0
#define EXIT_FAILURE -1

#define MAIN_MENU " ______ \n/ ____|\n| |     \n| |     \n| |____ \n\\_____| alculator\n\n[c]alculate [q]uit\n"

#define OPERATION_MENU                                                                                                 \
    " \
Operations:\n \
[1] Addition\n \
[2] Subtraction\n \
[3] Multiplication\n \
[4] Division\n \
[5] Power\n \
[6] Factorial\n \
"

#define ERROR_ON_NO_INPUT                                                                                              \
    if (!fgets(buf, sizeof(buf), stdin))                                                                               \
    {                                                                                                                  \
        perror("Error on getting input");                                                                              \
        exit(EXIT_FAILURE);                                                                                            \
    }

/**
 * @brief Macro to prompt the user to enter a number and parse it as a double.
 *
 * This macro performs the following steps:
 * 1. Declares a x variable to store the parsed value.
 * 2. Declares a buffer buf to hold user input.
 * 3. Prompts the user for a number.
 * 4. Checks if no input was provided and if true,
 * exits the program with `EXIT_FAILURE`.
 * 5. Otherwise, converts the input string from buf to a double,
 * storing the result in x.
 */
#define GET_NUMBER                                                                                                     \
    double x;                                                                                                          \
    char buf[1024], *endptr;                                                                                           \
    printf("Enter your number:\n");                                                                                    \
    ERROR_ON_NO_INPUT                                                                                                  \
                                                                                                                       \
    else x = strtod(buf, &endptr);

/**
 * @brief Macro to prompt the user to enter two numbers, parsing them as doubles.
 *
 * This macro performs the following steps:
 * 1. Declares a x and y variables to store the parsed values.
 * 2. Declares a buffer buf to hold user input.
 * 3. Prompts the user for a number.
 * 4. Checks if no input was provided and if true,
 * exits the program with `EXIT_FAILURE`.
 * 5. Otherwise, converts the input string from buf to a double,
 * storing the result in x.
 */
#define GET_NUMBERS                                                                                                    \
    double x, y;                                                                                                       \
    char buf[1024], *endptr;                                                                                           \
    printf("Enter the first number:\n");                                                                               \
                                                                                                                       \
    ERROR_ON_NO_INPUT                                                                                                  \
                                                                                                                       \
    else x = strtod(buf, &endptr);                                                                                     \
    printf("Enter the second number:\n");                                                                              \
                                                                                                                       \
    ERROR_ON_NO_INPUT                                                                                                  \
    else y = strtod(buf, &endptr);

#define QUIT_OPERATION "Pleasure doing calculations for you!\n"

/**
 * @brief Shows a menu for interaction.
 *
 * There's currently only two options:
 *
 * 1. [c]ontinue
 * 2. [q]uit
 *
 * c moves to the next menu, while q exits the program.
 * @return Usually EXIT_SUCCESS, as there's not much to fail here.
 */
extern int main_menu(void);

/**
 * @brief Menu showing the available operations.
 *
 * Currently available operations are:
 *
 * 1. Addition
 * 2. Subtraction
 * 3. Multiplication
 * 4. Division
 * 5. Power
 * 6. Factorial
 * @return EXIT_SUCCESS on no errors, EXIT_FAILURE otherwise.
 *
 * EXIT_FAILURE happens on lack of input.
 */
extern int operation(void);

/**
 * @brief Adds two numbers
 *
 * Using the GET_NUMBERS macro, read two numbers from stdin
 * to perform an addition.
 * @return EXIT_SUCCESS on no errors, EXIT_FAILURE otherwise.
 *
 * EXIT_FAILURE happens on lack of input.
 */
extern int addition(void);

/**
 * @brief Subtracts two numbers
 *
 * Using the GET_NUMBERS macro, read two numbers from stdin
 * to perform a subtraction.
 * @return EXIT_SUCCESS on no errors, EXIT_FAILURE otherwise.
 *
 * EXIT_FAILURE happens on lack of input.
 */
extern int subtraction(void);

/**
 * @brief Multiplies two numbers
 *
 * Using the GET_NUMBERS macro, read two numbers from stdin
 * to perform multiplication.
 * @return EXIT_SUCCESS on no errors, EXIT_FAILURE otherwise.
 *
 * EXIT_FAILURE happens on lack of input.
 */
extern int multiplication(void);

/**
 * @brief Divides two numbers
 *
 * Using the GET_NUMBERS macro, read two numbers from stdin
 * to perform a division.
 * @return EXIT_SUCCESS on no errors, EXIT_FAILURE otherwise.
 *
 * EXIT_FAILURE happens on lack of input.
 */
extern int division(void);

/**
 * @brief Performs a power operation
 *
 * A power operation involves multiplying an x number by itself
 * an y amount of times, so:
 *
 * pow(10, 2) = 100
 *
 * Because 10 * 10 = 100
 *
 * @param x The base
 * @param y The exponent
 * @return The result of the power operation.
 */
extern double pow(double x, double y);

/**
 * @brief Gets the power of a given base from a given exponent
 *
 * Using the GET_NUMBERS macro, read two numbers from stdin
 * to perform a power operation.
 * @return EXIT_SUCCESS on no errors, EXIT_FAILURE otherwise.
 *
 * EXIT_FAILURE happens on lack of input.
 */
extern int power(void);

/**
 * @brief Performs a factorial operation on a number
 *
 * A factorial, represented as "!", involves multiplying a given number
 * in a descending order, so:
 *
 * factor(5) = 120
 *
 * Because 5! = 5 * 4 * 3 * 2 * 1 = 120
 *
 * NOTE: When performing this type operation by hand, just omit the 1.
 * It's a waste of space.
 *
 * @param x The number to be factored.
 * @return The result of the factorial operation.
 */
extern double factor(double x);

/**
 * @brief Factors a number
 *
 * Using the GET_NUMBER macro, read one number from stdin
 * to perform factoring.
 * @return EXIT_SUCCESS on no errors, EXIT_FAILURE otherwise.
 *
 * EXIT_FAILURE happens on lack of input.
 */
extern int factorial(void);
