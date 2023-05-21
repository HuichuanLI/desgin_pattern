#include <iostream>

#include "XiaojiuziMessage.h"
#include "DayiziMessage.h"

#include "SimpleMessageFactory.h"

#include "MessageFactory.h"
#include "XiaojiuziMessageFactory.h"
#include "DayiziMessageFactory.h"

int main() {
    MessageFactory *mf = new DayiziMessageFactory();

    Message *message = mf->createMessage();
    message->sendMessage("12633333333", "短信来喽！！！");

    OverseaMessage *overseaMessage = mf->createOverseaMessage();

    delete message;
    delete mf;
    return 0;
}