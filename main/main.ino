#include "misc.h"
#include "servos.h"
#include "creep.h"
#include "leg.h"

#include <avr/sleep.h>

// 0 -- Power off
// 1 -- Walk
// 2 -- Nothing
// 3 -- Home
int robot_mode = 2;


void setup() {
    // battery_setup();
    servo_setup();
    // start serial debug output
    Serial.begin(115200);
    Serial.println("Startup");
}

void loop() {
    if(Serial.available()) {
      unsigned char cin = Serial.read();
      Serial.println(cin,DEC);
      switch (cin) {
        case 48: // 0
           robot_mode = 0;
           Serial.println("Robot Mode: power off");
           break;
        case 49: // 1
           robot_mode = 1;
           Serial.println("Robot Mode: walk");
           break;
        case 50: // 2
           robot_mode = 2;
           Serial.println("Robot Mode: stop");
           break;
        case 51: // 3
           robot_mode = 3;
           Serial.println("Robot Mode: home");
           break;
         case 119: // w
           robot_mode = 1;
           creep_dx = 0.0;
           creep_dy = 1.0;
           creep_rotation = 0.0;
           Serial.println("Robot Mode: walk forward");
           break;
         case 97: // a
           robot_mode = 1;
           creep_dx = -1.0;
           creep_dy = 0.0;
           creep_rotation = 0.0;
           Serial.println("Robot Mode: walk left");
           break; 
         case 115: // s
           robot_mode = 1;
           creep_dx = 0.0;
           creep_dy = -1.0;
           creep_rotation = 0.0;
           Serial.println("Robot Mode: walk backward");
           break; 
         case 100: // d
           robot_mode = 1;
           creep_dx = 1.0;
           creep_dy = 0.0;
           creep_rotation = 0.0;
           Serial.println("Robot Mode: walk right");
           break;
         case 113: // q
           robot_mode = 1;
           creep_dx = 0.0;
           creep_dy = 0.0;
           creep_rotation = 0.05;
           Serial.println("Robot Mode: walk right");
           break; 
         case 101: // e
           robot_mode = 1;
           creep_dx = 0.0;
           creep_dy = 0.0;
           creep_rotation = -0.05;
           Serial.println("Robot Mode: walk right");
           break; 
      }
    }
    
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
