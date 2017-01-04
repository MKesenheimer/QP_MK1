#include "misc.h"
#include "servos.h"
#include "creep.h"
#include "leg.h"
#include "serial.h"

#include <avr/sleep.h>

// 0 -- Power off
// 1 -- Walk
// 2 -- Nothing
// 3 -- Home
int robot_mode = 2;
    
void setup() {
    servo_setup();
    serial_setup();
}

void loop() {
    serial_loop();
    switch (robot_mode) {
        case 0: // Power off
            servo_shutdown();
            set_sleep_mode(SLEEP_MODE_PWR_DOWN);
            sleep_enable();
            sleep_mode();
            while (1) {
                delay(100);
            }
            break;
        case 1:
            walk();
            break;
        case 2: // Nothing
            delay(100);
            break;
        case 3: // Home
            servo_setup();
            break;
    }
}
