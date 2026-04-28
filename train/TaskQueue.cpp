#include "TaskQueue.hpp"
#include "Task.hpp"

//
#ifdef __APPLE__
std::shared_mutex TaskQueue::qMutex = std::shared_mutex();
std::queue<Task> TaskQueue::qTask = std::queue<Task>();
#endif

TaskQueue::TaskQueue() {

}

TaskQueue::~TaskQueue() {

}

void TaskQueue::Push(const Task &t) {
    if (true) {
        std::unique_lock<std::shared_mutex> lock(qMutex);
        qTask.push(t);
    }
}

void TaskQueue::Push2(const std::vector<Task> &v) {
    if (true) {
        std::unique_lock<std::shared_mutex> lock(qMutex);
        for (auto iter = v.begin(); iter != v.end(); iter++) {
            qTask.push(*iter);
        }
    }
}

bool TaskQueue::Get(Task &t) {
    bool isSucc = false;
    //
    if (true) {
        std::unique_lock<std::shared_mutex> lock(qMutex);
        if (qTask.size() > 0) {
            t = qTask.front();
            qTask.pop();
            isSucc = true;
        }
    }
    //
    return isSucc;
}

bool TaskQueue::Empty() {
    bool isEmpty = false;
    //
    if (true) {
        std::shared_lock<std::shared_mutex> lock(qMutex);
        isEmpty = qTask.empty();
    }
    //
    return isEmpty;
}

void TaskQueue::Clean() {
    if (true) {
        std::unique_lock<std::shared_mutex> lock(qMutex);
        std::queue<Task> empty;
        swap(empty, qTask);
    }
}

size_t TaskQueue::TaskNum() {
    std::size_t numTask = 0;
    //
    if (true) {
        std::shared_lock<std::shared_mutex> lock(qMutex);
        numTask = qTask.size();
    }
    //
    return numTask;
}
