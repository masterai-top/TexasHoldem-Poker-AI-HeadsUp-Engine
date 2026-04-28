#ifndef TASK_QUEUE_HPP
#define TASK_QUEUE_HPP

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <memory>
#include <atomic>
#include <mutex>
#include <shared_mutex>
#include <algorithm>
#include <condition_variable>
#include <functional>
#include <unordered_map>
#include <thread>
#include <future>
#include <boost/serialization/serialization.hpp>
#include <boost/serialization/unordered_map.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/set.hpp>
#include "Single.hpp"

using namespace std;

class Task;
class TaskQueue {
  public:
    //
    TaskQueue();
    //
    ~TaskQueue();
    //
    void Push(const Task &t);
    //
    void Push2(const std::vector<Task> &v);
    //
    bool Get(Task &t);
    //
    bool Empty();
    //
    void Clean();
    //
    size_t TaskNum();

  private:
    //
#ifdef __APPLE__
    //
    static std::shared_mutex qMutex;
    //
    static std::queue<Task> qTask;
#else
    //
    mutable std::shared_mutex qMutex;
    //
    std::queue<Task> qTask;
#endif
};

#endif


