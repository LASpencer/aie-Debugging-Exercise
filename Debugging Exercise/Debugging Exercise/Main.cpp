// A Debugging Exercise by Marc Chee (marcc@aie.edu.au)
// 18/12/2016

// Marines are trying to "de-bug" an area (haha . . . haha)
// However something's up with this code . . . figure out what's going wrong
// When you're finished, there should be no compiler errors or warnings
// The encounter should also run and finish correctly as per the rules in the comments

// In many cases there are differences between what's in otherwise identical sections
// for Marines and Zerglings. It's good to be able to tell what the differences are
// and why they might be important.

// What's efficient and inefficient? Why?
// What uses more memory and what doesn't? Why?

#include <iostream>
#include <vector>
#include "Marine.h"
#include "Zergling.h"

using std::vector;
using std::cout;
using std::endl;

bool marineAlive(vector<Marine> squad);
bool zerglingAlive(vector<Zergling> swarm);
template <typename T>
bool teamAlive(vector<T> team);

int main()
{
	vector<Marine> squad;
	vector<Zergling> swarm;

	int squadSize = 10;
	int swarmSize = 20;

	// Set up the Squad and the Swarm at their initial sizes listed above

	Marine m;
	for (size_t i = 0; i < squadSize; i++)
	{
		squad.push_back(m);
	}

	Zergling z;
	for (size_t i = 0; i < swarmSize; i++)
	{
		swarm.push_back(z);
	}

	cout << "A squad of marines approaches a swarm of Zerglings and opens fire! The Zerglings charge!" << endl;
	// Attack each other until only one team is left alive
	while (teamAlive(squad) && teamAlive(swarm)) // If both sides are still alive
	{
		if (teamAlive(squad)) // if there's at least one marine alive
		{
			for (size_t i = 0; i < squad.size(); i++) // go through the squad	TODO make this like zergling iterator
			{
				// TODO extract out as update function
				// each marine will attack the first zergling in the swarm
				//cout << "A marine fires for " << squad[i].attack() << " damage. " << endl;
				//int damage = squad[i].attack();
				//swarm[0].takeDamage(damage);
				//if (!swarm[0].isAlive()) // if the zergling dies, it is removed from the swarm
				//{
				//	cout << "The zergling target dies" << endl;
				//	swarm.erase(swarm.begin());
				//}
				squad[i].update(swarm);
				if (!teamAlive(swarm))	// if last zergling was killed, stop attacking
				{	
					break;
				}
			}
		}
		if (teamAlive(swarm)) // if there's at least one zergling alive
		{
			for (vector<Zergling>::iterator i = swarm.begin(); i != swarm.end(); ++i) // loop through zerglings
			{
				// TODO extract out as update function
				/*cout << "A zergling attacks for " << i->attack() << " damage." << endl;
				squad.begin()->takeDamage(i->attack());
				if (!squad.begin()->isAlive())
				{
					squad.erase(squad.begin());
					cout << "The marine succumbs to his wounds." << endl;
				}*/
				i->update(squad);
				if (!teamAlive(squad))	// if last marine was killed, stop attacking
				{
					break;
				}
					
			}
		}
	}

	// Once one team is completely eliminated, the fight ends and one team wins
	cout << "The fight is over. ";
	if (teamAlive(squad))
	{
		cout << "The Marines win." << endl;
	} else if (teamAlive(swarm))
	{
		cout << "The Zerg win." << endl;
	} else
	{
		cout << "It was a draw." << endl;
	}
}



// Is there a Marine Alive?
bool marineAlive(vector<Marine> squad)
{
	return squad.size() > 0;
}

// Is there a zergling Alive
bool zerglingAlive(vector<Zergling> swarm)
{
	return swarm.size()>0;
}

template <typename T>
bool teamAlive(vector<T> team)
{
	return team.size() > 0;
}
