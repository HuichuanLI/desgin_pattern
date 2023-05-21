#pragma once

#include "MessageFactory.h"

class DayiziMessageFactory : public MessageFactory
{
public:
	virtual Message* createMessage() override;
	virtual OverseaMessage* createOverseaMessage() override;
};

