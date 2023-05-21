#pragma once

#include "Message.h"

class DayiziMessage : public Message
{
public:
	DayiziMessage(const std::string & appid, const std::string & secret, const std::string & publickey);
	virtual int sendMessage(const std::string& number, const std::string& content) override;

	std::string m_appid;
	std::string m_secret;
	std::string m_public_key;
};

