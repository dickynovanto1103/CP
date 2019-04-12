def subarrayBitwiseOR(A): 
  
    # res contains distinct values 
    res = set() 
  
    pre = {0} 
  
    for x in A: 
        pre = {x | y for y in pre} | {x} 
        res |= pre 
  
    return len(res) 
  
  
# Driver program 
tc = int(input())
while(tc > 0):
	n = int(input())
	A = map(int, input().split(' '))

	print(subarrayBitwiseOR(A)) 
	tc -= 1