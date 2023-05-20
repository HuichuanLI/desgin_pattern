#include <iostream>
#include <string>
#include <stack>

#include "ValExpression.h"
#include "AddExpression.h"
#include "SubExpression.h"

int main() {
    std::string expStr = "1+2+3+8-5";

    std::stack<std::shared_ptr<Expression>> stack;

    for (int i = 0; i < expStr.size(); i++) {
        char c = expStr[i];
        if (c == '+') {
            int number = expStr[++i] - '0';
            std::shared_ptr<ValExpression> right = std::make_shared<ValExpression>(number);
            std::shared_ptr<Expression> left = stack.top();
            std::shared_ptr<AddExpression> add = std::make_shared<AddExpression>(left, right);
            stack.push(add);
        } else if (c == '-') {
            int number = expStr[++i] - '0';
            std::shared_ptr<ValExpression> right = std::make_shared<ValExpression>(number);
            std::shared_ptr<Expression> left = stack.top();
            std::shared_ptr<SubExpression> sub = std::make_shared<SubExpression>(left, right);
            stack.push(sub);
        } else {
            std::shared_ptr<ValExpression> val = std::make_shared<ValExpression>(c - '0');
            stack.push(val);
        }
    }

    int res = stack.top()->doFunc();

    printf("Res: %d\n", res);

    return 0;
}
