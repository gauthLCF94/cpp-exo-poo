/*
Fichier header de la classe Highlander
Auteur : Gauthier Lecouffe
Création : 26/04/2020
Dernière mise à jour : 05/05/2020
*/
#ifndef HIGHLANDER_H
#define HIGHLANDER_H

#pragma once
#include "Fighter.h"

// Enumerator des avantages du Highlander
const enum class HighlanderPerks { None, Veteran };

class Highlander : public Fighter
{
private:
	HighlanderPerks m_perk;
public:
	//Constructeurs
	Highlander() : Fighter(150, Weapon::GreatSword)
	{
		// Un constructeur par défaut qui utilise le constructeur de la classe parent
		// puis initialise les propres attributs de la classe
		m_perk = HighlanderPerks::None;
	}
	Highlander(std::string perks) : Fighter(150, Weapon::GreatSword)
	{
		// Un second constructeur utilisat toujours le constructeur de la classe parent
		// et avec paramètres permettant l'initialisation de l'avantage du Swordman
		if (perks == "Veteran")
			m_perk = HighlanderPerks::Veteran;
		else
			m_perk = HighlanderPerks::None;
	}

	// Accesseurs
	const HighlanderPerks getPerk(); // getter
	void setPerk(HighlanderPerks perk); // setter

	// Fonctions membres
	void Attack(Fighter &other);
	int HandleDamage(Fighter &other, int dmg);
};

#endif
