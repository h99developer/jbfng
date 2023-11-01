#include <iostream>
#include <string>
#include <pqxx/pqxx>

using namespace std;

namespace basepsql
{
    class Postgres
    {
        
        public:
            class User
            {
                public:
                    string Login;

                bool registration(string Password, string IP);
                bool login(string Password);
                bool addKills(int kills);
                
            };
    };
}


