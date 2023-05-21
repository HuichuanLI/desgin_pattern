#pragma once

#include <string>

class Staff
{
public:
	Staff(const std::string & _name, int _age, const std::string & _idcard);

	std::string name;
	int age;
	std::string idcard;

	Staff* next = nullptr;
};

