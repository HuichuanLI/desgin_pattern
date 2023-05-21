#pragma once

#include <string>

class Message
{
public:
	virtual int sendMessage(const std::string & number, const std::string & content) = 0;
};

