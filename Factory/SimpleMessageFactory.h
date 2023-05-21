#pragma once

#include "Message.h"

enum MessageType
{
	Xiaojiuzi,
	Dayizi
};

class SimpleMessageFactory
{
public:
	static Message* createMessage(MessageType type);
};

