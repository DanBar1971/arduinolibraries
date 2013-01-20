
#include "Arduino.h"
#include "mapToPWM.h"

mapToPWM::mapToPWM() {
}

int mapToPWM::mtp(int guideReading, int guideCentre, int guideMin, int guideMax, int deadZoneWidth, int pwmCentre, int pwmMin, int pwmMax) {
	//expected case: guideMin < guideCentre < guideMax & pwmMin < pwmCentre < pwmMax
	int thePWM; //the PWM value that will be returned.
	float floatPWM;
	float theNumerator;
	float thePercentage;

	//this function accounts for a stick-center deadzone.
	int negDZwidth = deadZoneWidth * -1;
	int ctrThresh = guideReading - guideCentre;
	if((ctrThresh < negDZwidth) && (guideReading > guideMin)) {
		float pwmRangeBelowCtr = float(pwmCentre - pwmMin);
		float guideRangeBelowCtr = float(guideCentre - guideMin - deadZoneWidth);
		theNumerator = guideRangeBelowCtr - float(guideReading - guideMin);
		thePercentage = theNumerator / guideRangeBelowCtr;
		floatPWM = float(pwmCentre) - (pwmRangeBelowCtr * thePercentage);
		thePWM = floatPWM;
	} else if ((ctrThresh > deadZoneWidth) && (guideReading < guideMax)) {
		float guideRangeAboveCtr = float(guideMax - guideCentre - deadZoneWidth);
		float pwmRangeAboveCtr = float(pwmMax - pwmCentre);
		theNumerator = guideRangeAboveCtr - float(guideMax - guideReading);
		thePercentage = theNumerator / guideRangeAboveCtr;
		floatPWM = float(pwmCentre) + (pwmRangeAboveCtr * thePercentage);
		thePWM = floatPWM;
	} else if (guideReading <= guideMin) {
		thePWM = pwmMin;
	} else if (guideReading >= guideMax) {
		thePWM = pwmMax;
	} else {
		thePWM = pwmCentre;
	}
	//  Serial.print("guideReading: ");
	//  Serial.print(guideReading);
	//  Serial.print(", thePWM: ");
	//  Serial.print(thePWM);
	//  Serial.println(" ");
	//  delay(666);
	return(thePWM);

  // pinMode(pin, OUTPUT);
  // _pin = pin;
}



// void mapToPWM::dot()
// {
//   digitalWrite(_pin, HIGH);
//   delay(250);
//   digitalWrite(_pin, LOW);
//   delay(250);  
// }

// void Morse::dash()
// {
//   digitalWrite(_pin, HIGH);
//   delay(1000);
//   digitalWrite(_pin, LOW);
//   delay(250);
// }