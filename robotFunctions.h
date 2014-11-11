#ifndef robotFunctions_h
#define robotFunctions_h

float leftFrontSpeed = 0;
float leftBackSpeed = 0;
float rightFrontSpeed = 0;
float rightBackSpeed = 0;

void move(float distance, int power) { //distance in inches
	distance = distance / 0.032527;
	nMotorEncoder[leftFront] = 0;
	nMotorEncoder[leftBack] = 0;
	nMotorEncoder[rightFront] = 0;
	nMotorEncoder[rightBack] = 0;
	while (abs(nMotorEncoder[leftFront]) < distance) {
		motor[leftFront] = power;
		motor[leftBack] = power;
		motor[rightFront] = power;
		motor[rightBack] = power;
	}
}

void turn(int degree, int power, bool leftDir) {
	nMotorEncoder[leftFront] = 0;
	nMotorEncoder[leftBack] = 0;
	nMotorEncoder[rightFront] = 0;
	nMotorEncoder[rightBack] = 0;
	int stopTurn = 1380; //encoderTick/1 degree * degree var Number will need to be changed
	if(leftDir) {
		while(nMotorEncoder[leftFront] < stopTurn && nMotorEncoder[leftBack] < stopTurn) {
			motor[leftFront] = power;
			motor[leftBack] = power;
			motor[rightFront] = power * -1;
			motor[rightBack] = power * -1;
		}
	} else {
			while(nMotorEncoder[leftFront] < stopTurn && nMotorEncoder[leftBack] < stopTurn) {
				motor[leftFront] = power * -1;
				motor[leftBack] = power * -1;
				motor[rightFront] = power;
				motor[rightBack] = power;
			}
	}
}

void grabRollingGoal() {
	servo[grabber] = 255;
	wait1Msec(100); //Number will need to be changed
	servo[grabber] = 127;
	wait1Msec(100); //Number will need to be changed STOP SERVO
}

void releaseRollingGoal() {
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
