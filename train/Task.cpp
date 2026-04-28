#include "Task.hpp"
#include "Agent.hpp"
#include "Pluribus.hpp"
#include "Processor.hpp"
#include "Trainer.hpp"

Task::Task() {
	Init();
}

Task::~Task() {

}

void Task::Init() {
	mType = TASK_TYPE_NONE;
	mTaskId = 0;
	mFactor = 1.0;
	mAgent = nullptr;
	mPluribus = nullptr;
	mProcessor = nullptr;
	mTrainer = nullptr;
}

void Task::Process() {
	switch (mType) {
	case TASK_TYPE_TRAIN:
		train();
		break;
	case TASK_TYPE_DISCOUNT:
		discount();
		break;
	case TASK_TYPE_STRATEGY:
		strategy();
		break;
	case TASK_TYPE_RESEARCH:
		research();
		break;
	case TASK_TYPE_LOAD_MODEL:
		modelLoad();
		break;
	case TASK_TYPE_SAVE_MODEL:
		modelSave();
		break;
	default:
		LOGF_ERROR("unknown type: %d", mType);
		break;
	}
}

void Task::train() {
	if (nullptr != mPluribus) {
		mPluribus->trainConsume(mTaskId);
	} else {
		LOG_ERROR("@Task: mPluribus is nullptr!");
	}
	//
	if (nullptr != mTrainer) {
		mTrainer->incrTaskProcessed();
	} else {
		LOG_ERROR("@Task: mTrainer is nullptr!");
	}
}

void Task::discount() {
	if (nullptr != mAgent) {
		mAgent->Discount(mFactor);
	} else {
		LOG_ERROR("@Task: mAgent is nullptr!");
	}
	//
	if (nullptr != mProcessor) {
		mProcessor->incrDiscountProcessed();
	}
}

void Task::strategy() {
	if (nullptr != mAgent) {
		mAgent->UpdateStrategy();
	} else {
		LOG_ERROR("@Task: mAgent is nullptr!");
	}
	//
	if (nullptr != mProcessor) {
		mProcessor->incrStrategyProcessed();
	}
}

void Task::research() {
	if (nullptr != mPluribus) {
		mPluribus->searchConsume(mTaskId);
	} else {
		LOG_ERROR("@Task: mPluribus is nullptr!");
	}
	//
	if (nullptr != mProcessor) {
		mProcessor->incrTaskProcessed();
	} else {
		LOG_ERROR("@Task: mProcessor is nullptr");
	}
}

void Task::modelLoad() {
	if (nullptr != mAgent) {
		mAgent->Load();
	} else {
		LOG_ERROR("@Task: mAgent is nullptr!");
	}
	//
	if (nullptr != mTrainer) {
		mTrainer->incrAgentLoadedNum();
	}
}

void Task::modelSave() {
	if (nullptr != mAgent) {
		mAgent->Save(mSuffix);
	} else {
		LOG_ERROR("@Task: mAgent is nullptr!");
	}
	//
	if (nullptr != mTrainer) {
		mTrainer->incrAgentSavedNum();
	}
}
