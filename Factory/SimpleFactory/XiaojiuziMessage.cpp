#include "XiaojiuziMessage.h"

XiaojiuziMessage::XiaojiuziMessage(const std::string& appid, const std::string& secret)
	: m_appid(appid)
	, m_secret(secret)
{

}

int XiaojiuziMessage::sendMessage(const std::string& number, const std::string& content)
{
	printf("Xiaojiuzi appid: %s, secret: %s\n", m_appid.c_str(), m_secret.c_str());
	printf("Xiaojiuzi sendMessage\n");
	return 0;
}