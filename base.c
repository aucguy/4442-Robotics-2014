/*refer to doc/base guide.txt on instructions on how to use this
TODO add header file*/

#define baseName(action, name) __RoBoT ## action ## name
	/*internally used function. Conacts __RoBot to action to name*/

#define declareAction(action) \
	/*call this function with the arguement of the action function to declare an action*/ \
	bool basename(action, Activated);

#define isActionExecuting(action) \
	/*'returns' whether or the given action is executing*/\
	basename(action, Activated);


#define updateAction(action) \
	/*calls the action if it is currently executing. Should be called once per tick*/
	if(isActionExecuting(action)) \
	{ \
		if(callAction(action)) \
		{ \
			stopAction(action); \
		} \
	} \

#define callAction(action) \
	/*internally used function. Calls the action no matter what*/
	action();

#define startAction(action) \
	/*starts executing the function*/
	isActionExecuting(action) = true;

#define stopAction(action) \
	/*stops executing the function*/
	isActionExecuting(action) = false;

void initRobot()
{
	/*this should be called just in case this is actually neccessary.
	Obviously this currently does nothing.*/
}
void updateRobot()
{
	/*call this function each tick, since this updates each action
	For each action you add, add the following line of code here:
		updateAction(action)
	where action is the name of the action function*/
}
