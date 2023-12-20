// URL: https://exercism.org/tracks/cpp/exercises/rna-transcription DATE: 2023-12-19

#include <stdexcept>

#include "rna_transcription.h"


char rna_transcription::to_rna(char dna) {
	switch (dna) {
		case 'G': return 'C';
		case 'C': return 'G';
		case 'T': return 'A';
		case 'A': return 'U';
		default: std::invalid_argument("Invalid DNA nucleotide"); return dna;
	}
}

std::string rna_transcription::to_rna(std::string dna) {
	std::string rna = "";

	for (char c : dna) {
		rna += to_rna(c);
	}

	return rna;
}
