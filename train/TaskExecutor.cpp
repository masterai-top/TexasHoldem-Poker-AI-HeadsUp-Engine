#include "TaskExecutor.hpp"
#include "Configure.hpp"

TaskExecutor::TaskExecutor::TaskExecutor() {

}

TaskExecutor::~TaskExecutor() {

}

bool TaskExecutor::init() {
	int threadNum = 1;
	if (Configure::GetInstance().mResearchMultiThreading) {
		threadNum = std::thread::hardware_concurrency();
	}
	//
	consumeRunning = true;
	taskQueue.Clean();
	//
	if (true) {
		std::unique_lock<std::mutex> lock(mtxConsumers);
		for (int i = 0; i < threadNum; i++) {
			auto consumer = new std::thread(std::bind(&TaskExecutor::consume, this));
			consumer->detach();
			consumers.insert({consumer->get_id(), consumer});
			numTaskThread++;
		}
	}
	//
	return true;
}

bool TaskExecutor::final() {
	while (true) {
		if (taskQueue.Empty())
			break;
		//
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
	//
	kill();
	//
	wait();
	//
	if (true) {
		std::unique_lock<std::mutex> lock(mtxConsumers);
		for (auto iter = consumers.begin(); iter != consumers.end(); iter++) {
			delete (*iter).second;
		}
		//
		consumers.clear();
	}
	//
	return true;
}

bool TaskExecutor::kill() {
	consumeRunning = false;
	return true;
}

void TaskExecutor::wait() {
	while (numTaskThread > 0) {
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
}


void TaskExecutor::consume() {
	TEST_I("consume begined");
	//
	while (consumeRunning) {
		if (true) {
			Task task;
			if (taskQueue.Get(task)) {
				task.Process();
			} else {
				std::this_thread::sleep_for(std::chrono::milliseconds(1));
			}
		}
	}
	//
	TEST_I("consume exited");
	numTaskThread--;
}

void TaskExecutor::submit(const Task &task) {
	taskQueue.Push(task);
}

void TaskExecutor::submit2(const std::vector<Task> &v) {
	taskQueue.Push2(v);
}

