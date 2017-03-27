#include "Marine.h"



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

// TODO move string constants to their own file (rewriting/localization reusability)
const std::string Marine::ATTACK_MESSAGE = "A marine fires for ";
const std::string Marine::DEATH_MESSAGE = "The marine succumbs to his wounds.";

