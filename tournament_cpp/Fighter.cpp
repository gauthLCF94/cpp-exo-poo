/*
Fichier cpp de la classe Fighter
Auteur : Gauthier Lecouffe
Cr�ation : 26/04/2020
Derni�re mise � jour : 05/05/2020
*/
#include "Fighter.h"

// Accesseurs
// L'indentation est diff�rente pour bien diff�rentier les accesseurs et les m�thodes membres
// Getters
const int Fighter::HitPoints()						{ return m_hitpoints; }
const Weapon Fighter::getWeapon()					{ return m_weapon; }
const bool Fighter::getBuckler()					{ return m_equipement["buckler"]; }
const bool Fighter::getArmor()						{ return m_equipement["armor"]; }
const BlockingState Fighter::getBlockingState()		{ return m_blockingState; }
const int Fighter::getBucklerDurability()			{ return m_bucklerDurability; }
const int Fighter::getAttackCount()					{ return m_attackCount; }
// Setters
void Fighter::setHitPoints(int hp)					{ m_hitpoints = hp; }
void Fighter::setWeapon(Weapon w)					{ m_weapon = w; }
void Fighter::setBuckler(bool b)					{ m_equipement["buckler"] = b; }
void Fighter::setArmor(bool b)						{ m_equipement["armor"] = b; }
void Fighter::setBlockingState(BlockingState bs)	{ m_blockingState = bs; }
void Fighter::setBucklerDurability()				{ m_bucklerDurability--; } // d�cr�mentation
void Fighter::setAttackCount()						{ m_attackCount++; } // incr�mentation

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
	// Fonction d'attaque
	setAttackCount(); // Incr�mentation du nombre d'attaque r�alis�.
	if (!other.TryToBlock(*this)) // Si la fonction TryToBlock renvoie true
	{
		other.isHit(HandleDamage(other, Damage())); // Application des dommages
	}
}

void Fighter::isHit(int dmg)
{
	// Ternaire v�rifiant si les hp ne sont pas < 0 apr�s l'application des dommages
	// si oui, met les hp � 0, si non, applique les dommages
	m_hitpoints = (m_hitpoints - dmg < 0) ? 0 : m_hitpoints - dmg;
}

int Fighter::Damage()
{
	// Switch modifiant les d�g�ts en fonction de l'arme utilis�
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
	// Fonction permettant d'�quip� un objet
	if (item == "buckler" || item == "armor")
	{
		m_equipement[item] = true;
	}
	else
	{
		if (item == "axe")
		{
			setWeapon(Weapon::Axe);
		}
		else if (item == "sword")
		{
			setWeapon(Weapon::Sword);
		}
		else if (item == "great sword")
		{
			setWeapon(Weapon::GreatSword);
		}
	}
}

bool Fighter::TryToBlock(Fighter &other)
{
	// Fonction g�rant le blocage (une fois sur deux)
	if (getBuckler())
	{
		if (getBlockingState() == BlockingState::Blocked)
		{
			setBlockingState(BlockingState::NotBlocked);
			return false; // met fin � la fonction avec un return
		}
		// Gestion de la destruction du bouclier si l'adversaire a une hache
		if (other.getWeapon() == Weapon::Axe)
		{
			setBucklerDurability();
			if (getBucklerDurability() == 0)
				setBuckler(false);
		}
		// Si on ne passe pas dans le 1er return  
		setBlockingState(BlockingState::Blocked);
		return true; //
	}
	// Si on ne passe pas dans les 2 premiers return
	setBlockingState(BlockingState::NotBlocked);
	return false;
}

int Fighter::HandleDamage(Fighter & other, int dmg)
{
	// Fonction permettant la modification des dommages en fonction des objets �quip�s
	if (getArmor()) // Si le Fighter a une armure
	{
		dmg--;
	}
	else if (other.getArmor()) // Si l'opposant a une armure
	{
		dmg = dmg - 3;
	}
	else if (getArmor() && other.getArmor()) // Si le Fighter et son opposant ont une armure
	{
		dmg = dmg - 1 - 3;
	}
	return dmg;
}
