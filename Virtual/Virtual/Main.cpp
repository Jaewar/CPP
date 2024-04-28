#include <iostream>
#include <string>

class Entity
{
public:
	// defined in base class with the intention of overriding in derived classes.
	virtual std::string GetName() { return "Entity"; }
};

class Player : public Entity {
private:
	std::string m_Name;
public:
	Player(const std::string& name) : m_Name(name) {}

	// overriding the GetName from Entity to return the value provided in this class.
	std::string GetName() override { return m_Name; }
};

void PrintName(Entity* entity) {
	std::cout << entity->GetName() << std::endl;
}

int main() {
	// Using the virtual method to show entity
	Entity* e = new Entity();
	PrintName(e);

	// using the overriden virtual method for player.
	Player* p = new Player("Player");
	PrintName(p);

	std::cin.get();
}