#include<servo.h>
motors, and servo
const int leftSensor=9;
const int rightSensor=10;
const int forwardSensor=8;
const int leftMotor1=2;
const int leftMotor2=3;
const int rightMotor1=4;
const int rightMotor2=5;
const int waterPump=6;
const int servoPin=7;
number if necessary
 
Servo myservo;
//declare a boolean varable to track water pump status and fire status
bool isWaterPumpOn=false;
bool fire=false;

//initialize flame sensor, motor and servo
void setup(){
	pinMode(leftSensor, INPUT);
	pinMode(rightSensor, INPUT);
	pinMode(forwardSensor, INPUT);
	pinMode(leftMotor1, OUTPUT);
	pinMode(leftMotor2, OUTPUT);
	pinMode(rightMotor1, OUTPUT);
	pinMode(rightMotor2, OUTPUT);
	pinMode(waterPump, OUTPUT);
	
	//attach the servo to the pin
	myservo.attach(servo.Pin);
	myservo.write(0);
	
}  

//loop forever

void loop(){
	if(digitalRead(leftSensor) == HIGH || digitalRead(rightSensor) == HIGH || digitalRead(forwardSensor) == HIGH){
		fire=true;
		
		
	}
	else{
		fire=false;
	}
	//if there is fire, move the robot towaards it
	if(fire){
		if(digitalRead(leftSensor) == HIGH){
			//turn left
			digitalWrite(leftMotor1, HIGH);
			digitalWrite(leftMotor2, LOW);
			digitalWrite(rightMotor1, LOW);
			digiatlWrite(rightMotor2, HIGH);
			
		}
		else if (digitalRead(rightSensor) == HIGH){
			//turn right
			digitalWrite(leftMotor1, LOW);
			digitalWrite(leftMotor2, HIGH);
			digitalWrite(rightMotor1, HIGH);
			digiatlWrite(rightMotor2, LOW);
		
		}
		else if(digitalRead(forwadSensor) == HIGH){
			//move forward
			digitalWrite(leftMotor1, HIGH);
			digitalWrite(leftMotor2, LOW);
			digitalWrite(rightMotor1, HIGH);
			digiatlWrite(rightMotor2, LOW);
		}
		
	}
	else{
		//no fire detected, stop the motors
		digitalWrite(leftMotor1, LOW);
		digitalWrite(leftMotor2, LOW);
		digitalWrite(rightMotor1, LOW);
		digiatlWrite(rightMotor2, LOW);
	}
	//IF ROBOT IS CLOSE TO THE FIRE AND THE LEFT SENSOR IS DETECTING FIRE, TURN ON THE WATER PUMP AND SPRAY WATER
	if (fire&&(digitalRead(leftSensor) == HIGH || digitalRead(rightSensor) == HIGH || digitalRead(forwardSensor) == HIGH))
	{
		digitalWrite(waterPump, HIGH);
		isWaterPumpOn=true;
		
		//rotate servo to spray water at the sight where the fire is detected
		myservo.write(120);
		delay(1000);//delay for spraying wter 
	}
	else{
		digitalWrite(waterPump, LOW);
		isWaterPumpOn = false;
		// set the servo back to 0 degree when the fire is extinguished
		myservo.write(0);
	}
}

