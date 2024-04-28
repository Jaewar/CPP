#include <iostream>

class Entity {
public:
	float X, Y;

	void Move(float xa, float ya) {
		X += xa;
		Y += ya;
	}
};

// Inherits Entity and contains access to everything within Entity.
// Can also be passed to a function that requires Entity (polymorphism).
class Player : public Entity {
public:
	const char* Name;

	void PrintName() {
		std::cout << Name << std::endl;
	}
};

int main() {

	// Displaying memory sizes of each class
	std::cout << sizeof(Entity) << std::endl;
	std::cout << sizeof(Player) << std::endl;

	// Instance of Player
	Player player;

	// Showing that player can infact use the values from Entity.
	player.Move(5, 5);
	player.X = 2;
	player.Y = 3;

	std::cin.get();

}