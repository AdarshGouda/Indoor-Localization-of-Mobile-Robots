r=open("agereadings.txt","r")
f=open("gyroscope.txt",'w')
sepFile = r.read().split('\n')
for ag in sepFile:
	gyro=ag.split(',')
	f.write(gyro[1]+"\n")
