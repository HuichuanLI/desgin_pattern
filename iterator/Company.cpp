#include "Company.h"

int Company::addStaff(const std::string& name, int age, const std::string& idcard)
{
	Staff s(name, age, idcard);
	staffVec.push_back(s);
	return 0;
}

Staff Company::first()
{
	pos = 0;
	return staffVec[0];
}

Staff Company::next()
{
	Staff s = staffVec[pos];
	pos += 1;
	return s;
}

bool Company::isEnd()
{
	if (pos >= staffVec.size()) {
		return true;
	}
	return false;
}