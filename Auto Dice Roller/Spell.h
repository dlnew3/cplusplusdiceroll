#pragma once
#include <string>
using namespace std;
class Spell
{
private:
	string name;
	int base_level, num_dice, damage_dice;
public:
	int roll_base(int num_dice, int damage_dice);

};

