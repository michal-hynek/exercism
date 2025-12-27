#include <math.h>
#include <stdio.h>
#include "resistor_color_trio.h"

long long pow10(int exp)  {
    long long result = 1;

    for (int i = 0; i < exp; i++) {
        result *= 10;
    }

    return result;
}

resistor_value_t color_code(resistor_band_t *bands) {
    long long exp = (long long) pow(10, bands[2]);
    long long value = (((long long) bands[0])*10ll + ((long long) bands[1])) * exp;
    resistor_unit_t unit = OHMS;

    if (value >= 1000ll && value < 1000000ll) {
        value /= 1000ll;
        unit = KILOOHMS;
    } else if (value >= 1000000ll && value < 1000000000ll) {
        value /= 1000000ll;
        unit = MEGAOHMS;
    } else if (value >= 1000000000ll) {
        value /= 1000000000ll;
        unit = GIGAOHMS;
    }

    resistor_value_t resistor_value = { .value = value, .unit = unit };

    return resistor_value;
}
