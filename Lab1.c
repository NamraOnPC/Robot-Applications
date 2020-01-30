#pragma config(Motor,  port10,           rightMotor,    tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port1,           leftMotor,     tmotorNormal, openLoop)

task main()
{
	wait1Msec(500);

	motor[rightMotor] = -75;
	motor[leftMotor]  = -75;
	wait1Msec(1000);
	getMotorEncoder(port1);
	getMotorEncoder(port10);

		motor[rightMotor] = 0;
	motor[leftMotor]  = 0;
	wait1Msec(500);
	getMotorEncoder(port1);
	getMotorEncoder(port10);

	motor[rightMotor] = -127;
	motor[leftMotor]  = 127;
	wait1Msec(450);
	getMotorEncoder(port1);
	getMotorEncoder(port10);

		motor[rightMotor] = 0;
	motor[leftMotor]  = 0;
	wait1Msec(500);
	getMotorEncoder(port1);
	getMotorEncoder(port10);

	motor[rightMotor] = -75;
	motor[leftMotor]  = -75;
	wait1Msec(1300);
	getMotorEncoder(port1);
	getMotorEncoder(port10);

		motor[rightMotor] = 0;
	motor[leftMotor]  = 0;
	wait1Msec(1000);
	getMotorEncoder(port1);
	getMotorEncoder(port10);

	motor[rightMotor] = 127;
	motor[leftMotor]  = -127;
	wait1Msec(450);
	getMotorEncoder(port1);
	getMotorEncoder(port10);

	motor[rightMotor] = 0;
	motor[leftMotor]  = 0;
	wait1Msec(1000);
	getMotorEncoder(port1);
	getMotorEncoder(port10);

	motor[rightMotor] = -75;
	motor[leftMotor]  = -75;
	wait1Msec(1200);
	getMotorEncoder(port1);
	getMotorEncoder(port10);

	motor[rightMotor] = 0;
	motor[leftMotor]  = 0;
	wait1Msec(1000);
	getMotorEncoder(port1);
	getMotorEncoder(port10);

	motor[rightMotor] = 127;
	motor[leftMotor]  = -127;
	wait1Msec(450);
	getMotorEncoder(port1);
	getMotorEncoder(port10);

	motor[rightMotor] = 0;
	motor[leftMotor]  = 0;
	wait1Msec(1000);
	getMotorEncoder(port1);
	getMotorEncoder(port10);

	motor[rightMotor] = -75;
	motor[leftMotor]  = -75;
	wait1Msec(1300);
	getMotorEncoder(port1);
	getMotorEncoder(port10);

	motor[rightMotor] = 0;
	motor[leftMotor]  = 0;
	wait1Msec(1000);
	getMotorEncoder(port1);
	getMotorEncoder(port10);
}												        // Program ends, and the robot stops
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
