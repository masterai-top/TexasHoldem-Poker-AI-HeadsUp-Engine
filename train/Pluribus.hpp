#ifndef PLURIBUS_H
#define PLURIBUS_H

#include <string>
#include <unordered_map>
#include <algorithm>
#include <random>
#include <memory>
#include <ctime>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
#include <mutex>
#include <shared_mutex>
#include <thread>
#include <filesystem>
#include <csignal>
#include <boost/serialization/serialization.hpp>
#include <boost/serialization/unordered_map.hpp>
#include <boost/serialization/unordered_set.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/set.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <sys/time.h>
#include "InfoNode.hpp"
#include "State.hpp"
#include "Agent.hpp"
#include "Hash.hpp"
#include "Log.hpp"
#include "Evaluate.hpp"

#define AGENT_MAX_NUM 1024
#define GAME_STAGE_NUM 4

using namespace std;

class Pluribus {
  public:
    //
    friend class boost::serialization::access;
    //
    Pluribus();
    //
    ~Pluribus();
    //
    void print(bool isPrint = false);
    //
    void load(bool isResearch = false);
    //
    void save(bool isResearch = false);
    //
    void train(int iterations);
    //
    void trainConsume(int i);
    //
    void searchConsume(int i);
    //
    void resetEng();
    //
    void terminal();
    //
    void sample(State &state, int blueprint = -1);
    //
    std::unordered_map<std::string, std::valarray<float>> samplePayoff(State &state, int player);
    //
    std::valarray<float> samplePayoff2(State &state, int player);
    //
    std::valarray<float> samplePayoff3(State &state, int player);
    //
    std::vector<std::size_t> searchBoardCards(State &state);
    //
    std::valarray<float> mccfr1(State &state, int player, int iter, bool prune = false, int depth = 0);
    //
    std::valarray<float> mccfr2(State &state, int player, int iter, bool prune = false, int depth = 0);
    //
    std::valarray<float> mccfr3(State &state, int player, int iter, bool prune = false, int depth = 0);
    //
    std::valarray<float> mccfr4(State &state, int player, int iter, bool prune = false, int depth = 0);
    //
    std::valarray<float> mccfr5(State &state, int iter, int depth);
    //
    std::unordered_map<std::string, std::valarray<float>> mccfr6(State &state, int player, int iter, bool prune, int depth);
    //
    std::unordered_map<std::string, std::valarray<float>> mccfr7(State &state, int player, int iter, bool prune, int depth);
    //
    std::valarray<float> mccfr8(State &state, int player, int iter, bool prune, int depth, std::unordered_set<std::string> &dict);
    //
    std::valarray<float> mccfr9(State &state, int player, int iter, bool prune, int depth, std::unordered_set<std::string> &dict);
    //
    std::string getDateTime(bool onlynum = true, time_t timestamp = time(NULL));
    //
    std::string getMSDateTime();
    //
    void redis();
    //
    void convert();

  public:
    //
    void agentView();
    //
    void agentDiscount(double factor);
    //
    void agentStrategy();
    //
    Agent *getAgent(const int stage, const std::string &infoSet);
    //
    void setAgent(const int stage, const std::string &infoSet, InfoNode *nodePtr);
    //
    InfoNode *getAgentNode(const int stage, const std::string &infoSet, const std::set<string> &validActions);
    //
    InfoNode *getAgentNode(const std::string &infoSet, const std::set<string> &validActions);
    //
    InfoNode *findAgentNode(const int stage, const std::string &infoSet);
    //
    InfoNode *findAgentNode(const std::string &infoSet);
    //
    Agent *getAgentPointer(int index);
    //
    size_t getAgentSize();
    //
    size_t getAgentNodeSize();
    //
    void printAgentNodeSize();

  public:
    //
    std::valarray<float> payout(State &state, int player, std::vector<int> bias, int depth = 0);
    //
    std::valarray<float> payout2(State &state, int player, vector<int> bias, vector<int> randlist);
    //
    std::valarray<float > rollout(State &state, int player, std::vector<int> bias);
    //
    std::unordered_map<std::string, double> biasStrategy(int blueprint, std::unordered_map<std::string, double> strategySum);
    //
    std::valarray<float> subgameSolve(State &state, int player, int iter, bool prune);
    //
    void trainChoseBlueprint(State &state, int player);
    //
    std::valarray<float> subgameSolve2(State &state, int player, int iter, bool prune);
    //
    void trainChoseBlueprint2(State &state, int player);
    //
    std::valarray<float> subgameSolve3(State &state, int player, int iter, bool prune, int depth);
    //
    void trainChoseBlueprint3(State &state, int player, int depth);
    //
    std::valarray<float> subgameSolve4(State &state, int player, int iter, bool prune, int depth);
    //
    std::valarray<float> lcfr(State &state, int player, int iter, int depth, std::vector<float> &reachProbs);
    //
    std::map<std::size_t, std::vector<std::string>> getClusPairs(std::vector<std::size_t> &boardCards);

  public:
    //
    static bool isRunning;
    //
    Game *mEngine = NULL;
    //
    int mNumPlayers = 6;
    //
    int mRegretMinimum = -3000000;
    //
    int mStrategyInterval = 50;
    //
    int mPruneThreshold = 100000;
    //
    int mDiscountInterval = 500;
    //
    int mLCFRThreshold = 100000;
    //
    int mSerializeInterval = 10000;
    //
    int mMaxIterations = 1000000;
    //
    int mMumRound = 2;
    //
    int mMumRaises = 15;
    //
    int randseed = 0;
    //
    std::random_device mRd;
    //
    std::mt19937 mActionEng;
    //
    State *mGameState;

  private:
    //
    Agent *mAgentBuckets[AGENT_MAX_NUM * GAME_STAGE_NUM];
};

#endif
