tc = int(input())
for i in range(tc):
	n = int(input())
	s1 = input()
	s2 = input()
	isBad = False
	for i in range(n):
		isBad |= s1[i] == '1' and s2[i] == '1'

	if(isBad):
		print("NO")
	else:
		print("YES")