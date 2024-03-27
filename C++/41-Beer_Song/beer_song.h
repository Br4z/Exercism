// URL: https://exercism.org/tracks/cpp/exercises/beer-song DATE: 2024-01-05

#include <string>

#ifndef BEER_SONG_H
#define BEER_SONG_H


namespace beer_song {
	std::string verse(int verse);
	std::string sing(int start, int end = 0);
}

#endif
