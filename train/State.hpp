#ifndef STATE_H
#define STATE_H

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <memory>
#include <valarray>
#include <set>
#include "Player.hpp"
#include "Game.hpp"
#include "Log.hpp"
#include <climits>
#include <cfloat>
#define UNLEAGLE FLT_MIN
using namespace std;

class State {
  public:
    //
    State() = delete;

  public:
    //
    explicit State(int numPlayers);
    //
    explicit State(const State &state, bool shuffle = false);
    //
    explicit State(const State *state, bool shuffle = false);
    //
    explicit State(const State &state, const std::string &action, bool search = false);
    //
    ~State();
    //
    void Command(const std::string &action, bool search = false);
    //
    std::string infoSet();
    //
    std::string infoSetdepthLimit( int turnIndex);
    //
    bool isTerminal();
    //
    std::valarray<float> payoff();
    //
    std::valarray<float> payoffMatrix(int player);
    //
    std::valarray<float> payoffMatrix3(int player, vector<int> randList);
    //
    std::vector<int> getleagle(int player, vector<int> randList);
    //
    std::unordered_map<std::string, std::valarray<float>> payoffMatrix2(int player);
    //
    std::vector<int> winners();
    //
    std::set<std::string> validActions();
    //
    std::vector<std::string> validActionsV();
    //
    Player *getTurnPlayer();
    //
    Player *getLastPlayer();
    //
    Game *getEngine();
    //
    int getTurnIndex();
    //
    int getLastIndex();
    //
    int getNextIndex();
    //
    int getRound();

  public:
    //
    static bool initDefault();
    //
    std::unordered_map<std::string, double> initialRegret();
    //
    std::unordered_map<std::string, double> rawStrategy();
    //
    std::unordered_map<std::string, double> returnsum(std::vector<float> weight);

  private:
    //
    int doTurnProcess(const std::string &action, bool search);
    //
    int doTurnSchedule();
    //
    int doGameSchedule();

  public:
    //
    std::vector<std::vector<std::string>> mHistory;
    //
    int mNumPlayers;
    //
    int mRound;
    //
    int cardpower;
    //
    int callid;
    //
    int pair;
    //
    Game *mEngine;

  public:
    // Number of seats in the game
    int numSeats;
    // Current game public card
    std::vector<string> boardCards;
    // Range of the current player's hand
    std::unordered_map<string, double> handRanges[6];
};

#endif
