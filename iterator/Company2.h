#pragma once

#include "Staff.h"
#include "Iterator.h"

class Company2 : public Iterator
{
public:
	int addStaff(const std::string & name, int age, const std::string & idcard);

	Staff* head = new Staff("", 0, "");

	virtual Staff first() override;
	virtual Staff next() override;
	virtual bool isEnd() override;

	Staff* p = nullptr;
};

