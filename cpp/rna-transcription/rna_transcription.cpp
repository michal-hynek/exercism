#include "rna_transcription.h"

#include <stdexcept>

namespace rna_transcription {

    char to_rna(char dna) {
        switch (dna) {
            case 'G':
                return 'C';
            case 'C':
                return 'G';
            case 'T':
                return 'A';
            case 'A':
                return 'U';
            default:
                throw invalid_argument("invalid argument");
        }
    }

    string to_rna(string dna) {
        string rna{};

        for (auto c : dna) {
            rna.push_back(to_rna(c));
        }

        return rna;
    }

}  // namespace rna_transcription
