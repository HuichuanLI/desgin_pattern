//
// Created by lhc456 on 2023/5/21.
//

#include <memory>
#include "Expression.h"

class SubExpression : public Expression {
public:
    SubExpression(const std::shared_ptr<Expression> &_left, const std::shared_ptr<Expression> &_right) {
        left = _left;
        right = _right;
    }

    virtual int doFunc() override {
        return left->doFunc() - right->doFunc();
    }

    std::shared_ptr<Expression> left = nullptr;
    std::shared_ptr<Expression> right = nullptr;
};