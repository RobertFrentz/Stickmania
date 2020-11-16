#include "Gun.h"


Gun::Gun()
{
}

Gun::Gun(const char * _name, unsigned int _damage)
{
	name = _name;
	damage = _damage;
}

Gun::~Gun()
{
}

int Gun::getGunDamage()
{
	return damage;
}
