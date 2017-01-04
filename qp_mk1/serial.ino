#include "serial.h"
#include <SoftwareSerial.h>

SoftwareSerial btSerial(rxPin, txPin);

void serial_setup() {
    Serial.begin(115200);
    Serial.println("Startup");
    btSerial.begin(9600);
    btSerial.println("Startup");
}

void serial_loop() {
    if(btSerial.available()) {
      unsigned char cin = btSerial.read();
      btSerial.println(cin,DEC);
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
           creep_dy = 0;
           creep_dx = 0;
           creep_rotation = 0;
           Serial.println("Robot Mode: stop");
           break;
        case 51: // 3
           robot_mode = 3;
           Serial.println("Robot Mode: home");
           break;
        case 52: //4
            creep_spread--;
            Serial.println("Spread -");
            break;
        case 53: //5
            creep_spread = 0.0;
            Serial.println("Spread default");
            break;
        case 54: //6
            creep_spread++;
            Serial.println("Spread +");
            break;
        case 55: //7
            creep_height--;
            Serial.println("Height -");
            break;
        case 56: //8
            creep_height = TIBIA * 0.80;
            Serial.println("Height default");
            break;
        case 57: //9
            creep_height++;
            Serial.println("Height +");
            break;
         case 119: // w
           robot_mode = 1;
           creep_dx = 0;
           creep_dy = max(1, creep_dy + 0.25);
           creep_rotation = 0;
           Serial.println("Robot Mode: walk forward");
           Serial.println(creep_dy,DEC);
           break;
         case 97: // a
           robot_mode = 1;
           creep_dx = min(-1, creep_dx - 0.25);
           creep_dy = 0;
           creep_rotation = 0;
           Serial.println("Robot Mode: walk left");
           Serial.println(creep_dx,DEC);
           break; 
         case 115: // s
           robot_mode = 1;
           creep_dx = 0;
           creep_dy = min(-1, creep_dy - 0.25);
           creep_rotation = 0;
           Serial.println("Robot Mode: walk backward");
           Serial.println(creep_dy,DEC);
           break; 
         case 100: // d
           robot_mode = 1;
           creep_dx = max(1, creep_dx + 0.25);
           creep_dy = 0;
           creep_rotation = 0;
           Serial.println("Robot Mode: walk right");
           Serial.println(creep_dx,DEC);
           break;
         case 113: // q
           robot_mode = 1;
           creep_dx = 0;
           creep_dy = 0;
           creep_rotation = max(PI/180, creep_rotation + PI/360);
           Serial.println("Robot Mode: rotate right");
           Serial.println(creep_rotation,DEC);
           break; 
         case 101: // e
           robot_mode = 1;
           creep_dx = 0;
           creep_dy = 0;
           creep_rotation = min(-PI/180, creep_rotation - PI/360);
           Serial.println("Robot Mode: rotate left");
           Serial.println(creep_rotation,DEC);
           break; 
      }
    }
}
