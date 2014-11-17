#ifndef robotFunctions_h
#define robotFunctions_h

#include "action.c"

void resetMoveEncoders()
{
	/*sets the drive train motor encoders to zero*/
	nMotorEncoder[leftFront] = 0;
	nMotorEncoder[leftBack] = 0;
	nMotorEncoder[rightFront] = 0;
	nMotorEncoder[rightBack] = 0;
}

defActionData();
	float distance;
	int power;
endActionData(moveData, MoveData);

bool moveActionExecuting();

void startMove(float distance, int power)
{
	/*distance is in inches*/
	if(!moveActionExecuting())
	{
		resetMoveEncoders();
		motor[leftFront] = power;
		motor[leftBack] = power;
		motor[rightFront] = power;
		motor[rightBack] = power;
		moveData.distance = distance / 0.032527;
		moveData.power = power;
		startAction(moveData)
	}
}

bool moveUpdate(int time, MoveData data) {
	return abs(nMotorEncoder[leftFront]) < data.distance;
}

defActionData();
	int degree;
	int power;
	bool leftDir;
//endActionDef(turnData, TurnData);
} TurnData;
TurnData turnData;

void startTurn(int degree, int power, bool leftDir)
{
	if(!moveActionExecuting())
	{
		resetMoveEncoders();
		if(leftDir)
		{
			motor[leftFront] = power;
			motor[leftBack] = power;
			motor[rightFront] = power * -1;
			motor[rightBack] = power * -1;
		}
		else
		{
				motor[leftFront] = power * -1;
				motor[leftBack] = power * -1;
				motor[rightFront] = power;
				motor[rightBack] = power;
		}
		turnData.degree = degree;
		turnData.power = power;
		turnData.leftDir = leftDir;
	}
}

void turnUpdate() {

	const int stopTurn = 1380 * turnData.degree; //encoderTick/1 degree * degree var Number will need to be changed
	if(turnData.leftDir) {
		return nMotorEncoder[leftFront] < stopTurn && nMotorEncoder[leftBack] < stopTurn;
	}
}

bool moveActionExecuting()
{
	return isActionExecuting(moveData) || isActionExecuting(turnData);
}

void grabRollingGoal() {
	servo[grabber] = 255;
	wait1Msec(100); //Number will need to be changed
	servo[grabber] = 127;
	wait1Msec(100); //Number will need to be changed STOP SERVO
}

void releaseRollingGoal() { //not an action since one would expect to grab something before continuing
	servo[grabber] = 0;
	wait1Msec(100); //Number will need to be changed
	servo[grabber] = 127;
	wait1Msec(100); //Number will need to be changed STOP SERVO
}

void moveScissorLiftPos(int goalHeight) {
	goalHeight *= 0; //Number will need to be changed
	nMotorEncoder[scissorFront] = 0;
	while (nMotorEncoder[leftFront] < goalHeight) {
		motor[scissorFront] = 90;
	}
}

void moveScissorLift(int direction) {
	if(direction > 10) direction = 1;
	else direction = -1;
	motor[scissorFront] = 90 * direction;
}

void dropBallInGoal(int goalHeight) {
	//Turn Servo
}

void dropBallInGoal() {
	//Turn Servo
}


void pickUpBall() {}

#endif
