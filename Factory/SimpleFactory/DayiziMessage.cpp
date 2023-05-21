#include "DayiziMessage.h"

DayiziMessage::DayiziMessage(const std::string& appid, const std::string& secret, const std::string& publickey)
	: m_appid(appid)
	, m_secret(secret)
	, m_public_key(publickey)
{

}

int DayiziMessage::sendMessage(const std::string& number, const std::string& content)
{
	printf("Dayizi appid: %s, secret: %s, publickey: %s\n", m_appid.c_str(), m_secret.c_str(), m_public_key.c_str());
	printf("Dayizi sendMessage\n");
	return 0;
}