#ifndef __INFO_SET_H_
#define __INFO_SET_H_

#include <cstddef>
#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <memory>
#include <ctime>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <mutex>
#include <shared_mutex>
#include <thread>
#include <filesystem>
#include <csignal>
#include <filesystem>
#include <algorithm>
#include <random>
#include <memory>
#include <boost/serialization/serialization.hpp>
#include <boost/serialization/unordered_map.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/set.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include "Single.hpp"
#include "InfoNode.hpp"
#include "RedisMgr.hpp"

using namespace std;

class Agent {
  public:
    //
    Agent() = delete;
    //
    Agent(const Agent &) = delete;
    //
    explicit Agent(std::string name);
    //
    virtual ~Agent();
    //
    int Init();
    //
    int Final();
    //
    int Load();
    //
    int Save(std::string suffix = "");
    //
    int Stat();
    //
    void View();
    //
    void Discount(double factor);
    //
    void UpdateStrategy();
    //
    InfoNode *GetNode(const std::string &infoSet, const std::set<std::string> &validAactions);
    //
    InfoNode *GetNode2(const std::string &infoSet);
    //
    InfoNode *SetNode(const std::string &infoSet, InfoNode *ptr);
    //
    void UploadToRedis(RedisMgr &mgr);
    //
    std::unordered_map<std::string, InfoNode *> &GetNodes();
    //
    std::string getFilename();
    //
    bool isLoaded();
    //
    std::size_t nodeNum();

  private:
    //
    std::string filename;
    //
    std::unordered_map<std::string, InfoNode *> mapNode;
    //
    bool isLoad;

  public:
    //
    mutable std::shared_mutex mtxNode;
};

#endif

