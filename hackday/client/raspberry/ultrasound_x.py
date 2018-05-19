#!/usr/bin/python
# -*- coding: utf-8 -*-

# @Author homeway
# @Link http::homeway.me
# @Github https://github.com/grasses
# @Version 15.05.22

'''
注：本库用于3个超声波传感器同时使用，环境树莓派下安装RPi.GPIO，单个请用ultrasound.py
'''
import sys
import time
import RPi.GPIO as GPIO

breaks = 0.1

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)


class Ultrasound(object):
    def __init__(self, time_break=breaks):
        self.last_distance = 0
        self.current_distance = 0
        self.time_break = time_break

    def get_distance(self):
        self.last_distance = self.current_distance
        GPIO.setup(self.echo, GPIO.IN)
        GPIO.setup(self.trig, GPIO.OUT)
        GPIO.output(self.trig, GPIO.HIGH)
        time.sleep(0.00001)
        GPIO.output(self.trig, GPIO.LOW)
        start = time.time()
        while GPIO.input(self.echo) == GPIO.LOW:
            if time.time() - start > self.time_break:
                return self.get_distance()
        start = time.time()
        while GPIO.input(self.echo) == GPIO.HIGH:
            pass
        end = time.time()
        self.current_distance = 17000 * ( end - start )
        return self.current_distance

    def get_distances(self, trig, echo):
        self.last_distance = self.current_distance
        GPIO.setup(echo, GPIO.IN)
        GPIO.setup(trig, GPIO.OUT)
        GPIO.output(trig, GPIO.HIGH)
        time.sleep(0.00001)
        GPIO.output(trig, GPIO.LOW)
        start = time.time()
        while GPIO.input(echo) == GPIO.LOW:
            #print time.time()
            if time.time() - start > self.time_break:
                return self.get_distances(trig, echo)
        start = time.time()
        while GPIO.input(echo) == GPIO.HIGH:
            pass
        end = time.time()
        self.current_distance = 17000 * ( end - start )
        return self.current_distance

    def get_speed(self, trig, echo):
        return (self.get_distances(trig, echo) - self.last_distance) / self.time_break

if __name__ == '__main__':
    trig = 18
    echo = 12
    time_break = breaks

    if len(sys.argv) > 2:
        trig = int(sys.argv[1])
        echo = int(sys.argv[2])
        breaks = int(sys.argv[3])

    sensor = ultrasound(trig, echo, time_break)
    print sensor.get_distance()
    i = 0
    while i < 50:
        print sensor.get_speed(0.5)
        time.sleep(0.5)

