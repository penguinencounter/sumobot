#include "motorlib.h"
#include "sumoring.h"
#include <Zumo32U4.h>

Zumo32U4Encoders encoders;
Zumo32U4Motors motors;
Zumo32U4LCD lcd;
Zumo32U4LineSensors linesense;
Zumo32U4ProximitySensors prox;
Zumo32U4Buzzer buzzer;
Zumo32U4ButtonA btn_a;
Zumo32U4ButtonB btn_b;
Zumo32U4ButtonC btn_c;

unsigned int line_sensor_readings[3];
unsigned int prox_sensor_readings[3];
bool sensors_on_edge[3];
bool mute;

void setup() 
{
    encoders = Zumo32U4Encoders();
    motors = Zumo32U4Motors();
    prox = Zumo32U4ProximitySensors();
    lcd = Zumo32U4LCD();
    linesense = Zumo32U4LineSensors();
    buzzer = Zumo32U4Buzzer();
    btn_a = Zumo32U4ButtonA();
    btn_b = Zumo32U4ButtonB();
    btn_c = Zumo32U4ButtonC();
    mute = false;
    prox.initThreeSensors();
    lcd.clear();
    linesense.initThreeSensors();
    ledGreen(true);
    motorCountTimer(100, 100, 300);
    motorCountTimer(-100, -100, 300);
    lcd.write("Start: A");
    lcd.gotoXY(0, 1);
    lcd.write("Muted: C");
    while (true) {
        if (btn_a.isPressed()) {
            break;
        }
        else if (btn_c.isPressed()) {
            mute = true;
            break;
        }
    }
}

void loop()
{
    /* RUNS OVER AND OVER AGAIN */
}
