from bstem.platform import AdCord
import time
ad=AdCord()

while(True):
	print("Accelerometer:"+str(ad.accelerometer.value))
	time.sleep(.3)
