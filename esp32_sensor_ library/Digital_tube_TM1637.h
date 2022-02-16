#ifndef DIGITAL_TUBE_TM1637_H
#define DIGITAL_TUBE_TM1637_H

#include <Arduino.h>  

class Digital_tube_TM1637
{
    private:
        uint8_t TM1637_CLK;
        uint8_t TM1637_DIO;
        
    public:
    void displayclock(int hour,int minute,int second);  //播放时钟
    void displaycountdown(int hour,int minute,int second) ;  //倒计时
    void displaytiming(int hour,int minute,int second) ;  //计时
    void displayerror(void) ;   //显示88：88,用来表示错误信息
    
    void coding(uint8_t DispData[]);
    void start(void);
    void stop(void);
    void display(uint8_t BitAddr,int8_t DispData);
    void clearDisplay(void);
    void init(void);



};


#endif