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

 Functionality for c-alculator.

Code:
 */

#define NO_INPUT !fgets(buf, sizeof(buf), stdin)

#define INTRO " ______ \n/ ____|\n| |     \n| |     \n| |____ \n\\_____| alculator\n\n[c]alculate [q]uit\n"

#define OPERATION_MENU "Operations:\n[1] Addition\n[2] Subtraction\n[3] Multiplication\n[4] Division\n[5] Power\n"

#define QUIT_OPERATION "Pleasure doing calculations for you!\n"

#define GET_NUMBERS                                                                                                    \
    double x, y;                                                                                                       \
    char buf[1024], *endptr;                                                                                           \
    printf("Enter the first number:\n");                                                                               \
    if (NO_INPUT)                                                                                                      \
        return FAILURE;                                                                                                \
    else                                                                                                               \
        x = strtod(buf, &endptr);                                                                                      \
    printf("Enter the second number:\n");                                                                              \
    if (NO_INPUT)                                                                                                      \
        return FAILURE;                                                                                                \
    else                                                                                                               \
        y = strtod(buf, &endptr);

extern int main_menu(void);

extern int operation(void);

extern int addition(void);

extern int subtraction(void);

extern int multiplication(void);

extern int division(void);

extern double pow(double x, double y);

extern int power(void);
#define SUCCESS 0
#define FAILURE -1
