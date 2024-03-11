#ifndef DATABASE_H
#define DATABASE_H

#include <mysql.h>

class DataBase {
public:
    DataBase();

    DataBase(const char* serverIP, const char* user, const char* passwd, const char*dbName);

    DataBase(const DataBase& copy);

    DataBase& operator=(const DataBase& copy);

    ~DataBase();

    void setNewConnection(char* serverIP, char* user, char* passwd, char*dbName);

    MYSQL_RES* performQuery(const char *query);

    bool isConnectionValid();

private:
    MYSQL *connection = nullptr;
};
#endif // DATABASE_H
