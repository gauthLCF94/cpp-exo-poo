#include "Swordman.h"

const SwordsmanPerks Swordsman::getPerk() { return m_perk; }

void Swordsman::setPerks(SwordsmanPerks perk) { m_perk = perk; }

void Swordsman::Attack(Fighter &other) { Fighter::Attack(other); }

int Swordsman::HandleDamage(Fighter & other, int dmg)
{
	if (getPerk() == SwordsmanPerks::Vicious && getAttackCount() <= 2)
	{
		return Fighter::HandleDamage(other, dmg) + 20;
	}
	else
		return Fighter::HandleDamage(other, dmg);
}
