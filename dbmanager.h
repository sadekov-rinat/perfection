#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <pqxx/pqxx>
#include <string>


using namespace std;
using namespace pqxx;

class dbmanager
{
public:
    dbmanager(string dbname, string user, string password);
    ~dbmanager();
    string autorization(string login, string pass);
    void createTable();

private:
    bool db_connect = false;
    connection *C;
};

#endif // DBMANAGER_H
