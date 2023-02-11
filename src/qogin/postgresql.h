#ifndef POSTGRESQL_H
#define POSTGRESQL_H

#include <pqxx/pqxx>
#include <string>

class PostgreSQL {
private:
    std::string query;
    pqxx::connection* conn;
public:
    PostgreSQL(std::string);

    void create_db();

    void create_user(std::string name, std::string password, std::string email);
    void delete_user(std::string name);
    void check_user(std::string name, std::string password);
};

#endif // POSTGRESQL_H
