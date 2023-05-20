#pragma once

#include <memory>
#include "Expression.h"

class AddExpression : public Expression
{
public:
	AddExpression(const std::shared_ptr<Expression> & _left, const std::shared_ptr<Expression>& _right) {
		left = _left;
		right = _right;
	}

	virtual int doFunc() override
	{
		return left->doFunc() + right->doFunc();
	}

	std::shared_ptr<Expression> left = nullptr;
	std::shared_ptr<Expression> right = nullptr;
};

