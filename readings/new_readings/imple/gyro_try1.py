import math

print "Enter the initial position of the robot:"
k= 1500#input('Enter X:')
l= 1500#input('Enter Y:')

p_dist=0
p_ang=0

w=open("newdata.txt","w",0)
r=open("agereadings.txt","r")
sepFile = r.read().split('\n')
for val in sepFile: 
	reading = val.split(',')
	gz=float(reading[1])
	encoder=reading[3].split(' ')
	dist=((float(encoder[0])+float(encoder[1]))/2)
	r=dist-p_dist
	print (dist,p_dist,r)
	p_dist=dist
	#print("Left:"+str(-ad1.encoder[2].position*3.38))
	#print("Right:"+str(ad1.encoder[1].position*3.38))
	#print(dist)
	theta=(math.radians(gz))
	#theta=ang-p_ang
	#print (ang,p_ang,theta)
	#p_ang=ang
	k+=(r*(math.sin(theta)))
	l+=(r*(math.cos(theta)))
	print(k,l)
	print("------------------------------")
	w.write(str(k) + "," +str(l) + "\n")
w.close()
