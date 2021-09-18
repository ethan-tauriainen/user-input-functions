//
// Created by etcodr on 7/31/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "input.h"

// dynamically obtain a string of unspecified length from the user
char *get_string(char *prompt) {
    int c;
    char *str = malloc(sizeof(char));
    str[0] = '\0';

    printf("%s", prompt);
    for (int i = 0; (c = getchar()) != '\n'; i++) {
        str = realloc(str, (i + 2) * sizeof(char));
        str[i] = (char) c;
        str[i + 1] = '\0';
    }
    return str;
}

// ensure each character in a given string is a digit 0-9
bool check_digits(char *str) {
    bool sentinel = true;
    for (int i = 0; i < strlen(str); i++) {
        if (isdigit(str[i]) || str[i] == '.')   // the '.' to allow use with floats and doubles
            sentinel = true;
        else
            sentinel = false;
    }
    return sentinel;
}

// prompt user for an integer
// if anything other than an integer, prompt again
int get_int(char *prompt) {
    char *str;
    char *ptr;
    long i;

    while (true) {
        str = get_string(prompt);
        if (check_digits(str))
            break;
    }

    i = strtol(str, &ptr, 10);
    free(str);      // free memory allocated in the get_string function
    return (int) i;
}

// prompt user for a long integer
// if anything other than a long integer, prompt again
long get_long(char *prompt) {
    char *str;
    char *ptr;
    long l;

    while (true) {
        str = get_string(prompt);
        if (check_digits(str))
            break;
    }

    l = strtol(str, &ptr, 10);
    free(str);      // free memory allocated in the get_string function
    return l;
}

// prompt user for a floating point number
// if anything other than a float, prompt again
float get_float(char *prompt) {
    char *str;
    char *ptr;
    float f;

    while (true) {
        str = get_string(prompt);
        if (check_digits(str))
            break;
    }

    f = strtof(str, &ptr);
    free(str);      // free memory allocated in the get_string function
    return f;
}

// prompt user for a double
// if anything other than a double, prompt again
double get_double(char *prompt) {
    char *str;
    char *ptr;
    double d;

    while (true) {
        str = get_string(prompt);
        if (check_digits(str))
            break;
    }

    d = strtod(str, &ptr);
    free(str);
    return d;
}

// prompt user for a single char
// if anything other than a char, or more/less than one char, prompt again
char get_char(char *prompt) {
    char *str;
    char c;

    while (true) {
        str = get_string(prompt);
        if (isalpha(str[0]))
            break;
    }

    c = str[0];
    free(str);
    return c;
}
