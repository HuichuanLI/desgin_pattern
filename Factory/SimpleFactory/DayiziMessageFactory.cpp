#include "DayiziMessageFactory.h"

#include "DayiziMessage.h"
#include "DayiziOverseaMessage.h"

Message* DayiziMessageFactory::createMessage()
{
	std::string appid = "567";
	std::string secret = "ewqevcxdsga";
	std::string publickey = "sdjafhjkfhjadskhfjkadshfjkashfas";
	return new DayiziMessage(appid, secret, publickey);
}

OverseaMessage* DayiziMessageFactory::createOverseaMessage()
{
	return new DayiziOverseaMessage();
}