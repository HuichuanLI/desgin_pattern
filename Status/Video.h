#pragma once

#include <memory>
#include "StatusWaitExamine.h"

class Video
{
public:
	void pass();
	void fail();

	std::shared_ptr<Status> status = std::make_shared<StatusWaitExamine>();
};

