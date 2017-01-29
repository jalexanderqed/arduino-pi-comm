import serial
import time

ser = serial.Serial('/dev/ttyACM0', 9600)

print ser.readline()

for i in range(1, 10):
    ser.write(str(i))
    time.sleep(2000)
