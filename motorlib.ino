#include <Zumo32U4.h>

extern Zumo32U4Encoders encoders;
extern Zumo32U4Motors motors;

void leftMotorCountTimer(int speed, long counts) {
    encoders.getCountsAndResetLeft();
    long left_c = 0;
    motors.setLeftSpeed(speed);
    if (speed > 0) {
        while (left_c < counts) {
            left_c += encoders.getCountsAndResetLeft();
            delay(2);
        }
    } else if (speed < 0)
    {
        while (left_c > -counts) {
            left_c += encoders.getCountsAndResetLeft();
            delay(2);
        }
    }
    motors.setLeftSpeed(0);
}

void rightMotorCountTimer(int speed, long counts) {
    encoders.getCountsAndResetLeft();
    long right_c = 0;
    motors.setRightSpeed(speed);
    if (speed > 0) {
        while (right_c < counts) {
            right_c += encoders.getCountsAndResetRight();
            delay(2);
        }
    } else if (speed < 0)
    {
        while (right_c > -counts) {
            right_c += encoders.getCountsAndResetRight();
            delay(2);
        }
    }
    
    motors.setRightSpeed(0);
}

void motorCountTimer(int l_speed, int r_speed, long counts) {
    encoders.getCountsAndResetLeft();
    encoders.getCountsAndResetLeft();
    long left_c = 0;
    long right_c = 0;
    bool left_inv = l_speed < 0;
    bool right_inv = r_speed < 0;
    motors.setSpeeds(l_speed, r_speed);
    // condition ? output a : output b
    // while (if the left motor is inverted, check if left_c is more than -counts, else check if left_c is less than counts)
    // OR (if the right motor is inverted, check if right_c is more than -counts, else check if right_c is less than counts) 
    // man that's big
    while ((left_inv ? left_c > -counts : left_c < counts) || (right_inv ? right_c > -counts : right_c < counts)) {
        left_c += encoders.getCountsAndResetLeft();
        right_c += encoders.getCountsAndResetRight();
        if (left_inv ? left_c <= -counts : left_c >= counts) { // Same thing. It's a conditional conditional!
            motors.setLeftSpeed(0); // Stop the motor if it's finished
        }
        if (right_inv ? right_c <= -counts : right_c >= counts) {
            motors.setRightSpeed(0); // Stop the motor if it's finished
        }
    }
    // Will always get here. May or may not be stopped.
    motors.setSpeeds(0, 0);
    // Is stopped. Report errors.
}
