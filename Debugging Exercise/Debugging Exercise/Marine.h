#pragma once
#include "Entity.h"
#include <string>
#include <vector>

class Zergling;

class Marine : public Entity
{
public:
	Marine();
	~Marine();

	int attack();

	void update(std::vector<Zergling>& targetList);


	static const int STARTING_HEALTH = 50;
	static const int DAMAGE = 10;
	static const std::string ATTACK_MESSAGE;
	static const std::string DEATH_MESSAGE;
};

