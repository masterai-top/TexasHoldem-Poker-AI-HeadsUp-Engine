#ifndef RESEARCH_TASK_EXEUTOR_H
#define RESEARCH_TASK_EXEUTOR_H

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <memory>
#include <atomic>
#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <cstddef>
#include <cstring>
#include <cmath>
#include <mutex>
#include <algorithm>
#include <condition_variable>
#include <functional>
#include <unordered_map>
#include <thread>
#include <future>
#include <random>
#include <boost/serialization/serialization.hpp>
#include <boost/serialization/unordered_map.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/set.hpp>
#include "Single.hpp"
#include "Processor.hpp"
#include "State.hpp"

using namespace std;

//
class TaskExecutor : public Singleton<TaskExecutor> {
  public:
	//
	TaskExecutor(const TaskExecutor &obj) = delete;
	//
	TaskExecutor();
	//
	~TaskExecutor();
	//
	bool init();
	//
	bool final();
	//
	bool kill();
	//
	void wait();
	//
	void consume();
	//
	void submit(const Task& task);
	//
	void submit2(const std::vector<Task> &v);

  private:
	//
	std::atomic<bool> consumeRunning;
	//
	std::unordered_map<std::thread::id, std::thread *> consumers;
	//
	mutable std::mutex mtxConsumers;
	//
	std::atomic<std::size_t> numTaskThread;

  private:
	//
	TaskQueue taskQueue;
};

#endif // !RESEARCH_TASK_EXEUTOR_H
