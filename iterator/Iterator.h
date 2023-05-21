#pragma once

#include "Staff.h"

class Iterator
{
public:
	virtual Staff first() = 0;
	virtual Staff next() = 0;
	virtual bool isEnd() = 0;
};

