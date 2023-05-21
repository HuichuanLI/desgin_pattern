
#include <iostream>

#include "Profit.h"
#include "USDProfit.h"
#include "USDAdapter.h"

int main()
{
    Profit profit;
    float profitNum = profit.getProfit();

    USDProfit usdProfit;
    float usdProfitNum = usdProfit.getUSDProfit("abc", "bcd");

    usdProfitNum = usdProfitNum * 7.0;

    USDAdapter adapter;
    float adapterNum = adapter.getProfit();


    Profit* adapterProfit = new USDAdapter();
    float adapterProfitNum = adapterProfit->getProfit();
    printf("adapterProfitNum: %f\n", adapterProfitNum);
    delete adapterProfit;

    return 0;
}