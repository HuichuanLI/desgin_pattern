#pragma once

#include "Message.h"

class MessageFactory
{
public:
	virtual Message* createMessage() = 0;
};

