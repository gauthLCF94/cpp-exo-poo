#include "Highlander.h"

const HighlanderPerks Highlander::getPerk()			{ return m_perk; }

void Highlander::setPerk(HighlanderPerks perk)		{ m_perk = perk; }

void Highlander::Attack(Fighter &other)
{
	if (getAttackCount() == 0)
		Fighter::Attack(other);
	else if (getWeapon() == Weapon::GreatSword && getAttackCount() % 3 == 0)
		setAttackCount();
	else
		Fighter::Attack(other);
}

int Highlander::HandleDamage(Fighter &other, int dmg)
{
	if (getPerk() == HighlanderPerks::Veteran && HitPoints() < 150 * 0.3)
	{
		return Fighter::HandleDamage(other, dmg * 2);
	}
	else
		return Fighter::HandleDamage(other, dmg);
}
