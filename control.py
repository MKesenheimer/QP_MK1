#!/usr/bin/python

# use $ sudo pip install --upgrad pip
# and $ sudo pip install pyserial
# and $ sudo pop install pygame
# first to upgrade and install pyserial

import time
import serial
import pygame
from pygame.locals import *
import sys

# initialize pygame screen
width  = 320
height = 240
size = (width, height)
pygame.display.init()
screen = pygame.display.set_mode(size) 

# configure the serial connections (the parameters differs on the device you are connecting to)
ser = serial.Serial(
    port='/dev/tty.HC-05-DevB',
    baudrate=9600,
    parity=serial.PARITY_ODD,
    stopbits=serial.STOPBITS_TWO,
    bytesize=serial.SEVENBITS
)

ser.isOpen()           

try:
    running=True
    clock = pygame.time.Clock()
    # run the game loop
    while running:
        clock.tick(10)
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                ser.close()
                pygame.quit()
                sys.exit()
            elif event.type == pygame.KEYDOWN:
                if event.key == K_w:
                    print 'forward'
                    ser.write('w')
                elif event.key == K_a:
                    print 'left'
                    ser.write('a')
                elif event.key == K_s:
                    print 'backward'
                    ser.write('s')
                elif event.key == K_d:
                    print 'right'
                    ser.write('d')
                elif event.key == K_q:
                    print 'rotate left'
                    ser.write('q')
                elif event.key == K_e:
                    print 'rotate right'
                    ser.write('e')
                elif event.key == K_0:
                    print 'power off'
                    ser.write('0')
                elif event.key == K_1:
                    print 'walk'
                    ser.write('1')
                elif event.key == K_2:
                    print 'stop'
                    ser.write('2')
                elif event.key == K_3:
                    print 'home'
                    ser.write('3')
                elif event.key == K_4:
                    print 'spread -'
                    ser.write('4')
                elif event.key == K_5:
                    print 'spread default'
                    ser.write('5')
                elif event.key == K_6:
                    print 'spread +'
                    ser.write('6')
                elif event.key == K_7:
                    print 'height -'
                    ser.write('7')
                elif event.key == K_8:
                    print 'height default'
                    ser.write('8')
                elif event.key == K_9:
                    print 'height +'
                    ser.write('9')
                else:
                    print 'Unknown Key: "{}"'.format(str(pygame.key.name(event.key)))

except pygame.error, perr:
    print('pygame Error: ' + str(perr))
except (KeyboardInterrupt, SystemExit):
    running = False
    print '\nQuit\n'