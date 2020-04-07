#pragma config(Sensor, in1,    lineFollowerRIGHT,   sensorLineFollower)
#pragma config(Sensor, in2,    lineFollowerCENTER,  sensorLineFollower)
#pragma config(Sensor, in3,    lineFollowerLEFT,    sensorLineFollower)
#pragma config(Motor,  port1,           rightMotor,    tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port10,           leftMotor,     tmotorNormal, openLoop)
#pragma config(Motor,  motor6,          clawMotor,    tmotorVexIQ, openLoop, reversed, encoder)
#pragma config(Motor,  motor7,          armMotor,      tmotorVexIQ, openLoop, encoder)
#pragma config(Sensor, dgtl8,  sonarSensor,    sensorSONAR_inch)


int threshold = 500;

task main()
{
	wait1Msec(2000);
	motor(clawMotor) = 100;   //Enable Servo Mode and move to position 10.
	sleep(500);

	bool check = true;
	motor[rightMotor] = 60;
	motor[leftMotor] = 60;
	wait1Msec(1500);

	while (check == true) {


		motor[rightMotor] = 60;
		motor[leftMotor] = 60;
		if (SensorValue(lineFollowerCENTER) > threshold) {
			check = false;

		}
	}
	if (SensorValue(lineFollowerLEFT) > threshold && SensorValue(lineFollowerLEFT) > threshold && SensorValue(lineFollowerRIGHT) > threshold) {
		motor[leftMotor] = 40;
		motor[rightMotor] = -40;
		wait1Msec(1000);
	}
	clearTimer(T1);						// Resets timer T1 to start counting at 0

	while (time1[T1] < 10000)
	{
		if (SensorValue(lineFollowerLEFT) > threshold)
		{
			// counter-steer left:
			motor[leftMotor] = -60;
			motor[rightMotor] = 60;
		}
		// RIGHT sensor sees dark:
		if (SensorValue(lineFollowerCENTER) > threshold)
		{
			// go straight
			motor[leftMotor] = 60;
			motor[rightMotor] = 60;
		}
		if (SensorValue(lineFollowerRIGHT) > threshold)
		{
			// counter-steer right:
			motor[leftMotor] = 60;
			motor[rightMotor] = -60;
		}
		// CENTER sensor sees dark:

		// LEFT sensor sees dark:

		if (SensorValue(lineFollowerLEFT) < threshold && SensorValue(lineFollowerLEFT) < threshold && SensorValue(lineFollowerRIGHT) < threshold) {

			motor[leftMotor] = 0;
			motor[rightMotor] = 0;

		}
	}

	while (SensorValue(sonarSensor) > 20 || SensorValue(sonarSensor) == -1)		// Loop while robot's Ultrasonic sensor is further than 20 inches away from an object
	{                                                                         // || (or) it is '-1'.  (-1 is the value returned when nothing is in it's visable range)
		motor[rightMotor] = 63;			// Motor on port2 is run at half (63) power forward
		motor[leftMotor] = 63;			// Motor on port3 is run at half (63) power forward
	}

	motor[rightMotor] = 0;
	motor[leftMotor] = 0;
	wait1Msec(500);
	resetMotorEncoder(armMotor); //Take current position as zero.


	sleep(500);


	motor(clawMotor) = -20;   //Enable Servo Mode and move to position 10.
	sleep(2000);


	motor[rightMotor] = 127;
	motor[leftMotor] = -127;
	wait1Msec(475);

	motor[rightMotor] = 127;
	motor[leftMotor] = 127;
	wait1Msec(2000);

	motor[rightMotor] = 127;
	motor[leftMotor] = -127;
	wait1Msec(475);

	check = true;

	while (check == true) {


		motor[rightMotor] = 60;
		motor[leftMotor] = 60;
		if (SensorValue(lineFollowerCENTER) > threshold) {
			check = false;

			motor[leftMotor] = 40;
			motor[rightMotor] = 0;
			wait1Msec(300);

		}
	}
	if (SensorValue(lineFollowerLEFT) > threshold && SensorValue(lineFollowerLEFT) > threshold && SensorValue(lineFollowerRIGHT) > threshold) {
		motor[leftMotor] = 40;
		motor[rightMotor] = -40;
		wait1Msec(1000);
	}
	clearTimer(T1);						// Resets timer T1 to start counting at 0

	while (time1[T1] < 20000)
	{
		if (SensorValue(lineFollowerLEFT) > threshold)
		{
			// counter-steer left:
			motor[leftMotor] = -50;
			motor[rightMotor] = 60;
		}
		// RIGHT sensor sees dark:
		if (SensorValue(lineFollowerCENTER) > threshold)
		{
			// go straight
			motor[leftMotor] = 60;
			motor[rightMotor] = 60;
		}
		if (SensorValue(lineFollowerRIGHT) > threshold)
		{
			// counter-steer right:
			motor[leftMotor] = 60;
			motor[rightMotor] = -50;
		}
		// CENTER sensor sees dark:

		// LEFT sensor sees dark:

		if (SensorValue(lineFollowerLEFT) < threshold && SensorValue(lineFollowerLEFT) < threshold && SensorValue(lineFollowerRIGHT) < threshold) {

			motor[leftMotor] = 0;
			motor[rightMotor] = 0;

		}
	}

	motor(armMotor) = 50;  //Enable Servo Mode and move to position 60.
	sleep(500);

	motor(clawMotor) = 100;   //Enable Servo Mode and move to position 10.
	sleep(480);

	motor[rightMotor] = 0;
	motor[leftMotor] = 0;
	wait1Msec(500);

	motor[rightMotor] = -127;
	motor[leftMotor] = -127;
	wait1Msec(2000);

	motor[rightMotor] = -127;
	motor[leftMotor] = 127;
	wait1Msec(475);

	motor[rightMotor] = 127;
	motor[leftMotor] = 127;
	wait1Msec(4000);

	motor[rightMotor] = 127;
	motor[leftMotor] = -127;
	wait1Msec(475);

	motor[rightMotor] = 127;
	motor[leftMotor] = 127;
	wait1Msec(2500);

}
