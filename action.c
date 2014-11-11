#ifndef ACTION_INCLUDED
#define ACTION_INCLUDED

#define isActionExecuting(data) data.executing
#define startAction(data) isActionExecuting(data) = true;
#define stopAction(data) isActionExecuting(data) = false;
#define updateAction(update, data) \
	if(isActionExecuting(data)) \
	{ \
		if(!update(0, data)) \
		{ \
			stopAction(data); \
		} \
	}
#define defActionData() typedef struct{bool executing
#define endActionData(data, type) } type; type data;

void updateRobot();

#endif
