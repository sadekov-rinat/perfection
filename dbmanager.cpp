#include <boost/algorithm/string/replace.hpp>
#include <iostream>
#include "dbmanager.h"

using namespace pqxx;
using namespace std;
using namespace boost;

/**
@brief              Class for data base connection and set/get sql request
@param[in] dbname   Name of database
@param[in] user     Name of users
@param[in] password Password for database
@retval             void
*/
dbmanager::dbmanager(string dbname, string user, string password)
{
    // create sting template for database connection
    string settings = "dbname = %1% user = %2% password = %3% hostaddr = 127.0.0.1 port = 5432";
    replace_all(settings, "%1%", dbname);
    replace_all(settings, "%2%", user);
    replace_all(settings, "%3%", password);

    try {
       //db connection
       C = new connection(settings);
       if (C->is_open()) {
          db_connect = true;
          cout << "Opened database successfully: " << C->dbname() << endl;
       } else {
          cout << "Can't open database" << endl;
       }
    }
    catch (const std::exception &e) {
       //exception if connection doesn't good
       cerr << e.what() << std::endl;
    }
}
/**
@brief              Destructor function
@retval             void
*/
dbmanager::~dbmanager() {
    C->disconnect();
}


/**
@brief              (experiment) function for creating table
@retval             void
*/
void dbmanager::createTable() {
    //create simple sql request
    string sql;
    sql = "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "
          "VALUES (1, 'Paul', 32, 'California', 20000.00 ); "
          "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "
          "VALUES (2, 'Allen', 25, 'Texas', 15000.00 ); "
          "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)"
          "VALUES (3, 'Teddy', 23, 'Norway', 20000.00 );"
          "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)"
          "VALUES (4, 'Mark', 25, 'Rich-Mond ', 65000.00 );";

    // Create a transactional object.
    work W(*C);
    // Execute SQL query
    W.exec( sql );
    W.commit();
    cout << "Table created successfully" << endl;
}


/**
@brief             Special unique database command for user autorization
@param[in] login   User login for checking
@param[in] pass    User password for checking
@retval            String session hash sum
*/
string dbmanager::autorization(string login, string pass) {
    // Create SQL statement
    string sql = "SELECT autorization('{1}','{2}')";
    replace_all(sql, "{1}", login);
    replace_all(sql, "{2}", pass);
    // Create a non-transactional object
    nontransaction N(*C);
    // Execute SQL query
    result R(N.exec( sql ));

    result::const_iterator c = R.begin();
    cout << c[0].as<string>();
    return c[0].as<string>();
}

/*
for (result::const_iterator c = R.begin(); c != R.end(); ++c) {
    cout << "Hash = " << c[0].as<string>() << endl;
}
*/
