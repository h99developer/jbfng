#ifndef FNGSTORAGE_H
#define FNGSTORAGE_H

#include <vector>
#include "../src/game/server/player.h"
#include "../src/engine/server/server.h"

class FNGStorage {
public:
  void addPlayer(CPlayer* player);
  CPlayer* getPlayerByClientID(int clientID);
  std::vector<CPlayer*> getAllPlayers();

private:
  std::vector<CPlayer*> players;
  
};

#endif