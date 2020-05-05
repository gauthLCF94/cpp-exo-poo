/*
Fichier header de la classe Swordman
Auteur : Gauthier Lecouffe
Création : 26/04/2020
Dernière mise à jour : 05/05/2020
*/
#ifndef SWORDSMAN_H
#define SWORDSMAN_H

#pragma once
#include "Fighter.h"

// Enumerator des avantages du Swordman
const enum class SwordsmanPerks { None, Vicious };

class Swordsman : public Fighter
{
private:
	// Attributs
	SwordsmanPerks m_perk; // Avantage du swordman
public:
	// Contructeurs
	Swordsman() : Fighter(100, Weapon::Sword)
	{
		// Un constructeur par défaut qui utilise le constructeur de la classe parent
		// puis initialise les propres attributs de la classe
		m_perk = SwordsmanPerks::None;
	}
	Swordsman(std::string perks) : Fighter(100, Weapon::Sword)
	{
		// Un second constructeur utilisat toujours le constructeur de la classe parent
		// et avec paramètres permettant l'initialisation de l'avantage du Swordman
		if (perks == "Vicious")
			m_perk = SwordsmanPerks::Vicious;
		else
			m_perk = SwordsmanPerks::None;
	}

	// Accesseurs
	const SwordsmanPerks getPerk(); // getter
	void setPerks(SwordsmanPerks perk); // setter

	// Fonctions membres
	void Attack(Fighter &other);
	int HandleDamage(Fighter &other, int dmg);
};

#endif

