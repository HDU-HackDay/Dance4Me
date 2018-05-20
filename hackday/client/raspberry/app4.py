#/usr/bin/python2.7
# -*- coding: utf-8 -*-

# @Author homeway
# @Link http::homeway.me
# @Github https://github.com/grasses
# @Version 2018.05.19

import os, json
import sys
import time
import websocket
import ultrasound_x as ultrasound
from websocket import create_connection

TRIG1 = 14
ECHO1 = 15

TRIG2 = 23
ECHO2 = 24

TRIG3 = 12
ECHO3 = 16

TRIG4 = 20
ECHO4 = 21

TIME_BREAK = 0.3
WS_URL = "ws://192.168.0.105:3000"

debug = False
is_socket = True

def main(url):
    sensor = ultrasound.Ultrasound(TIME_BREAK)

    data = {
        "data": {'cid': 1},
        "type": "hard",
        "status": 1
    }

    count = 15
    while True:
        if count > 0 and is_socket:
            server = create_connection(url)
            count -= 1
    
        distance1 = float(sensor.get_distances(TRIG1, ECHO1))
        if debug and distance1 > 5 and distance1 < 100:
            print("distance1 => {:.3f}".format(distance1))
        time.sleep(0.05)

        distance2 = float(sensor.get_distances(TRIG2, ECHO2))
        if debug and distance2 > 5 and distance2 < 100:
            print("distance2 => {:.3f}".format(distance2))
        time.sleep(0.05)

        distance3 = float(sensor.get_distances(TRIG3, ECHO3))
        if debug and distance3 > 5 and distance3 < 100:
            print("distance3 => {:.3f}".format(distance3))
        time.sleep(0.05)

        distance4 = float(sensor.get_distances(TRIG4, ECHO4))
        if debug and distance4 > 5 and distance4 < 100:
            print("distance4 => {:.3f}".format(distance4))
        time.sleep(0.05)
        
        flag = [False, False, False, False, False, False, False, False]

        # 1 and 2
        if (distance1 > 0 and distance1 < 40) and (distance2 > 0 and distance2 < 40) and (distance3 > 0 and distance3 < 40):
            print("======> 1, 2")
            data["data"]["cid"] = 1
            if is_socket: server.send(json.dumps(data))
            data["data"]["cid"] = 2
            if is_socket: server.send(json.dumps(data))
            flag[4] = True

        # 3 and 4
        if (distance1 > 20 and distance1 < 80) and (distance2 > 20 and distance2 < 80) and (distance4 > 0 and distance4 < 40):
            print("======> 3, 4")
            data["data"]["cid"] = 3
            if is_socket: server.send(json.dumps(data))
            data["data"]["cid"] = 4
            if is_socket: server.send(json.dumps(data))
            flag[5] = True

        # 1 and 3
        if (distance1 > 0 and distance1 < 40) and (distance2 > 20 and distance2 < 80) and (distance4 > 20 and distance4 < 60):
            print("======> 1, 3")
            data["data"]["cid"] = 1
            if is_socket: server.send(json.dumps(data))
            data["data"]["cid"] = 3
            if is_socket: server.send(json.dumps(data))
            flag[6] = True

        # 2 and 4
        if (distance2 > 0 and distance2 < 40) and (distance3 > 0 and distance2 < 40) and (distance4 > 0 and distance4 < 60):
            print("======> 2, 4")
            data["data"]["cid"] = 2
            if is_socket: server.send(json.dumps(data))
            data["data"]["cid"] = 4
            if is_socket: server.send(json.dumps(data))
            flag[7] = True

        # only 1
        if distance1 > 0 and distance1 < 40 and distance3 < 80 and distance3 > 30:
            print("======> 1")
            flag[0] = True
            data["data"]["cid"] = 1
            if is_socket: server.send(json.dumps(data))
        
        # only 2
        if distance2 > 0 and distance2 < 40 and distance3 > 0 and distance3 < 40:
            print("======> 2")
            flag[1] = True
            data["data"]["cid"] = 2
            if is_socket: server.send(json.dumps(data))

        # only 3
        if distance1 < 60 and distance1 > 20 and distance4 < 80 and distance4 > 30:
            print("======> 3")
            flag[2] = True
            data["data"]["cid"] = 3
            if is_socket: server.send(json.dumps(data))

        # only 4
        if distance2 > 0 and distance2 < 40 and distance4 > 0 and distance4 < 40:
            print("======> 4")
            flag[3] = True
            data["data"]["cid"] = 4
            if is_socket: server.send(json.dumps(data))

        #time.sleep(0.1)

        # 长期没有触碰，直接休息2s
        if not flag[0] and not flag[1] and not flag[2] and not flag[3]:
            pass
            #print("=> sleep 1s...")
            #time.sleep(1)

        if count < 0 and is_socket:
            server.close()
            count = 10

if __name__ == "__main__":
    main(sys.argv[1] if len(sys.argv) > 1 else WS_URL)
