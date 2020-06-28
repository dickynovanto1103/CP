Problem F
1. This is interesting problem
2. We must know this property of 2 numbers: a and b
	- sum = a + b
	- xor = a ^ b
	- A = a & b
	- sum = xor + 2 x A
3. We can get the value of a and b by knowing the value of (a & b) and (a ^ b)
4. Beware of some cases
	- sum - xor can be odd, therefore to get A, we must do: `(sum - xor + 1) / 2`
	- sum < xor, must handle this case as well. This case can happen if a[3]^a[4]^...^a[n] > (a[1] ^ a[2]).
	- These cases should not happen if xor is got from a and b only