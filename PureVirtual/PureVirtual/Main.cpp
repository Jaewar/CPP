#include <iostream>
#include <string>

// interface
class Printable {
public:
	virtual std::string GetClassName() = 0;
};

class Entity : public Printable
{
public:
	// defined in base class with the intention of overriding in derived classes.
	virtual std::string GetName() { return "Entity"; }
	// overriding the pure virtual function in Printable.
	std::string GetClassName() override { return "Entity"; }
};

class Player : public Entity {
private:
	std::string m_Name;
public:
	Player(const std::string& name) : m_Name(name) {}

	// overriding the GetName from Entity to return the value provided in this class.
	std::string GetName() override { return m_Name; }
	// overriding the pure virtual function in Printable.
	std::string GetClassName() override { return "Player"; }
};

void PrintName(Entity* entity) {
	std::cout << entity->GetName() << std::endl;
}

void Print(Printable* obj) {
	std::cout << obj->GetClassName() << std::endl;
}

int main() {
	// Using the virtual method to show entity
	Entity* e = new Entity();

	// using the overriden virtual method for player.
	Player* p = new Player("Player");

	// since Entity inherits Printable, so does the Player class.
	Print(e);
	Print(p);


	std::cin.get();
}