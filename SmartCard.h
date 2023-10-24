/* 
SmartCard
A library for viewing cards , etc
By: Sivakumar Adchayan


*/



#define SmartCard

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h" // for attachInterrupt, FALLING
#else
#include "WProgram.h"
#endif

class Card {
    public:
        int CD = 3;
        int RST = 2;
        int CLK = A5;
        int DATA = A4;
    void setCardPins(int dCD,int dRST,int dCLK,int dDATA) {
            CD = dCD;
            RST = dRST;
            CLK = dCLK;
            DATA = dDATA;
        }

    void initialize() {
        pinMode(CLK,OUTPUT);
        digitalWrite(CLK,HIGH);
        pinMode(RST,OUTPUT);
        digitalWrite(RST,HIGH);
        pinMode(CD,OUTPUT);
        digitalWrite(CD,HIGH);
        pinMode(DATA,INPUT);
    }
    
    bool isCardPresent() {
        bool iscp = digitalRead(DATA);
        return iscp;
    }
};