#include "XiaojiuziMessageFactory.h"

#include "XiaojiuziMessage.h"
#include "XiaojiuziOverseaMessage.h"

Message* XiaojiuziMessageFactory::createMessage()
{
	std::string appid = "123456";
	std::string secret = "adjksfhjdaskfhksa";
	return new XiaojiuziMessage(appid, secret);
}

OverseaMessage* XiaojiuziMessageFactory::createOverseaMessage()
{
	return new XiaojiuziOverseaMessage();
}