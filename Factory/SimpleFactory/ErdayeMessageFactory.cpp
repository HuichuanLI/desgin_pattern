#include "ErdayeMessageFactory.h"

#include "ErdayeMessage.h"
#include "ErdayeOverseaMessage.h"

Message* ErdayeMessageFactory::createMessage()
{
	return new ErdayeMessage();
}

OverseaMessage* ErdayeMessageFactory::createOverseaMessage()
{
	return new ErdayeOverseaMessage();
}