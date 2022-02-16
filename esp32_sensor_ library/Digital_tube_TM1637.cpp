#include "Digital_tube_TM1637.h"



unsigned char tab[] =
{
    //例如说0X3F，二进制为0011 1111,数据表示为高位再前，低位在后，
    //那么实际数据为1111 1100，对应数码管为 a,b,c,d,e,f,g,dp
    0x3F,/*0*/
    0x06,/*1*/
    0x5B,/*2*/
    0x4F,/*3*/
    0x66,/*4*/
    0x6D,/*5*/
    0x7D,/*6*/
    0x07,/*7*/
    0x7F,/*8*/
    0x6F,/*9*/
    0x77,/*10 A*/
    0x7C,/*11 b*/
    0x58,/*12 c*/
    0x5E,/*13 d*/
    0x79,/*14 E*/
    0x71,/*15 F*/
    0x76,/*16 H*/
    0x38,/*17 L*/
    0x54,/*18 n*/
    0x73,/*19 P*/
    0x3E,/*20 U*/
    0x00,/*21 黑屏*/
} ;



Digital_tube_TM1637::Digital_tube_TM1637(uint8_t CLK,uint8_t DIO){
    //初始化
    TM1637_CLK=CLK;
    TM1637_DIO = DIO;

    pinMode(TM1637_CLK,OUTPUT);
    pinMode(TM1637_DIO,OUTPUT);
}
;


/*void Digital_tube_TM1637::coding(uint8_t DispData[])
{
  uint8_t PointData;
  if(_PointFlag == POINT_ON)PointData = 0x80;
  else PointData = 0; 
  for(uint8_t i = 0;i < 4;i ++)
  {
    if(DispData[i] == 0x7f)DispData[i] = 0x00;
    else DispData[i] = TubeTab[DispData[i]] + PointData;
  }
}   */

void Digital_tube_TM1637::start(void){
    //开始传输
    digitalWrite(TM1637_CLK,HIGH);
    digitalWrite(TM1637_DIO,HIGH);
    digitalWrite(TM1637_DIO,LOW);
    digitalWrite(TM1637_CLK,LOW);


}

void Digital_tube_TM1637::stop(void){
    //停止
    digitalWrite(TM1637_CLK,LOW);
    digitalWrite(TM1637_DIO,LOW);
    digitalWrite(TM1637_CLK,HIGH);
    digitalWrite(TM1637_DIO,HIGH); 
}

void Digital_tube_TM1637::display(uint8_t BitAddr,int8_t DispData){
    //实际显示
    int8_t SegData;
    SegData = coding(DispData);
    start();          //start signal sent to TM1637 from MCU
    writeByte(ADDR_FIXED);//
    stop();           //
    start();          //
    writeByte(BitAddr|0xc0);//
    writeByte(SegData);//
    stop();            //
    start();          //
    writeByte(Cmd_DispCtrl);//
    stop();           //

}

void Digital_tube_TM1637::clearDisplay(void){
    //清屏
    display(0x00,0x7f);
    display(0x01,0x7f);
    display(0x02,0x7f);
    display(0x03,0x7f);


}
void Digital_tube_TM1637::init(void){
    //初始化
    pinMode(TM1637_CLK,OUTPUT);
    pinMode(TM1637_DIO,OUTPUT);
    clearDisplay();
}

void Digital_tube_TM1637::displayclock(uint8_t hour,uint8_t minute,uint8_t second){
    //用来显示时间
    //分别显示时、分、秒

}

void Digital_tube_TM1637::displayerror(void)
{
    //显示88：88并且闪烁用来显示错误信息
    display(0x00,0x7f);
    display(0x01,0x7f);
    display(0x02,0x7f);
    display(0x03,0x7f);

    delay(1);
    display(0x00,0x00);
    display(0x01,0x00);
    display(0x02,0x00);
    display(0x03,0x00);
}