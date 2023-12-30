// URL: https://exercism.org/tracks/cpp/exercises/protein-translation DATE: 2023-12-30

#include <unordered_map>

#include "protein_translation.h"


/**
 * A dictionary-like container that maps a string key to a string value.
 *
 * This unordered map is used as a translator to map codons (sequences of three nucleotides)
 * to their corresponding protein names. The keys are codons represented as strings, and the
 * values are the corresponding protein names.
 */
const std::unordered_map <std::string, std::string> translator = {
	{"AUG", "Methionine"}, {"UUU", "Phenylalanine"}, {"UUC", "Phenylalanine"},
	{"UUA", "Leucine"},    {"UUG", "Leucine"},       {"UCU", "Serine"},
	{"UCC", "Serine"},     {"UCA", "Serine"},        {"UCG", "Serine"},
	{"UAU", "Tyrosine"},   {"UAC", "Tyrosine"},      {"UGU", "Cysteine"},
	{"UGC", "Cysteine"},   {"UGG", "Tryptophan"},    {"UAA", "STOP"},
	{"UAG", "STOP"},       {"UGA", "STOP"}
};

/**
 * Translates RNA sequences into proteins.
 *
 * @param rna The RNA sequence to be translated.
 * @return The translated RNA sequence.
 */
std::vector <std::string> protein_translation::proteins(std::string rna) {
	std::vector <std::string> polypeptide;

	for (int i = 0; i < (int) rna.length() / 3; i++) {
		std::string protein = translator.at(rna.substr(i * 3, 3));

		if (protein == "STOP")
			break;

		polypeptide.push_back(protein);
	}

	return polypeptide;
}
