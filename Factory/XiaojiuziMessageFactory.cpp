#include "XiaojiuziMessageFactory.h"

#include "XiaojiuziMessage.h"

Message* XiaojiuziMessageFactory::createMessage()
{
	std::string appid = "123456";
	std::string secret = "adjksfhjdaskfhksa";
	return new XiaojiuziMessage(appid, secret);
}