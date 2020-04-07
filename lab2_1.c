#pragma config(Sensor, in3,    rightLineFollower, sensorLineFollower)
#pragma config(Sensor, in2,    centerLineFollower, sensorLineFollower)
#pragma config(Sensor, in1,    leftLineFollower, sensorLineFollower)
#pragma config(Motor,  port1,           leftMotor,     tmotorVex393_HBridge, openLoop, reversed, encoderPort, None)
#pragma config(Motor,  port10,          rightMotor,    tmotorVex393_HBridge, openLoop, encoderPort, None)


void moveForward(float time){ //moves both motors forward at max power
	motor[rightMotor] = 50;
	motor[leftMotor]  = 50;
	wait1Msec(time);
}

void moveForward(){ //moves both motors forward at max power
	motor[rightMotor] = 50;
	motor[leftMotor]  = 50;
}


void turnRight(){//rotate the right motor to turn it to the left
	motor[rightMotor] = 15;//59.1
	motor[leftMotor] = 30;
//	wait1Msec(2000);
}

void turnLeft(){//rotate the left motor to turn it to the right
	motor[leftMotor] = 15;
	motor[rightMotor] = 30;
//	wait1Msec(2000);
}
void stopMotors(){//stop robot
	motor[leftMotor] = 0;
	motor[rightMotor]=0;
	wait1Msec(2000);
}



task main()
{
	int threshold = 2000;
	bool check = true;
	//wait before start executing program
	wait1Msec(5000);

	//execute first goal - reach first black line
	moveForward(200);
	//execute second goal - keep first black line centered with robot until destination reached
	//
	while(check ==true){ //used as place holder for sonar check

		if(SensorValue[centerLineFollower] > threshold ){//move forward
			moveForward(100);
		}
		if(SensorValue[leftLineFollower] > threshold ){//turn left if color is light on left sensor
			turnLeft();
		}
		if(SensorValue[rightLineFollower] > threshold ){//turn right if color light on right sensor
			turnRight();
		}
	}
	stopMotors();//stop robot
}
#pragma config(Sensor, in3,    rightLineFollower, sensorLineFollower)
#pragma config(Sensor, in2,    centerLineFollower, sensorLineFollower)
#pragma config(Sensor, in1,    leftLineFollower, sensorLineFollower)
#pragma config(Motor,  port1,           leftMotor,     tmotorVex393_HBridge, openLoop, reversed, encoderPort, None)
#pragma config(Motor,  port10,          rightMotor,    tmotorVex393_HBridge, openLoop, encoderPort, None)


void moveForward(float time){ //moves both motors forward at max power
	motor[rightMotor] = 50;
	motor[leftMotor]  = 50;
	wait1Msec(time);
}

void moveForward(){ //moves both motors forward at max power
	motor[rightMotor] = 50;
	motor[leftMotor]  = 50;
}


void turnRight(){//rotate the right motor to turn it to the left
	motor[rightMotor] = 15;//59.1
	motor[leftMotor] = 30;
//	wait1Msec(2000);
}

void turnLeft(){//rotate the left motor to turn it to the right
	motor[leftMotor] = 15;
	motor[rightMotor] = 30;
//	wait1Msec(2000);
}
void stopMotors(){//stop robot
	motor[leftMotor] = 0;
	motor[rightMotor]=0;
	wait1Msec(2000);
}



task main()
{
	int threshold = 2000;
	bool check = true;
	//wait before start executing program
	wait1Msec(5000);

	//execute first goal - reach first black line
	moveForward(200);
	//execute second goal - keep first black line centered with robot until destination reached
	//
	while(check ==true){ //used as place holder for sonar check

		if(SensorValue[centerLineFollower] > threshold ){//move forward
			moveForward(100);
		}
		if(SensorValue[leftLineFollower] > threshold ){//turn left if color is light on left sensor
			turnLeft();
		}
		if(SensorValue[rightLineFollower] > threshold ){//turn right if color light on right sensor
			turnRight();
		}
	}
	stopMotors();//stop robot
}
