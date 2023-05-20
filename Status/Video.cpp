#include "Video.h"

void Video::pass()
{
	std::shared_ptr<Status> s = status->pass();
	if (s != nullptr) {
		status = s;
	}
}

void Video::fail()
{
	std::shared_ptr<Status> s = status->fail();
	if (s != nullptr) {
		status = s;
	}
}