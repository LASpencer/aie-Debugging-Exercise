#pragma once
#include "Entity.h"
#include <string>
#include <vector>

class Marine : public Entity
{
public:
	Marine();
	~Marine();

	int attack();
	template <typename T>
	void update(std::vector<T>& targetList)								//HACK instead of template, change vector to entity 
	{
		int damage = attack();
		cout << ATTACK_MESSAGE << damage << " damage. " << endl;
		targetList[0].takeDamage(damage);
		if (!targetList[0].isAlive())
		{
			cout << T::DEATH_MESSAGE<<endl;
			targetList.erase(targetList.begin());
		}
	}


	static const int STARTING_HEALTH = 50;
	static const int DAMAGE = 10;
	static const std::string ATTACK_MESSAGE;
	static const std::string DEATH_MESSAGE;
};

