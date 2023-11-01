#include <iostream>
#include <string>
#include <pqxx/pqxx>
#include "database.h"

using namespace std;

string Host;
string Port;
string User;
string Password;
string Dbname;

string getConn() {
    string dbconn;
    dbconn = "host=" + Host + " port=" + Port + " user=" + User + " password=" + Password + " dbname=" + Dbname;
    return dbconn;
}

bool basepsql::Postgres::User::registration(string Password, string IP) {
    pqxx::connection conn(getConn());

    if (conn.is_open()) {
        pqxx::work txn(conn);

        string Query = "SELECT * FROM accounts WHERE login = " + txn.quote(this->Login);
        pqxx::result Result = txn.exec(Query);

        if (Result.empty()) {
            string InsertQuery = "INSERT INTO accounts (login, password, last_ip) VALUES (" + txn.quote(this->Login) + ", " + txn.quote(Password) + ", " + txn.quote(IP) + ")";
            string InsertStat = "INSERT INTO statistics (login, kills) VALUES (" + txn.quote(this->Login) + ", 0)";
            txn.exec(InsertQuery);
            txn.exec(InsertStat);
            txn.commit();
            return true;
        }
        else {
            return false;
        }
    } else {
        cout << "[PSQL]: Failed to connect to database!";
        return false;
    }
}

bool basepsql::Postgres::User::login(string Password) {
    pqxx::connection conn(getConn());

    if (conn.is_open()) {
        pqxx::work txn(conn);

        string Query = "SELECT login FROM accounts WHERE login = " + txn.quote(this->Login) + "AND password = " + txn.quote(Password);
        pqxx::result Result = txn.exec(Query);

        if (Result.empty()) {
            return false;
        } else {
            return true;
        }
    } else {
        cout << "[PSQL]: Failed to connect to database!";
        return false;
    }
}

bool basepsql::Postgres::User::addKills(int kills) {
    pqxx::connection conn(getConn());

    if (conn.is_open())
    {
        pqxx::work txn(conn);
        string UpdateQuery = "UPDATE statistics SET kills = kills + " + txn.quote(kills) + " WHERE login = " + txn.quote(this->Login);
        txn.exec(UpdateQuery);
        txn.commit();
        return true;
    }
    else
    {
        cout << "[PSQL]: Failed to connect to database!";
        return false;
    }
}
