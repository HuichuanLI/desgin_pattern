#pragma once

#include "Status.h"

class StatusWaitExamine : public Status
{
public:
	virtual std::shared_ptr<Status> pass() override;
	virtual std::shared_ptr<Status> fail() override;
};

