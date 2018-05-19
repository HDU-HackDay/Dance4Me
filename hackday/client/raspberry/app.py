#/usr/bin/python2.7
# -*- coding: utf-8 -*-

# @Author homeway
# @Link http::homeway.me
# @Github https://github.com/grasses
# @Version 15.05.22

import os
import sys
import time
import websocket
import ultrasound_x as ultrasound

TRIG1 = 20
ECHO1 = 21

TRIG2 = 12
ECHO2 = 16

TRIG3 = 14
ECHO3 = 15

TIME_BREAK = 0.3
WS_URL = "ws://192.168.0.102:3000"


def main(url):
    #websocket.enableTrace(True)
    sensor = ultrasound.Ultrasound(TIME_BREAK)
    while True:
        #server = websocket.create_connection(url)
        distance1 = float(sensor.get_distances(TRIG1, ECHO1))
        if distance1>4:
            print("distance1 => ", distance1)
            try:
                pass
                #server.send(str(1))
            except EOFError:
                print("error =>", EOFError)
            time.sleep(0.2)
        else:
            time.sleep(0.1)

        distance2 = float(sensor.get_distances(TRIG2, ECHO2))
        if distance2>3.3:
            print("distance2 => ", distance2)
            try:
                pass
                #server.send(str(2))
            except EOFError:
                print("error =>", EOFError)
            time.sleep(0.2)
        else:
            time.sleep(0.1)

        distance3 = float(sensor.get_distances(TRIG3, ECHO3))
        if distance3>3.3:
            print("distance3 => ", distance3)
            try:
                pass
                #server.send(str(3))
            except EOFError:
                print("error =>", EOFError)
            time.sleep(0.2)
        else:
            time.sleep(0.1)

        #server.close()

if __name__ == "__main__":
    main(sys.argv[1] if len(sys.argv) > 1 else WS_URL)
