#ifndef LUHN_H
#define LUHN_H

#include <stdbool.h>

bool luhn(const char *num);
void remove_spaces(const char *input, char *output);

#endif
