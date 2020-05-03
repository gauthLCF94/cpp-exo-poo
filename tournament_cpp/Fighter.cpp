#include "Fighter.h"

// Accesseurs
const int Fighter::HitPoints()						{ return m_hitpoints; }
const Weapon Fighter::getWeapon()					{ return m_weapon; }
const bool Fighter::getBuckler()					{ return m_equipement["buckler"]; }
const bool Fighter::getArmor()						{ return m_equipement["armor"]; }
const BlockingState Fighter::getBlockingState()		{ return m_blockingState; }
const int Fighter::getBucklerDurability()			{ return m_bucklerDurability; }
const int Fighter::getAttackCount()					{ return m_attackCount; }

void Fighter::setHitPoints(int hp)					{ m_hitpoints = hp; }
void Fighter::setWeapon(Weapon w)					{ m_weapon = w; }
void Fighter::setBuckler(bool b)					{ m_equipement["buckler"] = b; }
void Fighter::setArmor(bool b)						{ m_equipement["armor"] = b; }
void Fighter::setBlockingState(BlockingState bs)	{ m_blockingState = bs; }
void Fighter::setBucklerDurability()				{ m_bucklerDurability--; }
void Fighter::setAttackCount()						{ m_attackCount++; }

// Fonctions membres
void Fighter::Engage(Fighter &other)
{
	while (HitPoints() > 0)
	{
		Attack(other);

		if (other.HitPoints() <= 0)
			break;
		
		other.Attack(*this);
	}
}

void Fighter::Attack(Fighter &other)
{
	setAttackCount();
	if (!other.TryToBlock(*this))
	{
		other.isHit(HandleDamage(other, Damage()));
	}
}

void Fighter::isHit(int dmg)
{
	m_hitpoints = (m_hitpoints - dmg < 0) ? 0 : m_hitpoints - dmg;
}

int Fighter::Damage()
{
	switch (getWeapon())
	{
	case Weapon::Axe:
		return 6;
	case Weapon::Sword:
		return 5;
	case Weapon::GreatSword:
		return 12;
	default:
		return 0;
	}
}

void Fighter::Equip(std::string item)
{
	if (item == "buckler" || item == "armor") { m_equipement[item] = true; }
	else
	{
		if (item == "axe") { setWeapon(Weapon::Axe); }
		else if (item == "sword") { setWeapon(Weapon::Sword); }
		else if (item == "great sword") { setWeapon(Weapon::GreatSword); }
	}
}

bool Fighter::TryToBlock(Fighter &other)
{
	if (getBuckler())
	{
		if (getBlockingState() == BlockingState::Blocked)
		{
			setBlockingState(BlockingState::NotBlocked);
			return false;
		}

		if (other.getWeapon() == Weapon::Axe)
		{
			setBucklerDurability();
			if (getBucklerDurability() == 0)
				setBuckler(false);
		}
		setBlockingState(BlockingState::Blocked);
		return true;
	}
	setBlockingState(BlockingState::NotBlocked);
	return false;
}

int Fighter::HandleDamage(Fighter & other, int dmg)
{
	if (getArmor())
	{
		dmg--;
	}
	else if (other.getArmor())
	{
		dmg = dmg - 3;
	}
	else if (getArmor() && other.getArmor())
	{
		dmg = dmg - 1 - 3;
	}
	return dmg;
}
