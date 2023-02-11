#include "postgresql.h"

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
