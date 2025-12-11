#include "eliuds_eggs.h"

unsigned int egg_count(unsigned int display) {
    unsigned int eggs = 0;

    for (int i = 0; i < 32; i++) {
        if (((1 << i) & display) != 0) {
            eggs++;
        }
    }

    return eggs;
}