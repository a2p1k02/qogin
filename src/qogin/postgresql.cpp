#include "postgresql.h"
#include <iostream>

PostgreSQL::PostgreSQL(std::string dbname)
{
    conn = new pqxx::connection("dbname = " + dbname + " hostaddr = 127.0.0.1 port = 5432");
}

void PostgreSQL::create_db()
{
    pqxx::work work(*conn);
    query = "create table users ("
            "id BIGSERIAL NOT NULL PRIMARY KEY, "
            "name VARCHAR(50) NOT NULL, "
            "password VARCHAR(100) NOT NULL, "
            "email VARCHAR(150)"
            ");";
    work.exec(query);
    work.commit();
}

bool PostgreSQL::check_user(std::string name, std::string password)
{
    pqxx::nontransaction n(*conn);
    query = "select exists(select 1 from users where name='" + name + "' and password = '" + password + "');";
    pqxx::result r(n.exec(query));
    for (const auto& x : r)
        if (x[0].as<std::string>() == "t")
            return true;
    return false;
}

void PostgreSQL::create_user(std::string name, std::string password, std::string email)
{
    pqxx::work work(*conn);
    query = "insert into users (name, password, email) VALUES ('" + name + "', '" + password + "', '" + email + "')";
    work.exec(query);
    work.commit();
}

void PostgreSQL::delete_user(std::string name)
{

}
