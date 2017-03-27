#include "Zergling.h"



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

const std::string Zergling::ATTACK_MESSAGE = "A zergling attacks for ";
const std::string Zergling::DEATH_MESSAGE = "The zergling target dies";
