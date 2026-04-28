#ifndef INFO_NODE_H
#define INFO_NODE_H

#include <valarray>
#include <unordered_map>
#include <string>
#include <vector>
#include <boost/serialization/serialization.hpp>
#include <boost/serialization/unordered_map.hpp>
#include <boost/serialization/string.hpp>
#include <set>
#include <mutex>
#include <shared_mutex>
#include <algorithm>
#include <random>
#include <memory>

using namespace std;

class InfoNode {
  public:
    //
    friend class boost::serialization::access;
    //
    InfoNode();
    //
    InfoNode(const std::set<std::string> validActions);
    //
    ~InfoNode();
    //
    std::unordered_map<std::string, double> getAverageStrategy();
    //
    std::unordered_map<std::string, double> getStrategy(const std::set<std::string> validActions);
    //
    std::unordered_map<std::string, double> getStrategy();
    //
    std::unordered_map<std::string, double> getRegretSum();
    //
    std::unordered_map<std::string, double> getStrategySum();
    //
    std::set<std::string> getValidActions();
    //
    int incRegretNumber();
    //
    int getRegretNumber();
    //
    int incStrategyNumber();
    //
    int getStrategyNumber();
    //
    std::string getInfoSet();
    //
    int setInfoSet(std::string key);
    //
    int discount(double factor);
    //
    int updateStrategy();
    //
    int incRegretSum(const std::unordered_map<std::string, double> &temp);
    //
    int incRegretSum2(const std::unordered_map<std::string, double> &temp);

  public:
    //
    std::unordered_map<std::string, double> regretSum;
    //
    std::unordered_map<std::string, double> strategySum;

  private:
    //
    mutable std::shared_mutex regretMutex;
    //
    mutable std::shared_mutex strategyMutex;

  public:
    //
    template<class Archive>
    void serialize(Archive &ar, const unsigned int version) {
        ar &regretSum;
        ar &strategySum;
        ar &regretNumber;
        ar &strategyNumber;
        ar &mValidActions;
    };

  private:
    //
    std::unordered_map<std::string, double> strategy;
    //
    std::set<std::string> mValidActions;
    //
    int regretNumber;
    //
    int strategyNumber;
    //
    std::string infoSet;
};

//
typedef InfoNode *InfoNodePtr;

#endif
