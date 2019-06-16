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
    prox.initThreeSensors();
    lcd.clear();
    linesense.initThreeSensors();
    ledGreen(true);
    motorCountTimer(100, 100, 300);
    motorCountTimer(-100, -100, 300);
    lcd.write("Press A");
    btn_a.waitForPress();
    ledRed(0);
    ledGreen(0);
    ledYellow(1);
    buzzer.play("c16>c16");
    lcd.clear();
    lcd.write("5");
    delay(1000);
    lcd.clear();
    lcd.write("4");
    delay(1000);
    ledGreen(1);
    ledRed(1);
    lcd.clear();
    lcd.write("3");
    buzzer.play("f");
    delay(1000);
    ledRed(0);
    lcd.clear();
    lcd.write("2");
    buzzer.play("f");
    delay(1000);
    ledGreen(0);
    lcd.clear();
    lcd.write("1");
    buzzer.play("f");
    delay(1000);
    lcd.clear();
    ledYellow(0);
    buzzer.play(">c1");
}

void loop()
{
    /* RUNS OVER AND OVER AGAIN */
    lcd.clear();
    lcd.write(edge());
    delay(100);
}
