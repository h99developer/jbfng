#include <vector>
#include <string>
#include <iostream>
#include "../src/game/server/player.h"
#include "../src/engine/server/server.h"

class FNGStorage {
public:
  // CPLAYER // CPLAYER // CPLAYER // CPLAYER // CPLAYER //
  void addPlayer(CPlayer* player);
  CPlayer* getPlayerByClientID(int clientID);
  std::vector<CPlayer*> getAllPlayers();
  // CPLAYER // CPLAYER // CPLAYER // CPLAYER // CPLAYER //

private:


  std::vector<CPlayer*> players; // CPlayer
  std::vector<CPlayer*> characters; // CCharacter
};


// CPLAYER // CPLAYER // CPLAYER // CPLAYER // CPLAYER //

std::vector<CPlayer*> FNGStorage::getAllPlayers() {
  return players;
}

void FNGStorage::addPlayer(CPlayer* player) {
  players.push_back(player);
}

CPlayer* FNGStorage::getPlayerByClientID(int clientID) {
  for (const auto& player : players) {
    if (player->GetCID() == clientID) {
        return player;
    }
  }
  // Return nullptr if player is not found
  return nullptr;
}

// CPLAYER // CPLAYER // CPLAYER // CPLAYER // CPLAYER //

// CSERVER // CSERVER // CSERVER // CSERVER // CSERVER //

// ...........

// CSERVER // CSERVER // CSERVER // CSERVER // CSERVER //