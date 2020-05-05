/*
Fichier cpp de la classe Highlander
Auteur : Gauthier Lecouffe
Cr�ation : 26/04/2020
Derni�re mise � jour : 05/05/2020
*/
#include "Highlander.h"

// L'indentation est diff�rente pour bien diff�rentier les accesseurs et les m�thodes membres
const HighlanderPerks Highlander::getPerk()						{ return m_perk; }
void Highlander::setPerk(HighlanderPerks perk)					{ m_perk = perk; }

void Highlander::Attack(Fighter &other)
{
	// Modification de la fonction par rapport � la classe parent
	// afin d'attaque 2 fois sur 3
	if (getAttackCount() == 0)
		Fighter::Attack(other);
	else if (getWeapon() == Weapon::GreatSword && getAttackCount() % 3 == 0)
		Fighter::setAttackCount();
	else
		Fighter::Attack(other);
}

int Highlander::HandleDamage(Fighter &other, int dmg)
{
	// Modification de la fonction par rapport � la classe parent
	// afin de multiplier les d�g�ts quand les hp sont inf�rieurs � 30% des hp du d�part
	if (getPerk() == HighlanderPerks::Veteran && HitPoints() < 150 * 0.3)
	{
		return Fighter::HandleDamage(other, dmg * 2);
	}
	else
		return Fighter::HandleDamage(other, dmg);
}
