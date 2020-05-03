#include "Viking.h"

void Viking::Attack(Fighter & other) { Fighter::Attack(other); }

int Viking::HandleDamage(Fighter & other, int dmg) { return Fighter::HandleDamage(other, dmg); }
