#ifndef SWORDSMAN_H
#define SWORDSMAN_H

#pragma once
#include "Fighter.h"

 const enum class SwordsmanPerks { None, Vicious };

class Swordsman : public Fighter
{
private:
	// Attributs
	SwordsmanPerks m_perk;
public:
	// Contructeurs
	Swordsman() : Fighter(100, Weapon::Sword)
	{
		m_perk = SwordsmanPerks::None;
	}
	Swordsman(std::string perks) : Fighter(100, Weapon::Sword)
	{
		if (perks == "Vicious")
			m_perk = SwordsmanPerks::Vicious;
	}

	// Accesseurs
	const SwordsmanPerks getPerk();
	void setPerks(SwordsmanPerks perk);

	// Fonctions membres
	void Attack(Fighter &other);
	int HandleDamage(Fighter &other, int dmg);
};

#endif

