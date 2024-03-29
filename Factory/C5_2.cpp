﻿#include <iostream>

#include "XiaojiuziMessage.h"
#include "DayiziMessage.h"

#include "SimpleMessageFactory.h"

#include "MessageFactory.h"
#include "XiaojiuziMessageFactory.h"
#include "DayiziMessageFactory.h"

int main() {
    SimpleMessageFactory *mf = new SimpleMessageFactory();
    mf->createMessage(MessageType::Dayizi)->sendMessage("12633333333", "短信来喽！！！");


    MessageFactory *mf1 = new XiaojiuziMessageFactory();
    Message *message = mf1->createMessage();
    message->sendMessage("12633333333", "短信来喽！！！");
    delete mf;
    return 0;
}