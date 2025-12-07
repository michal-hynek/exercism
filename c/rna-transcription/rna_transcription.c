#include "rna_transcription.h"
#include <stdlib.h>
#include <string.h>

char *to_rna(const char *dna) {
    int offset = 0;
    char *rna = malloc(sizeof(char) * (strlen(dna) + 1));
    rna[strlen(dna)] = '\0';

    while (*(dna + offset) != '\0') {
        char dna_char = *(dna + offset);
        char rna_char = '-';

        if (dna_char == 'C') {
            rna_char = 'G';
        } else if (dna_char == 'G') {
            rna_char = 'C';
        } else if (dna_char == 'T') {
            rna_char = 'A';
        } else if (dna_char == 'A') {
            rna_char = 'U';
        }

        rna[offset] = rna_char;

        offset++;
    }

    return rna;
}
