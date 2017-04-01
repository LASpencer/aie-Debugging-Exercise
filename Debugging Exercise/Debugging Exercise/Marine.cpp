#include <iostream>
#include "Marine.h"
#include "Zergling.h"


Marine::Marine()
{
	maxHealth = STARTING_HEALTH;	
	health = STARTING_HEALTH;
}


Marine::~Marine()
{
}

int Marine::attack()
{
	return DAMAGE;	
}

void Marine::update(std::vector<Zergling>& targetList)
{
	int damage = attack();
	std::cout << ATTACK_MESSAGE << damage << " damage. " << std::endl;
	targetList.begin()->takeDamage(damage);										// Attack first zergling in the swarm
	if (!targetList.begin()->isAlive())
	{
		std::cout << Zergling::DEATH_MESSAGE << std::endl;
		targetList.erase(targetList.begin());								// Remove killed zergling from swarm
	}
}

const std::string Marine::ATTACK_MESSAGE = "A marine fires for ";
const std::string Marine::DEATH_MESSAGE = "The marine succumbs to his wounds.";

