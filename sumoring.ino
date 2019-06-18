#include <Zumo32U4.h>

extern Zumo32U4LineSensors linesense;
extern unsigned int line_sensor_readings[3];
extern bool sensors_on_edge[3];

bool edge()
{
    linesense.read(line_sensor_readings);
    bool white = line_sensor_readings[0] < 500 || line_sensor_readings[1] < 500 || line_sensor_readings[2] < 500;
    sensors_on_edge[0] = line_sensor_readings[0] < 500;
    sensors_on_edge[1] = line_sensor_readings[1] < 500;
    sensors_on_edge[2] = line_sensor_readings[2] < 500;
    return white ? true : false;
}
