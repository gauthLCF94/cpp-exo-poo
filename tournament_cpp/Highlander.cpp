/*
Fichier cpp de la classe Highlander
Auteur : Gauthier Lecouffe
Création : 26/04/2020
Dernière mise à jour : 05/05/2020
*/
#include "Highlander.h"

// L'indentation est différente pour bien différentier les accesseurs et les méthodes membres
const HighlanderPerks Highlander::getPerk()						{ return m_perk; }
void Highlander::setPerk(HighlanderPerks perk)					{ m_perk = perk; }

void Highlander::Attack(Fighter &other)
{
	// Modification de la fonction par rapport à la classe parent
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
	// Modification de la fonction par rapport à la classe parent
	// afin de multiplier les dégâts quand les hp sont inférieurs à 30% des hp du départ
	if (getPerk() == HighlanderPerks::Veteran && HitPoints() < 150 * 0.3)
	{
		return Fighter::HandleDamage(other, dmg * 2);
	}
	else
		return Fighter::HandleDamage(other, dmg);
}
