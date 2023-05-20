#pragma once

#include <memory>

class Status
{
public:
	virtual std::shared_ptr<Status> pass();
	virtual std::shared_ptr<Status> fail();
};

