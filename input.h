//
// Created by etcodr on 7/31/2021.
//
// Declares the various inputs and their functionality

#ifndef INPUT_FUNCTIONS_INPUT_H
#define INPUT_FUNCTIONS_INPUT_H

#include <stdbool.h>

// function prototypes
char *get_string(char *prompt);
bool check_digits(char *str);
int get_int(char *prompt);
long get_long(char *prompt);
float get_float(char *prompt);
double get_double(char *prompt);
char get_char(char *prompt);

#endif //INPUT_FUNCTIONS_INPUT_H
