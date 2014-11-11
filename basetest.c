#include "action.c"

defActionData();
	string m;
endActionData(testActionData, TestActionData);

const int BUTTON_RIGHT = 1;

void startSecondAction(const string m);

bool testActionUpdate(int time, TestActionData data)
{
	writeDebugStream(data.m);
	string tmp;
	sprintf(tmp, "%i\n", nNxtButtonPressed);
	writeDebugStream(tmp);
	if(nNxtButtonPressed == BUTTON_RIGHT)
	{
		startSecondAction("hello world\n");
	}
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

defActionData();
	string m;
endActionData(secondActionData, SecondActionData);

bool secondActionUpdate(int time, SecondActionData data)
{
	writeDebugstream(data.m);
	return true;
}

void startSecondAction(const string m)
{
	if(!isActionExecuting(secondActionData))
	{
		secondActionData.m = m;
		startAction(secondActionData);
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
