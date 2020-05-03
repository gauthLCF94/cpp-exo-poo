#ifndef HIGHLANDER_H
#define HIGHLANDER_H

#pragma once
#include "Fighter.h"

const enum class HighlanderPerks { None, Veteran };

class Highlander : public Fighter
{
private:
	HighlanderPerks m_perk;
public:
	//Constructeurs
	Highlander() : Fighter(150, Weapon::GreatSword)
	{
		m_perk = HighlanderPerks::None;
	}
	Highlander(std::string perks) : Fighter(150, Weapon::GreatSword)
	{
		if (perks == "Veteran")
			m_perk = HighlanderPerks::Veteran;
	}

	// Accesseurs
	const HighlanderPerks getPerk();

	void setPerk(HighlanderPerks perk);

	// Fonctions membres
	void Attack(Fighter &other);
	int HandleDamage(Fighter &other, int dmg);
};

#endif
