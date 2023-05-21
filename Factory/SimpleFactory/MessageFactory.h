#pragma once

#include "Message.h"
#include "OverseaMessage.h"

class MessageFactory
{
public:
	virtual Message* createMessage() = 0;
	virtual OverseaMessage * createOverseaMessage() = 0;
};

