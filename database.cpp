#include <database.h>

DataBase::DataBase() {};

DataBase::DataBase(const char* serverIP, const char* user, const char* passwd, const char*dbName) {
    connection = mysql_init(nullptr);
    mysql_real_connect(connection, serverIP, user, passwd, dbName, 0, nullptr, 0);
}

DataBase::DataBase(const DataBase& copy) {
    if (copy.connection != nullptr) {
        connection = mysql_init(nullptr);
        mysql_real_connect(connection, copy.connection->host, copy.connection->user, copy.connection->passwd, copy.connection->db, 0, nullptr, 0);
    }
}

DataBase& DataBase::operator=(const DataBase& copy) {
    if (this != &copy) {
        delete connection;
        if (copy.connection != nullptr) {
            connection = mysql_init(nullptr);
            mysql_real_connect(connection, copy.connection->host, copy.connection->user, copy.connection->passwd, copy.connection->db, 0, nullptr, 0);
        }
    }
    return *this;
}

DataBase::~DataBase() {
    mysql_close(connection);
}

void DataBase::setNewConnection(char* serverIP, char* user, char* passwd, char*dbName) {
    mysql_close(connection);
    connection = mysql_init(nullptr);
    mysql_real_connect(connection, serverIP, user, passwd, dbName, 0, nullptr, 0);
}

MYSQL_RES* DataBase::performQuery(const char *query) {
    mysql_query(connection, query);
    return mysql_use_result(connection);
}

bool DataBase::isConnectionValid() {
    if (connection != nullptr) {
        return true;
    } else {
        return false;
    }
}
