//
// Created by lhc456 on 2023/5/21.
//

#include <string>

class DBConfig {
public:
    static DBConfig *config;

    static DBConfig *getInstance();

    DBConfig();

    std::string getConn();

    std::string getUsername();

    std::string getPassword();

private:
    std::string conn;
    std::string username;
    std::string password;
};
