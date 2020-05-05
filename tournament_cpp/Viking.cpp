/*
Fichier cpp de la classe Viking
Auteur : Gauthier Lecouffe
Cr�ation : 26/04/2020
Derni�re mise � jour : 05/05/2020
*/
#include "Viking.h"

void Viking::Attack(Fighter & other)
{
	// Utilise la fonction de la classe parent
	Fighter::Attack(other);
}

int Viking::HandleDamage(Fighter & other, int dmg)
{
	// Utilise la fonction de la classe parent
	return Fighter::HandleDamage(other, dmg);
}
