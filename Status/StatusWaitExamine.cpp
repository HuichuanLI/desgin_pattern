#include "StatusWaitExamine.h"

#include "StatusPassed.h"
#include "StatusFailed.h"

std::shared_ptr<Status> StatusWaitExamine::pass()
{
	// ÒÑ¹ıÉó
	return std::make_shared<StatusPassed>();
}

std::shared_ptr<Status> StatusWaitExamine::fail()
{
	return std::make_shared<StatusFailed>();
}