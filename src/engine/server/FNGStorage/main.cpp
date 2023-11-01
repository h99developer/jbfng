#include "fngstorage.h"
#include <string>
#include <vector>
#include <iostream>

int main()
{
    FNGStorage storage;
    FNGPlayer player1;
    player1.ClientID = 0;
    player1.ClientName = "Lil Tee";
    player1.isAuth = true;

    FNGPlayer player2;
    player2.ClientID = 1;
    player2.ClientName = "ninekeem";
    player2.isAuth = false;

    FNGPlayer player3;
    player3.ClientID = 2;
    player3.ClientName = "Zavo";
    player3.isAuth = true;

    storage.addPlayer(player1);
    storage.addPlayer(player2);
    storage.addPlayer(player3);

    for (auto& player : storage.getAllPlayers())
    {
        std::cout << player.ClientID << std::endl;
    }
    
}