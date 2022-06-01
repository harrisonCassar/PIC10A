#include "Character.h"

Character::Character(string newName)
{
	this->name = newName;
	this->health = 20;
	this->damage = 2;
	this->arrows = 2;
}

Character::Character(string newName, int newHealth, int newDamage, int newArrows)
{
	this->name = newName;
	this->health = newHealth;
	this->damage = newDamage;
	this->arrows = newArrows;
}

void Character::attack(Character& target)
{
	// notify user of attack
	std::cout << this->get_name() << " attacks " << target.get_name() << " doing " << this->damage << " damage!" << std::endl;

	// damage target (change resultant health)
	target.set_health(target.get_health() - this->damage);

	// notify user of result of attack
	std::cout << target.get_name() << " health: " << target.get_health() << std::endl;
}

void Character::rangedAttack(Character& target)
{
	// determine if we can attack (check arrow inventory)
	if (this->arrows <= 0)
	{
		// notify user of attack
		std::cout << this->get_name() << " is out of arrows!" << std::endl;

		return;
	}

	// determine amount of damage to deal
	int damage_dealt = (rand() % 5) + 1;

	// notify user of attack
	std::cout << this->get_name() << " shoots " << target.get_name() << " doing " << damage_dealt << " damage!" << std::endl;

	// damage target (change resultant health)
	target.set_health(target.get_health() - damage_dealt);

	// notify user of result of attack
	std::cout << target.get_name() << " health: " << target.get_health() << std::endl;

	// reduce arrow count
	this->arrows--;

}

void Character::set_health(int newHealth)
{
	this->health = newHealth;
}

int Character::get_health() const
{
	return this->health;
}

string Character::get_name() const
{
	return this->name;
}

void Character::display() const
{
	std::cout << "Hero health: " << this->health << "  arrows: " << this->arrows << std::endl;
}