#include <iostream>
#include "Zergling.h"
#include "Marine.h"



Zergling::Zergling()
{
	maxHealth = STARTING_HEALTH;	
	health = STARTING_HEALTH;
}


Zergling::~Zergling()
{
}

int Zergling::attack()
{
	return DAMAGE;
}

void Zergling::update(std::vector<Marine>& targetList)
{
	int damage = attack();
	std::cout << ATTACK_MESSAGE << damage << " damage. " << std::endl;
	targetList.begin()->takeDamage(damage);									// Attack first marine in the squad
	if (!targetList.begin()->isAlive())
	{
		std::cout << Marine::DEATH_MESSAGE << std::endl;
		targetList.erase(targetList.begin());							// Remove killed marine from squad
	}
}

const std::string Zergling::ATTACK_MESSAGE = "A zergling attacks for ";
const std::string Zergling::DEATH_MESSAGE = "The zergling target dies";
