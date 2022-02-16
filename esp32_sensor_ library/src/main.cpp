#include <Arduino.h>
//#include <Digital_tube_TM1637.h>

//Digital_tube_TM1637 tm1637;

#include "TM1637.h"
//#include <TimerOne.h>
#define ON 1
#define OFF 0


int8_t TimeDisp[] = {0x00,0x00,0x00,0x00};
unsigned char ClockPoint = 1;
unsigned char Update;
unsigned char halfsecond = 0;
unsigned char second;
unsigned char minute = 0;
unsigned char hour = 12;

#define CLK 23//pins definitions for TM1637 and can be changed to other ports    
#define DIO 22

static int8_t TubeTab[] = {0x3f,0x06,0x5b,0x4f,
                           0x66,0x6d,0x7d,0x07,
                           0x7f,0x6f,0x77,0x7c,
                           0x39,0x5e,0x79,0x71};//0~9,A,b,C,d,E,F 

TM1637 tm1637(CLK,DIO);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println('start tm1693 test');

  tm1637.set();
  tm1637.init();
  tm1637.set(BRIGHT_TYPICAL);//BRIGHT_TYPICAL = 2,BRIGHT_DARKEST = 0,BRIGHTEST = 7;
  //tm1637.init();
  

}

void loop() {
  // put your main code here, to run repeatedly:
  //tm1637.displayerror();
  
  for(int i=0;i<16;i++)
  {
    tm1637.display(0x00,TubeTab[i]);
    tm1637.display(0x01,TubeTab[i]);
    tm1637.display(0x02,TubeTab[i]);
    tm1637.display(0x03,TubeTab[i]);
    delay(1000);
  }
}

void TimingISR()
{
  halfsecond ++;
  Update = ON;
  if(halfsecond == 2){
    second ++;
    if(second == 60)
    {
      minute ++;
      if(minute == 60)
      {
        hour ++;
        if(hour == 24)hour = 0;
        minute = 0;
      }
      second = 0;
    }
    halfsecond = 0;  
  }
 // Serial.println(second);
  ClockPoint = (~ClockPoint) & 0x01;
}
void TimeUpdate(void)
{
  if(ClockPoint)tm1637.point(POINT_ON);
  else tm1637.point(POINT_OFF); 
  TimeDisp[0] = hour / 10;
  TimeDisp[1] = hour % 10;
  TimeDisp[2] = minute / 10;
  TimeDisp[3] = minute % 10;
  Update = OFF;
}