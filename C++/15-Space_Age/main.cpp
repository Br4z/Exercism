#include <iostream>

#include "space_age.h"


int main() {
	space_age::space_age age{ 2134835688 };

	std::cout << age.seconds() << std::endl;
	std::cout << age.on_earth() << std::endl;
	std::cout << age.on_mercury() << std::endl;
	std::cout << age.on_venus() << std::endl;
	std::cout << age.on_mars() << std::endl;
	std::cout << age.on_jupiter() << std::endl;
	std::cout << age.on_saturn() << std::endl;
	std::cout << age.on_uranus() << std::endl;
	std::cout << age.on_neptune() << std::endl;
	return 0;

}