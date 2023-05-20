#pragma once

#include "Expression.h"

class ValExpression : public Expression
{
public:
	ValExpression(int _val) {
		val = _val;
	}

	virtual int doFunc() override
	{
		return val;
	}
	int val = 0;
};

