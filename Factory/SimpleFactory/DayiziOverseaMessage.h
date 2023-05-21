#pragma once

#include "OverseaMessage.h"

class DayiziOverseaMessage : public OverseaMessage
{
public:
	virtual int sendMessage(const std::string& number, const std::string& content, const std::string& code) override;
};

