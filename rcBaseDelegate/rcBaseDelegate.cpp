
#include "Arduino.h"
#include "rcBaseDelegate.h"

//vars

rcBaseDelegate::rcBaseDelegate() {  //constructor
	
}

void rcBaseDelegate::delegate(String cmd, int cmdval)
{

	if (cmd.equals("<") || cmd.equals(">") || cmd.equals("^")) {
    	//handlerumbling(cmd, cmdval);
	}

	if(cmd.equals("S")) {
	    if(cmdval == 0) {
	      //digitalWrite(13, LOW);
	    } else if (cmdval == 1) {
	      //digitalWrite(13, HIGH);
	    }
	}

}