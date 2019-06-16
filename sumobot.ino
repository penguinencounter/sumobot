#include "motorlib.h"
#include <Zumo32U4.h>

Zumo32U4Encoders encoders;
Zumo32U4Motors motors;
Zumo32U4ProximitySensors prox;
Zumo32U4Buzzer buzzer;
Zumo32U4ButtonA btn_a;
Zumo32U4ButtonB btn_b;
Zumo32U4ButtonC btn_c;

void setup() 
{
    encoders = Zumo32U4Encoders();
    motors = Zumo32U4Motors();
    prox = Zumo32U4ProximitySensors();
    buzzer = Zumo32U4Buzzer();
    btn_a = Zumo32U4ButtonA();
    btn_b = Zumo32U4ButtonB();
    btn_c = Zumo32U4ButtonC();
    prox.initThreeSensors();
    buzzer.play("!T240 L8 abcdefabcdefabcdef aaaaaafg aaaaaagf ccc ccc ddd ddcac badbad babc");
    ledGreen(true);
    motorCountTimer(100, 100, 300);
    motorCountTimer(-100, -100, 300);
}

void loop()
{
    /* RUNS OVER AND OVER AGAIN */
    btn_a.waitForPress();
    
}
