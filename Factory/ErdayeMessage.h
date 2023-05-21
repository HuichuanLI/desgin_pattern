#pragma once

#include "Message.h"

class ErdayeMessage : public Message
{
public:
	virtual int sendMessage(const std::string& number, const std::string& content) override;
};

