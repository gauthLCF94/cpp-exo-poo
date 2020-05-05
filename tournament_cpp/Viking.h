/*
Fichier header de la classe Viking
Auteur : Gauthier Lecouffe
Cr�ation : 26/04/2020
Derni�re mise � jour : 05/05/2020
*/
#ifndef VIKING_H
#define VIKING_H

#pragma once
#include "Fighter.h"

class Viking : public Fighter
{
public:
	// Contructeur
	Viking() : Fighter(120, Weapon::Axe) {}
	
	// Fonction membre
	void Attack(Fighter &other);
	int HandleDamage(Fighter &other, int dmg);
};

#endif

