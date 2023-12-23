// URL: https://exercism.org/tracks/cpp/exercises/rna-transcription DATE: 2023-12-19

#include <stdexcept>

#include "rna_transcription.h"


/**
 * Transcribes a DNA nucleotide to its corresponding RNA nucleotide.
 *
 * @param dna The DNA nucleotide to be transcribed.
 * @return The corresponding RNA nucleotide.
 * @throws std::invalid_argument if the input DNA nucleotide is invalid.
 */
char rna_transcription::to_rna(char dna) {
	switch (dna) {
		case 'G': return 'C';
		case 'C': return 'G';
		case 'T': return 'A';
		case 'A': return 'U';
		default: std::invalid_argument("Invalid DNA nucleotide"); return dna;
	}
}

/**
 * Transcribes a DNA sequence to its corresponding RNA sequence.
 *
 * @param dna The DNA sequence to be transcribed.
 * @return The transcribed RNA sequence.
 */
std::string rna_transcription::to_rna(std::string dna) {
	std::string rna = "";

	for (char c : dna)
		rna += to_rna(c);

	return rna;
}
