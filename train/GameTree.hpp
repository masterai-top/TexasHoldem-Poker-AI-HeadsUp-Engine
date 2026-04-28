#ifndef GAME_TREE_HPP
#define GAME_TREE_HPP

#include <iostream>
#include <stack>
#include <set>
#include <vector>
#include <memory>
#include "Log.hpp"
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

using namespace std;

//
class GameNode {
  public:
    //
    GameNode();
    //
    ~GameNode();
    //
    std::vector<std::shared_ptr<GameNode>> getChildren();

  public:
    //
    std::string infoset;
    //
    std::shared_ptr<GameNode> parent;
    //
    std::vector<std::shared_ptr<GameNode>> children;
};

class GameTree {
  public:
    //
    GameTree(int depth, const std::set<std::string> &actions);
    //
    ~GameTree();
    //
    std::shared_ptr<GameNode> RecursiveCreateTree(int depth, std::shared_ptr<GameNode> parent, std::vector<std::string> &his);
    //
    int NumOfTreeNode();
    //
    int BuildTree();
    //
    std::string HistoryToStr(const std::vector<std::string> &his);
    //
    std::shared_ptr<GameNode> getGameTreeNode(const std::string &infoset);

  private:
    //
    int mDepth;
    //
    std::set<std::string> mActions;
    //
    std::vector<std::string> mHistory;
    //
    std::unordered_map<std::string, std::shared_ptr<GameNode>> mNodes;
};

#endif