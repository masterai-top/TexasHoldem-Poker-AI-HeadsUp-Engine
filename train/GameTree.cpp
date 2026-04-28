#include "GameTree.hpp"

GameNode::GameNode() {
    infoset = "";
    parent = nullptr;
    children.clear();
}

GameNode::~GameNode() {

}

std::vector<std::shared_ptr<GameNode>> GameNode::getChildren() {
    return children;
}

GameTree::GameTree(int depth, const std::set<std::string> &actions) {
    mDepth = depth;
    mActions = actions;
    mNodes.clear();
}

GameTree::~GameTree() {

}

std::shared_ptr<GameNode> GameTree::RecursiveCreateTree(int depth, std::shared_ptr<GameNode> parent, std::vector<std::string> &his) {
    if (depth == mDepth)
        return nullptr;
    //
    auto node = make_shared<GameNode>();
    node->infoset = HistoryToStr(his);
    node->parent = parent;
    mNodes.emplace(node->infoset, node);
    TEST_I("GameNode: infoset=" << node->infoset);
    //
    for (auto action : mActions) {
        if (action == "F")
            continue;
        //
        if (true) {
            auto his2 = his;
            auto curr = depth % 2;
            his2.push_back(std::to_string(curr) + action);
            auto child = RecursiveCreateTree(depth + 1, node, his2);
            if (child != nullptr) {
                node->children.push_back(child);
            }
        }
    }
    //
    return node;
}

int GameTree::NumOfTreeNode() {
    return mNodes.size();
}

std::string GameTree::HistoryToStr(const std::vector<std::string> &his) {
    std::ostringstream os;
    for (auto action : his) {
        os << "|" << action;
    }
    return os.str();
}

std::shared_ptr<GameNode> GameTree::getGameTreeNode(const std::string &infoset) {
    auto found = mNodes.find(infoset);
    if (found == mNodes.end())
        return nullptr;
    //
    return found->second;
}

int GameTree::BuildTree() {
    std::vector<std::string> his;
    auto root = RecursiveCreateTree(0, nullptr, his);
    auto num = NumOfTreeNode();
    TEST_I("这棵树一共有" << num << "个节点。");
    return 0;
}


