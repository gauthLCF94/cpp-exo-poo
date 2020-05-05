/*
Fichier header de la classe Fighter
Auteur : Gauthier Lecouffe
Cr�ation : 26/04/2020
Derni�re mise � jour : 05/05/2020
*/
#ifndef FIGHTER_H
#define FIGHTER_H

#pragma once
#include <string>
#include <map>
#include <iostream>

const enum class Weapon { Axe, Sword, GreatSword }; // Enumerator pour les 3 armes disponibles dans le jeu
const enum class BlockingState { Blocked, NotBlocked }; // Enumerator pour l'�tat du blocage de la pr�c�dente attaque
class Fighter
{
// Attributs
private:
	int m_hitpoints;
	Weapon m_weapon; // Arme du type enumerator d�fini plus haut
	std::map <std::string, bool> m_equipement; // map : un tableau cl�/valeur pour l'�quipement (true si �quip�, false si non)
	BlockingState m_blockingState; // Etat du blocage d�fini plus haut
	int m_bucklerDurability;
	int m_attackCount;

// M�thodes
public:
	//Constructeur
	Fighter(int pv, Weapon w)
	{
		m_hitpoints = pv;
		m_weapon = w;
		m_equipement["buckler"] = false;
		m_equipement["armor"] = false;
		m_blockingState = BlockingState::NotBlocked;
		m_bucklerDurability = 3;
		m_attackCount = 0;
	}

	// Accesseurs
	// Getters
	const int HitPoints();
	const Weapon getWeapon();
	const bool getBuckler();
	const bool getArmor();
	const BlockingState getBlockingState();
	const int getBucklerDurability();
	const int getAttackCount();
	// Setters
	void setHitPoints(int hp);
	void setWeapon(Weapon w);
	void setBuckler(bool b);
	void setArmor(bool b);
	void setBlockingState(BlockingState bs);
	void setBucklerDurability();
	void setAttackCount();

	//Fonctions membres
	void Engage(Fighter &other);
	virtual void Attack(Fighter &other); // La fonction est plac� en virtual pour modifier son comportement via les classes d�riv�s
	void isHit(int dmg);
	int Damage();
	void Equip(std::string item);
	bool TryToBlock(Fighter &other);
	virtual int HandleDamage(Fighter &other, int dmg); // De m�me que pour la fonction Attack
};

#endif

