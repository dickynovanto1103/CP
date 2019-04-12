from math import log2

a, b =input().split(' ')

if(log2(int(a)) > int(b)):
	print("You will become a flying monkey!")
else:
	print("Your wish is granted!")
