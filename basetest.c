#include "action.c"

defActionData();
	string m;
endActionData(testActionData, TestActionData);

const int BUTTON_RIGHT = 1;

bool testActionUpdate(int time, TestActionData data)
{
	writeDebugStream(data.m);
	string tmp;
	sprintf(tmp, "%i\n", nNxtButtonPressed);
	writeDebugStream(tmp);
	return nNxtButtonPressed != BUTTON_RIGHT;
}

void startTestAction(const string m)
{
	if(!isActionExecuting(testActionData))
	{
		testActionData.m = m;
		startAction(testActionData);
	}
}

finishActionDefs();

task main()
{
	startTestAction("Foo Bar\n");
	while(true)
	{
		updateRobot();
	}
}
