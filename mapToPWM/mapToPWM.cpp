
#include "mapToPWM.h"

mapToPWM::mapToPWM() {
}

int mapToPWM::mtp(int guideReading, int guideCentre, int guideMin, int guideMax, int deadZoneWidth, int pwmCentre, int pwmMin, int pwmMax, float kapow, float cap) {
	//expected case: guideMin < guideCentre < guideMax & pwmMin < pwmCentre < pwmMax
	int thePWM; //the PWM value that will be returned.
	float floatPWM;
	float theNumerator;
	float thePercentage;

	//this function accounts for a stick-center deadzone.
	int negDZwidth = deadZoneWidth * -1;
	int ctrThresh = guideReading - guideCentre;
	if(ctrThresh < negDZwidth) {
		float pwmRangeBelowCtr = float(pwmCentre - pwmMin);
		if(cap) {
			pwmRangeBelowCtr = pwmRangeBelowCtr * cap;
		}
		if(guideReading > guideMin) {
			float guideRangeBelowCtr = float(guideCentre - guideMin - deadZoneWidth);
			theNumerator = guideRangeBelowCtr - float(guideReading - guideMin);
			thePercentage = theNumerator / guideRangeBelowCtr;
			if(kapow) {
				thePercentage = pow(thePercentage,kapow);
			}
			floatPWM = float(pwmCentre) - (pwmRangeBelowCtr * thePercentage);
			thePWM = floatPWM;
		} else {
			thePWM = pwmCentre - pwmRangeBelowCtr;
		}
	} else if (ctrThresh > deadZoneWidth) {
		float pwmRangeAboveCtr = float(pwmMax - pwmCentre);
		if(cap) {
			pwmRangeAboveCtr = pwmRangeAboveCtr * cap;
		}
		if(guideReading < guideMax) {
			float guideRangeAboveCtr = float(guideMax - guideCentre - deadZoneWidth);
			theNumerator = guideRangeAboveCtr - float(guideMax - guideReading);
			thePercentage = theNumerator / guideRangeAboveCtr;
			if(kapow) {
				thePercentage = pow(thePercentage,kapow);
			}
			floatPWM = float(pwmCentre) + (pwmRangeAboveCtr * thePercentage);
			thePWM = floatPWM;
		} else {
			thePWM = pwmCentre + pwmRangeAboveCtr;
		}
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
}