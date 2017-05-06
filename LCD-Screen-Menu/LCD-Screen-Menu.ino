/*
 * This code create a MENU structure on a 16x2 LCD screen.
 * Six (6) different screens are implemented, and you can travel
 * thru them by pressing a button on Arduino PIN 4. Each press
 * of the button advances one (1) screen. 
 * 
 * Made by Clovis Fritzen in 05/06/2017
 * http://www.FritzenMaker.com
 * http://www.FritzenLab.com.br
*/
//Based on YWROBOT's LiquidCrystal_I2C library, Library version:1.1
//Also based on the Debounce.ino sketch that comes with Arduino IDE

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

int WhichScreen =1;   // This variable stores the current Screen number
boolean hasChanged = true;
const int buttonPin = 4;    // the number of the pushbutton pin
int buttonState;             // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

void setup()
{
  lcd.init();// initialize the lcd 
  lcd.backlight();
  pinMode(buttonPin, INPUT);
   
}
void loop()
{

  if (hasChanged == true) {
    
  switch(WhichScreen) {
    case 1:
    {
      firstScreen();
    }
      break;
    
    case 2:
      {
        secondScreen();
      }
      break;
    
    case 3:
      {
        thirdScreen();
      }
      break;
    
    case 4:
      {
        fourthScreen();
      }
      break;
    
    case 5:
      {
        fifthScreen();
      }
      break;
    
    case 6:
      {
        sixthScreen();
      }
      break;
    case 0:
      {
        
      }
      break;
    }
}

    //-------------------------------
    // BEGIN of the switch debouncing code
    int reading = digitalRead(buttonPin);
  if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState) {
      buttonState = reading;

      // only toggle the LED if the new button state is HIGH
      if (buttonState == HIGH) {
        hasChanged = true;
        WhichScreen++;
        
        
      }
    } else {
      hasChanged = false;
    }
  }
  lastButtonState = reading;
  // END of the switch Debouncing code
  // --------------------------------------
  if (WhichScreen > 6){
    WhichScreen = 1;
  }
}

void firstScreen()
  {
   lcd.clear();
   lcd.setCursor(0,0); // Column, line
   lcd.print("This is screen 1");
   lcd.setCursor(0,1);
   lcd.print("On a menu system");
  }
void secondScreen()
  {
    lcd.clear();
    lcd.setCursor(0,0); // Column, line
    lcd.print("  Second screen");
    lcd.setCursor(0,1);
    lcd.print("of my menu !!");
  }
void thirdScreen()
  {
    lcd.clear();
    lcd.setCursor(0,0); // Column, line
    lcd.print("Hello, world!");
    lcd.setCursor(0,1);
    lcd.print("Third screen (3)");
  }
void fourthScreen()
  {
    lcd.clear();
    lcd.setCursor(0,0); // Column, line
    lcd.print("This is screen 4");
    lcd.setCursor(0,1);
    lcd.print("Just press btn");
  }
void fifthScreen()
  {
    lcd.clear();
    lcd.setCursor(0,0); // Column, line
    lcd.print("   Fifth screen");
    lcd.setCursor(0,1);
    lcd.print("i2C LCD screen");
  }
void sixthScreen()
  {
    lcd.clear();
    lcd.setCursor(0,0); // Column, line
    lcd.print("THE last screen");
    lcd.setCursor(0,1);
    lcd.print("  Sixth and last");
  }
  

  

