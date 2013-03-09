#ifndef BASETASK_H_
#define BASETASK_H_

#include <memory>
#include "Task/GoalTree.h"

namespace Task
{

	typedef std::shared_ptr<BaseTask> Task_ptr;

	class BaseTask
	{
	public:

	protected:

	private:
		std::shared_ptr<GoalTree> tree;

	};

}
