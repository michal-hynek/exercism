#include "two_fer.h"

#include <stdio.h>
#include <string.h>

void two_fer(char *buffer, const char *name) {
    char *receiver = (char *) name;

    if (name == NULL || strlen(name) == 0) {
        receiver = "you";
    }

    sprintf(buffer, "One for %s, one for me.", receiver);
}