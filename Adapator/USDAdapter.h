#pragma once

#include "Profit.h"
#include "USDProfit.h"

class USDAdapter : public Profit
{
private:
	USDProfit usdProfit;
public:
	float getProfit();
};

