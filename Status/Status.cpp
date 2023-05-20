#include "Status.h"

std::shared_ptr<Status> Status::pass()
{
	printf("当前操作不被支持\n");

	return nullptr;
}

std::shared_ptr<Status> Status::fail()
{
	printf("当前操作不被支持\n");

	return nullptr;
}