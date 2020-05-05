/*
Fichier cpp de la classe Swordman
Auteur : Gauthier Lecouffe
Création : 26/04/2020
Dernière mise à jour : 05/05/2020
*/
#include "Swordman.h"

// L'indentation est différente pour bien différentier les accesseurs et les méthodes membres
const SwordsmanPerks Swordsman::getPerk()						{ return m_perk; }
void Swordsman::setPerks(SwordsmanPerks perk)					{ m_perk = perk; }

void Swordsman::Attack(Fighter &other)
{
	// Utilise la fonction de la classe parent
	Fighter::Attack(other);
}

int Swordsman::HandleDamage(Fighter & other, int dmg)
{
	// Modification de la fonction par rapport à la classe parent
	// afin d'ajouter 20 pts de dommages aux 2 premières attaques
	if (getPerk() == SwordsmanPerks::Vicious && getAttackCount() <= 2)
	{
		return Fighter::HandleDamage(other, dmg) + 20;
	}
	else
		return Fighter::HandleDamage(other, dmg);
}
