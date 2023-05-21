#include <iostream>

#include "Staff.h"
#include "Company.h"
#include "Company2.h"

int main()
{
    Company company;
    company.addStaff("XiaoMu", 28, "123456");
    company.addStaff("LaoLiu", 25, "789213");
    company.addStaff("LaoQi", 33, "2345678");

    company.first();
    while (!company.isEnd()) {
        Staff s = company.next();
        printf("Name: %s\n", s.name.c_str());
    }

    Company2 company2;
    company2.addStaff("XiaoMu", 28, "123456");
    company2.addStaff("LaoLiu", 25, "789213");
    company2.addStaff("LaoQi", 33, "2345678");

    company2.first();
    while (!company2.isEnd()) {
        Staff s = company2.next();
        printf("Name: %s\n", s.name.c_str());
    }

    /*
    for (int i = 0; i < company.staffVec.size(); i++) {
        Staff s = company.staffVec[i];
        printf("Name: %s\n", s.name.c_str());
    }
    

    Staff* p = company2.head->next;
    while (p != nullptr) {
        printf("Name: %s\n", p->name.c_str());
        p = p->next;
    }
    */

    return 0;
}