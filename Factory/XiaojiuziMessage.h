#pragma once

#include "Message.h"

class XiaojiuziMessage : public Message
{
public:
	XiaojiuziMessage(const std::string & appid, const std::string & secret);
	virtual int sendMessage(const std::string& number, const std::string& content) override;

private:
	std::string m_appid;
	std::string m_secret;
};

