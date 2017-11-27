/*
 * buttons.c
 *
 * Created: 2015-06-12 16:28:53
 * Author: To Be Decided
 */ 

#include "buttons.h"
#include "adcFunctions.h"	/* Must use the value from the ADC to figure out which button */

buttonType readLCDbutton(void)
{
	int val = analogRead(0);
	/* Write code here */
	if(val==0){
		return btnRIGHT;
	}
	else if(val<1400 && val>1100){
		return btnDOWN;
	}
	else if(val<700 && val>400){
		return btnUP;
	}
	else if(val<1900 && val >1700){
		return btnLEFT;
	}
	else if(val<3000 && val >2100){
		return btnSELECT;
	}
	else {return btnNONE;}

		/* Change to actual value */
}