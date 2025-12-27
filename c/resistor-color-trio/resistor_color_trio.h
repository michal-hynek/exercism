#ifndef RESISTOR_COLOR_TRIO_H
#define RESISTOR_COLOR_TRIO_H

typedef enum {
    BLACK,
    BROWN,
    RED,
    ORANGE,
    YELLOW,
    GREEN,
    BLUE,
    VIOLET,
    GREY,
    WHITE
} resistor_band_t;

typedef enum {
    OHMS,
    KILOOHMS,
    MEGAOHMS,
    GIGAOHMS,
} resistor_unit_t;

typedef struct {
    long long value;
    resistor_unit_t unit;
} resistor_value_t;

long long pow10(int exp);

resistor_value_t color_code(resistor_band_t *bands);

#endif
