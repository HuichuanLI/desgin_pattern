#pragma once

#include <string>

class OverseaMessage
{
public:
	virtual int sendMessage(const std::string & number, const std::string & content, const std::string & code) = 0;
};

