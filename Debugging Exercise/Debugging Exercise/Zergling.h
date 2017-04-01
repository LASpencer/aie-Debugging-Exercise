#pragma once

#include "Entity.h"
#include <vector>

class Marine;

class Zergling : public Entity
{
public:
	Zergling();
	~Zergling();

	int attack();
	void update(std::vector<Marine> &targetList);


	static const int STARTING_HEALTH = 10;
	static const int DAMAGE = 10;
	static const std::string ATTACK_MESSAGE;
	static const std::string DEATH_MESSAGE;
};

