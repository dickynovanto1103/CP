def gcd(a, b):
	if(a==0):
		return b
	else:
		return gcd(b%a, a)

x = 0
y = 0

def gcdExtended(a, b):
	global x,y
	if(a==0):
		x = 0
		y = 1
		return b
	else:
		hasilGCD = gcdExtended(b%a, a)
		x1 = y - (b//a)*x
		y1 = x
		x = x1
		y = y1
		return hasilGCD

def findSolution(a, b, c):
	global x,y
	gcd = gcdExtended(abs(a), abs(b))
	if(c%gcd != 0):
		return False
	else:
		x*=(c//gcd)
		y*=(c//gcd)

		if(a<0):
			x = -x
		if(b<0):
			y = -y
		return True

while True:
	line = input();
	if line == "0 0 0 0":
		break
	# n,m,a,k = line
	listBil = []
	bil = 0
	for i in line:
		if(i == ' '):
			listBil.append(bil)
			bil = 0
		else:
			bil*=10
			bil+=int(i)
	listBil.append(bil)
	n = listBil[0]
	m = listBil[1]
	a = listBil[2]
	k = listBil[3]

	if(m==0 and a==0):
		print("Impossible")
		continue

	selisih = a+k-n
	if(findSolution(m,-a,selisih)):
		ans = gcd(a,m)
		pengali = (y*ans) // m
		xJawaban = x+pengali*(-a//ans)
		jawab1 = n+m*xJawaban
		print(jawab1)
	else:
		print("Impossible")
	# print(n, m, a, k)
	# print(line)