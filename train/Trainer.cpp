#include "Trainer.hpp"
#include "GamePool.hpp"
#include "Configure.hpp"
#include "TaskExecutor.hpp"

Trainer::Trainer() {
	mPluribus = nullptr;
	mRunning = true;
	mNumIterations = 0;
	mNumProcessed = 0;
	mAgentLoaded = 0;
	mAgentSaved = 0;
}

Trainer::~Trainer() {
	if (mPluribus != nullptr) {
		delete mPluribus;
		mPluribus = nullptr;
	}
}

bool Trainer::start() {
	if (nullptr != mPluribus) {
		LOG_ERROR("start thread-pool failed");
		return false;
	}
	//
	TaskExecutor::GetInstance().init();
	//
	mNumIterations = Configure::GetInstance().mMinIterations;
	mNumProcessed  = Configure::GetInstance().mMinIterations;
	LOG_INFO("Starting point of training: mNumIterations=" << mNumIterations
	         << ", mNumProcessed=" << mNumProcessed);
	//
	if (nullptr == mPluribus) {
		mPluribus = new Pluribus();
		mPluribus->load(true);
	}
	//
	parallelLoad();
	//
	waitModelLoadedOver();
	//
	LOG_INFO("Load model complete!");
	return true;
}

bool Trainer::stop() {
	//
	TaskExecutor::GetInstance().final();
	//
	if (nullptr != mPluribus) {
		mPluribus->save();
	}
	//
	LOG_DEBUG("Trainer end");
	return true;
}

bool Trainer::kill() {
	LOG_INFO("kill threads...");
	mRunning = false;
	return true;
}

void Trainer::train() {
	LOG_INFO("produce begined");
	auto mMaxIterations = mPluribus->mMaxIterations;
	while (mRunning) {
		waitThreadsIdle();
		//
		size_t needWaitting = 0;
		size_t needTaskNum1 = 0;
		size_t needTaskNum2 = 0;
		//
		auto strategyInterval = mPluribus->mStrategyInterval;
		auto discountInterval = mPluribus->mDiscountInterval;
		auto serializeIntertval = mPluribus->mSerializeInterval;
		//
		if ((mNumIterations > 0) && (mNumProcessed > 0)) {
			auto resetPoolInterval = Configure::GetInstance().mResetPoolInterval;
			if (0 == mNumIterations % resetPoolInterval) {
				GamePool::GetInstance().status();
			}
			//
			if (0 == (mNumProcessed % strategyInterval)) {
				mPluribus->agentStrategy();
				needWaitting = 1;
				LOG_INFO("@train strategy: strategyInterval=" << strategyInterval << ", mNumProcessed=" << mNumProcessed);
			}
			//
			auto cfrThreshold = mPluribus->mLCFRThreshold;
			if ((mNumProcessed < cfrThreshold) && (0 == (mNumProcessed % discountInterval))) {
				float factor1 = (mNumProcessed / discountInterval);
				float factor2 = (mNumProcessed / discountInterval + 1.0);
				mPluribus->agentDiscount(factor1 / factor2);
				needWaitting = 1;
				LOG_INFO("@train discount: discountInterval=" << discountInterval << ", mNumProcessed=" << mNumProcessed);
			}
			//
			if (0 == (mNumProcessed % serializeIntertval)) {
				parallelSave();
				waitModelSavedOver();
				//
				LOG_INFO("@train serialize: serializeIntertval=" << serializeIntertval << ", mNumProcessed=" << mNumProcessed);
			}
		}
		//
		if (needWaitting) {
			waitThreadsIdle();
		}
		//
		if (mNumProcessed >= mMaxIterations) {
			break;
		}
		//
		int taskNum = mNumIterations - mNumProcessed;
		if (taskNum == 0) {
			taskNum = strategyInterval;
		}
		//
		if (taskNum > 0 && taskNum > discountInterval) {
			taskNum = discountInterval;
		}
		//
		if (needTaskNum1 > 0 && taskNum > needTaskNum1) {
			taskNum = needTaskNum1;
		}
		//
		if (needTaskNum2 > 0 && taskNum > needTaskNum2) {
			taskNum = needTaskNum2;
		}
		//
		if (mNumIterations < mPluribus->mMaxIterations) {
			for (int i = 0; i < taskNum; i++) {
				Task t;
				t.Init();
				t.mType = TASK_TYPE_TRAIN;
				t.mTaskId = (++mNumIterations);
				t.mPluribus = mPluribus;
				t.mTrainer = this;
				submitTask(t);
			}
		}
	}
	//
	LOG_INFO("produce exited");
}

