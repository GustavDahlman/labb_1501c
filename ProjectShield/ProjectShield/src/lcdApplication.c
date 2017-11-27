/*
 * lcdApplication.c
 *
 * Created: 2015-09-10 08:44:50
 *  Author: To Be Decided
 */ 

#include "lcdApplication.h"
#include "buttons.h"	/* to get the buttontype definiton */
#include "LCDFunctions.h"
#include "DelayFunctions.h"

int lcdWrite4DigitNumber(int number)
{
	lcdClearDisplay();
	int temp = number/1000;
	
	number = number - temp*1000;
	
	char numb= (char) temp+48;
	int nbr = number;
	delayMicroseconds(10000);
	lcdWrite(numb,1);
	
	
	temp=number/100;
	
	number = number - temp*100;
	
	numb= (char) temp+48;
	
	delayMicroseconds(10000);
	lcdWrite(numb,1);
	
	temp=number/10;
	
	number = number - temp*10;
	
	numb= (char) temp+48;
	delayMicroseconds(10000);
	lcdWrite(numb,1);
	
	temp=number;
	
	number = number - temp*1;
	
	numb= (char) temp+48;
	//delayMicroseconds(10000);
	lcdWrite(numb,1);
	delayMicroseconds(10000);

	return 0;	/* Assuming everything went ok */
}

int lcdWriteAsciiString(const char *string)
/* writes an ascii string up to 40 characters on the LCD display */
{
	lcdClearDisplay();
	
	while((*string)!='\0'){
		delayMicroseconds(10000);
		lcdWrite(*string, 1);
		string++;
	}
	/* Write code here */
	
	return 0;	/* Assuming everything went ok */
}

int lcdWriteButtonValue(buttonType inputButton)
/* Writes the text corresponding to one of the buttosn on the LCD dispaly using lcdWriteAsciiString() 
 * Output should be one of SELECT, LEFT, UP, DOWN, RIGHT on the LCD display
 * if no buttons is pushed you can chose on displaying nothing or NONE  */
{
	/* Write code here */
	buttonType btn = inputButton;
	//har str[20];
	//char* p_str = &str;
	if(btn==btnDOWN){
		//char str[]= {'D','O','W','N','\0'};
		//char* p_str = &str;
		lcdWriteAsciiString("DOWN");
		}
	if(btn==btnLEFT){
		//char str[]= {'L','E','F','T','\0'};
		//char* p_str = &str;
		lcdWriteAsciiString("LEFT");	
		}
	if(btn==btnRIGHT){
		//char str[]= {'R','I','G','H','T','\0'};
		//char* p_str = &str;
		lcdWriteAsciiString("RIGHT");
	}
	if(btn==btnUP){
		//char str[]= {'U','P','\0'};
		//char* p_str = &str;
		lcdWriteAsciiString("UP");
	}
	if(btn==btnSELECT){
		//char str[]= {'S','E','L','E','C','T','\0'};
		//char* p_str = &str;
		lcdWriteAsciiString("SELECT");
	}
	if(btn==btnNONE){
		lcdWriteAsciiString("NONE");
	}
	
	
	return 0;	/* Assuming everything went ok */
}