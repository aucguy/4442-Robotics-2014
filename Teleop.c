#pragma config(Hubs,  S1, MatrxRbtcs, none,     none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  motorA,          leftFront,     tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorB,          leftBack,      tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorC,          rightFront,    tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  mtr_Matrix_S1_1, rightBack,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_Matrix_S1_2, scissorFront,  tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_Matrix_S1_3, motorF,        tmotorMatrix, openLoop)
#pragma config(Motor,  mtr_Matrix_S1_4, motorG,        tmotorMatrix, openLoop)
#pragma config(Servo,  srvo_Matrix_S1_1, grabber,              tServoContinuousRotation)
#pragma config(Servo,  srvo_Matrix_S1_2, servo2,               tServoContinuousRotation)
#pragma config(Servo,  srvo_Matrix_S1_3, servo3,               tServoNone)
#pragma config(Servo,  srvo_Matrix_S1_4, servo4,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "robotFunctions.h"
#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.


void initializeRobot() {
  return;
}

task main() {
	bool movement = true;
	bool grabberArmBack = true;
	//Button 1: Switch between movement and scissor lift
	initializeRobot();
	waitForStart();

	while (true) {
			if (joy1Btn(1) == 1) {
				movement = !movement;
				wait1Msec(200);
			}

		if (movement) {
			leftFrontSpeed = 0;
			leftBackSpeed = 0;
			rightFrontSpeed = 0;
			rightBackSpeed = 0;
			getJoystickSettings(joystick);
			if(joystick.joy1_y1 > 10 || joystick.joy1_y1 < -10) {
				leftFrontSpeed = joystick.joy1_y1;
				leftBackSpeed = joystick.joy1_y1;
			}
			if (joystick.joy1_y2 > 10 || joystick.joy1_y2 < -10) {
				rightFrontSpeed = joystick.joy1_y2;
				rightBackSpeed = joystick.joy1_y2;
			}
			motor[leftFront] = leftFrontSpeed;
			motor[leftBack] = leftBackSpeed;
			motor[rightFront] = rightFrontSpeed;
			motor[rightBack] = rightBackSpeed;
		} else { //Movement False - Scissor Lift
			if(joystick.joy1_y1 > 10 || joystick.joy1_y1 < -10) moveScissorLift(joystick.joy1_y1);
			else if (joy1Btn(2)) dropBallInGoal();
		}
		wait1Msec(50);
	}
}
