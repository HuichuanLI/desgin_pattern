//
// Created by lhc456 on 2023/5/21.
//
#include <iostream>

class SqlQuery {
public:
    SqlQuery(const std::string &conn, const std::string &username, const std::string &password) {
        m_conn = conn;
        m_username = username;
        m_password = password;
    }

    int query() {
        // 假装这里有实现。
        return 0;
    }

    std::string m_conn;
    std::string m_username;
    std::string m_password;
};

#include <fstream>
#include <iostream>

int main() {
    for (int i = 0; i < 100; i++) {
        std::string conn = "mysql://localhost:3306/db/";
        std::string username = "user";
        std::string password = "password";

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

        printf("conn: %s\n", conn.c_str());
        printf("username: %s\n", username.c_str());
        printf("password: %s\n", password.c_str());

        SqlQuery query(conn, username, password);

        // 查询操作
        query.query();
    }

    std::cout << "C3_1\n";
}
