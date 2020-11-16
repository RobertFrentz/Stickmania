#pragma once

#include <string>

class Gun
{
public:
	Gun();
	Gun(const char* _name, unsigned int _damage);
	~Gun();
	int getGunDamage();
private:
	
	std::string name;
	unsigned int damage;

};

