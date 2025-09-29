#include "protein_translation.h"

#include <unordered_map>

using namespace std;

namespace protein_translation {

    const unordered_map<string, string> codon_mappings = {
        { "AUG", "Methionine" },
        { "UUU", "Phenylalanine"},
        { "UUC", "Phenylalanine"},
        { "UUA", "Leucine" },
        { "UUG", "Leucine" },
        { "UCU", "Serine" },
        { "UCC", "Serine" },
        { "UCA", "Serine" },
        { "UCG", "Serine" },
        { "UAU", "Tyrosine" },
        { "UAC", "Tyrosine" },
        { "UGU", "Cysteine" },
        { "UGC", "Cysteine" },
        { "UGG", "Tryptophan" },
        { "UAA", "stop" },
        { "UAG", "stop" },
        { "UGA", "stop" },
    };

    vector<string> proteins(string input) {
        vector<string> protein_list{};

        for (unsigned int i = 0; i < input.length(); i += 3) {
            auto codon = input.substr(i, 3);
            auto amino_acid = codon_mappings.at(codon);

            if (amino_acid == "stop") {
                break;
            }

            protein_list.emplace_back(amino_acid);
        }

        return protein_list;
    }

}  // namespace protein_translation
