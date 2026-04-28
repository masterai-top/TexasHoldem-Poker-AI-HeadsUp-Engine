#ifndef TRAINER_H
#define TRAINER_H

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <memory>
#include <atomic>
#include <mutex>
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
#include "Task.hpp"
#include "TaskQueue.hpp"
#include "Pluribus.hpp"

using namespace std;
//
class Trainer : public Singleton<Trainer> {
  public:
	//
	Trainer();
	//
	~Trainer();
	//
	bool start();
	//
	bool stop();
	//
	bool kill();
	//
	void train();
	//
	size_t iterations();
	//
	size_t processed();
	//
	void waitThreadsIdle();
	//
	void waitModelLoadedOver();
	//
	void waitModelSavedOver();
	//
	void submitTask(const Task &t);
	//
	void incrTaskProcessed();
	//
	void incrAgentLoadedNum();
	//
	void incrAgentSavedNum();
	//
	bool isParallelLoaded();
	//
	bool isParalleSaved();

  private:
	//
	void parallelDiscount(double factor);
	//
	void parallelStrategy();
	//
	void parallelLoad();
	//
	void parallelSave();

  private:
	//
	Pluribus *mPluribus;
	//
	std::atomic<bool> mRunning;
	//
	std::atomic<uint32_t> mNumIterations;
	//
	std::atomic<uint32_t> mNumProcessed;
	//
	std::atomic<uint32_t> mAgentLoaded;
	//
	std::atomic<uint32_t> mAgentSaved;
};

#endif // !THREADPOOL_H_
