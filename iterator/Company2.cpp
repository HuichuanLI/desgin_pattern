#include "Company2.h"

int Company2::addStaff(const std::string& name, int age, const std::string& idcard)
{
	Staff* p = head;
	while (p->next != nullptr) {
		p = p->next;
	}

	p->next = new Staff(name, age, idcard);
	return 0;
}

Staff Company2::first()
{
	p = head->next;
	return *p;
}
Staff Company2::next()
{
	Staff s = *p;
	p = p->next;
	return s;
}
bool Company2::isEnd()
{
	if (p == nullptr) {
		return true;
	}
	return false;
}