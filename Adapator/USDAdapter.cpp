#include "USDAdapter.h"

float USDAdapter::getProfit()
{
	float profit = usdProfit.getUSDProfit("abc", "bcd");
	return profit * 7.0;
}