#ifndef FIGHTER_H
#define FIGHTER_H

#pragma once
#include <string>
#include <map>
#include <iostream>

const enum class Weapon { Axe, Sword, GreatSword };
const enum class BlockingState { Blocked, NotBlocked };

class Fighter
{
// Attributs
private:
	int m_hitpoints;
	Weapon m_weapon;
	std::map <std::string, bool> m_equipement;
	BlockingState m_blockingState;
	int m_bucklerDurability;
	int m_attackCount;

// Méthodes
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
	const int HitPoints();
	const Weapon getWeapon();
	const bool getBuckler();
	const bool getArmor();
	const BlockingState getBlockingState();
	const int getBucklerDurability();
	const int getAttackCount();

	void setHitPoints(int hp);
	void setWeapon(Weapon w);
	void setBuckler(bool b);
	void setArmor(bool b);
	void setBlockingState(BlockingState bs);
	void setBucklerDurability();
	void setAttackCount();

	//Fonctions membres
	void Engage(Fighter &other);
	virtual void Attack(Fighter &other);
	void isHit(int dmg);
	int Damage();
	void Equip(std::string item);
	bool TryToBlock(Fighter &other);
	virtual int HandleDamage(Fighter &other, int dmg);
};

#endif

