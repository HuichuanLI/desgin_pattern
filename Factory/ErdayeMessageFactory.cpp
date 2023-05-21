#include "ErdayeMessageFactory.h"

#include "ErdayeMessage.h"

Message* ErdayeMessageFactory::createMessage()
{
	return new ErdayeMessage();
}