#ifndef ACTION_INCLUDED
#define ACTION_INCLUDED

#define isActionExecuting(data) data.executing \
	/*returns whether or not the given action is executing*/
#define startAction(data) isActionExecuting(data) = true;\
	/*starts the given action*/

#define stopAction(data) isActionExecuting(data) = false; \
	/*stops the given action*/

#define updateAction(update, data) \
	/*updates the given action*/ \
	if(isActionExecuting(data)) \
	{ \
		if(!update(0, data)) \
		{ \
			stopAction(data); \
		} \
	}
#define defActionData() \
	/*starts an action data stuct*/ \
	typedef struct \
	{ \
		bool executing \
		/*add your code here*/

#define endActionData(data, type) \
	/*ends an action data*/ \
		/*add your code here*/ \
	} type; \
	type data;

#define finishActionDefs() \
	/*finishs the action definitions*/ \
	void updateRobot() \
	{ \
		updateAction(testActionUpdate, testActionData); \
		updateAction(secondActionUpdate, secondActionData); \
	} \

void updateRobot();
/*update the robot*/

#endif
