from random import *
import time
import os

file ="fire.wav"

while(True):
    temp = randint(1, 100)
    humidity = randint(1, 100)
    if (temp > 30 and humidity > 30):
        os.system(file)
        time.sleep(11)
    else:
        print('temperatur',temp)
        print('humidity',humidity)


