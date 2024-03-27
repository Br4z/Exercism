// URL: https://exercism.org/tracks/cpp/exercises/dnd-character DATE: 2024-02-18


#ifndef DND_CHARACTER_H
#define DND_CHARACTER_H


namespace dnd_character {
	int modifier(int constitution);
	int ability();

	class Character {
		public:
			Character();

			int charisma = ability();
			int constitution = ability();
			int dexterity = ability();
			int hitpoints = 10 + modifier(constitution);
			int intelligence = ability();
			int strength = ability();
			int wisdom = ability();
	};
}

#endif