size_t Trainer::iterations() {
	return mNumIterations;
}

size_t Trainer::processed() {
	return mNumProcessed;
}

void Trainer::incrTaskProcessed() {
	mNumProcessed++;
}

void Trainer::incrAgentLoadedNum() {
	mAgentLoaded++;
}

void Trainer::incrAgentSavedNum() {
	mAgentSaved++;
}

void Trainer::waitThreadsIdle() {
	while (mRunning) {
		if (mNumIterations == mNumProcessed)
			break;
		//
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
}

void Trainer::waitModelLoadedOver() {
	while (mRunning) {
		if (isParallelLoaded())
			break;
		//
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
}

void Trainer::waitModelSavedOver() {
	while (mRunning) {
		if (isParalleSaved())
			break;
		//
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
}

void Trainer::parallelDiscount(double factor) {
	int agentSize = mPluribus->getAgentSize();
	for (int i = 0; i < agentSize; i++) {
		if (true) {
			Task t;
			t.mType = TASK_TYPE_DISCOUNT;
			t.mFactor = factor;
			t.mAgent = mPluribus->getAgentPointer(i);
			t.mPluribus = mPluribus;
			t.mTrainer = this;
			submitTask(t);
		}
	}
}

void Trainer::parallelStrategy() {
	int agentSize = mPluribus->getAgentSize();
	for (int i = 0; i < agentSize; i++) {
		if (true) {
			Task t;
			t.mType = TASK_TYPE_STRATEGY;
			t.mAgent = mPluribus->getAgentPointer(i);
			t.mPluribus = mPluribus;
			t.mTrainer = this;
			submitTask(t);
		}
	}
}

void Trainer::parallelLoad() {
	mAgentLoaded = 0;
	//
	int agentSize = mPluribus->getAgentSize();
	for (int i = 0; i < agentSize; i++) {
		if (true) {
			Task t;
			t.mType = TASK_TYPE_LOAD_MODEL;
			t.mAgent = mPluribus->getAgentPointer(i);
			t.mPluribus = mPluribus;
			t.mTrainer = this;
			submitTask(t);
		}
	}
}

void Trainer::parallelSave() {
	mAgentSaved = 0;
	//
	std::string suffix = mPluribus->getDateTime() + "/";
	std::string mkDir = Configure::GetInstance().mSavePath + suffix;
	if (0 != access(mkDir.c_str(), 0)) {
		if (mkdir(mkDir.c_str(), 0771) < 0 ) {
			LOG_ERROR("mkdir(" << mkDir << ") failed, errno=" << errno);
		}
	}
	//
	LOG_INFO("@Save: begin, savePath=" << mkDir);
	//
	int agentSize = mPluribus->getAgentSize();
	for (int i = 0; i < agentSize; i++) {
		if (true) {
			Task t;
			t.mType = TASK_TYPE_SAVE_MODEL;
			t.mAgent = mPluribus->getAgentPointer(i);
			t.mPluribus = mPluribus;
			t.mTrainer = this;
			t.mSuffix = suffix;
			submitTask(t);
		}
	}
}

void Trainer::submitTask(const Task &t) {
	TaskExecutor::GetInstance().submit(t);
}

bool Trainer::isParallelLoaded() {
	return (mAgentLoaded == mPluribus->getAgentSize());
}

bool Trainer::isParalleSaved() {
	return (mAgentSaved == mPluribus->getAgentSize());
}