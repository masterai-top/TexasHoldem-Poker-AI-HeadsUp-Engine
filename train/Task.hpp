#ifndef THREAD_TASK_H
#define THREAD_TASK_H

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
#include "Log.hpp"
//
class Agent;
class Pluribus;
class Processor;
class Trainer;
//
typedef enum enTaskType {
	TASK_TYPE_NONE = 0,
	TASK_TYPE_TRAIN,
	TASK_TYPE_DISCOUNT,
	TASK_TYPE_STRATEGY,
	TASK_TYPE_RESEARCH,
	TASK_TYPE_LOAD_MODEL,
	TASK_TYPE_SAVE_MODEL,
	TASK_TYPE_MAX_NUM
} TaskType;
//
class Task {
  public:
	//
	Task();
	//
	~Task();
	//
	void Init();
	//
	void Process();

  private:
	//
	void train();
	//
	void discount();
	//
	void strategy();
	//
	void research();
	//
	void modelLoad();
	//
	void modelSave();

  public:
	//
	TaskType mType;
	//
	int32_t mTaskId;
	//
	double mFactor;
	//
	Agent *mAgent;
	//
	Pluribus *mPluribus;
	//
	Processor* mProcessor;
	//
	Trainer* mTrainer;
	//
	std::string mSuffix;
};

#endif