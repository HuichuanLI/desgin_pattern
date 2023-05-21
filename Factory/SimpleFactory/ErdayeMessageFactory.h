#pragma once

#include "MessageFactory.h"

class ErdayeMessageFactory : public MessageFactory
{
public:
	virtual Message* createMessage() override;
	virtual OverseaMessage* createOverseaMessage() override;
};

