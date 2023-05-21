#pragma once

#include "MessageFactory.h"

class XiaojiuziMessageFactory : public MessageFactory
{
public:
	virtual Message* createMessage() override;
	virtual OverseaMessage* createOverseaMessage() override;
};

