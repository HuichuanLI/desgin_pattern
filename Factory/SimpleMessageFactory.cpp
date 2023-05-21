#include "SimpleMessageFactory.h"

#include "XiaojiuziMessage.h"
#include "DayiziMessage.h"

Message* SimpleMessageFactory::createMessage(MessageType type)
{
	if (type == Xiaojiuzi) {
		std::string appid = "123456";
		std::string secret = "adjksfhjdaskfhksa";
		return new XiaojiuziMessage(appid, secret);
	}
	if (type == Dayizi) {
		std::string appid = "567";
		std::string secret = "ewqevcxdsga";
		std::string publickey = "sdjafhjkfhjadskhfjkadshfjkashfas";
		return new DayiziMessage(appid, secret, publickey);
	}
	return nullptr;
}