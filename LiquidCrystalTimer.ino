#include <timer.h>
#include <timerManager.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);

const int switchPin = 6;
Timer timer;

int seconds = 3;
int minutes = 9;

void setup() {
 
	Serial.begin(9600);

	timer.setInterval(1000);
	timer.setCallback(alarm);
	timer.start();

	pinMode(switchPin,INPUT);

	lcd.begin(16,2);
}

void loop() {

	timer.update();
}

void alarm() {

	seconds--;	

	if(seconds == -1) {

		minutes--;
		seconds = 59;
	}

	displayTime();
}

String getTimeString() {

	String time = "";
	time += minutes;  
	time += ":";  
	time += seconds;  
	time += " Min/Sek";  
	return time;  
}   

void displayTime() {

	String currentTimeString = getTimeString();

	lcd.setCursor(1,0);
	lcd.print(currentTimeString);
}
