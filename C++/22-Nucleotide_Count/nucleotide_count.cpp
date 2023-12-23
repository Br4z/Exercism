// URL: https://exercism.org/tracks/cpp/exercises/nucleotide-count DATE: 2023-12-18

#include "nucleotide_count.h"

#include <stdexcept>


/**
 * Counts the nucleotides in the given dna.
 *
 * The key of the map is a character representing a nucleotide (A, C, G, or T),
 * and the value is an integer representing the count of that nucleotide.
 *
 * @return The map that stores the count of nucleotides.
 */
std::map <char, int> nucleotide_count::count(std::string dna) {
	std::map <char, int> nucleotide_count;
	nucleotide_count['A'] = 0;
	nucleotide_count['C'] = 0;
	nucleotide_count['G'] = 0;
	nucleotide_count['T'] = 0;

	for (int i = 0; i < (int) dna.length(); i++) {
		if (dna[i] == 'A') {
			nucleotide_count['A']++;
		} else if (dna[i] == 'C') {
			nucleotide_count['C']++;
		} else if (dna[i] == 'G') {
			nucleotide_count['G']++;
		} else if (dna[i] == 'T') {
			nucleotide_count['T']++;
		} else {
			throw std::invalid_argument("Invalid nucleotide in strand");
		}
	}

	return nucleotide_count;
}
