//
// Created by lhc456 on 2023/5/21.
//
#include "DBConfig.h"

#include <fstream>
#include <iostream>
#include <thread>

DBConfig *DBConfig::config = new DBConfig();

DBConfig *DBConfig::getInstance() {
    /*
    if (config == nullptr) {
        config = new DBConfig();
    }
    */
    return config;
}

DBConfig::DBConfig() {
    // Read Config
    std::fstream fs("D://Config/config.txt");
    char tempStr[1024];
    int index = 0;
    while (fs.getline(tempStr, 1024)) {
        if (index == 0) {
            conn = tempStr;
        } else if (index == 1) {
            username = tempStr;
        } else if (index == 2) {
            password = tempStr;
        }
        index++;
    }

    printf("Read config from file\n");
}

std::string DBConfig::getConn() {
    return conn;
}

std::string DBConfig::getUsername() {
    return username;
}

std::string DBConfig::getPassword() {
    return password;
}