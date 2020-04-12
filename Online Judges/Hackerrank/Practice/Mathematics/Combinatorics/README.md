### Things learnt
1. Merge List
	- Firstly, I tried to approach this problem using Math. But I couldn't find a way because there are no math tricks and the number of combination of events is so huge and it is impossible to approach it with a single math equation
	- Then, looking at the constraint of N and M, the highest value is only 100, then DP approach come to mind as this problem has characteristic: have subproblem to solve.
	- Formula: dp[i][j] = dp[i-1][j] + dp[i][j-1]. That is the formula because in one action, we can take one element from first list or second list, and we can sum the events from 2 actions here.
	- The second solution: it turns out that it is indeed a basic combin problem. The problem can be simplify as how many arrangement for N + M objects with N objects is different with the M objects. The solution is C(N+M, N) or C(N+M, M)
2. Consecutive Subsequences
	- The problem is to find the subarray with sum divisible by k
	- There are 2 solutions:
		1. Solution 1
			- Observation: 
				1. Since k is small (only 100), we will only need to care about the count of prefix sum elements with value of pref[i], and we care about the value pref[i] % k = i. We maintain the count of the element, let's say in array cnt. 
				2. If an element % k = x, and the element is substracted by a number y, then all elements with the modulo operation (element % k == x) will altogether be element % k == (x - y) % k, so the count value is moved to the new index in the array. We can do left shift operation
			- We can substract each element in the front, thus will decrease all the value of the prefix sum, and we do left shift of count array elements based on the observation.
			- The thing that we most care is cnt[0], since we will add the value of this to the answer for each substraction of element in the original array.  
		2. Solution 2
			- Observation:
				1. Getting the value a[i] + a[i+1] + ... + a[j] is done by pref[j] - pref[i-1]. If we want to get (a[i] + ... + a[j]) % k = 0, then (pref[j] - pref[i-1]) % k == 0. Hence, the value of pref[j] should be the same with pref[i-1] in order to get the value (pref[j] - pref[i-1]) % k == 0
				2. So, we do prefix sum and we store the value pref[i] % k in count array of size k, and we add count[pref[i] % k] by 1, don't forget to first add count[0] = 1, this is some kind of for pref[-1] = 0, and we can get the value of a[0] + .. + a[i] by pref[i] - 0.
				3. Sum (count[i] * (count[i]-1))/2

3. Coinage
	- If we are dealing with finite number of coins, then in order to get the value N using the finite number of coins, we can use bruteforce with pruning
	- The idea is, we should iterate the largest denomination first since it will make the iteration faster, then we break from the iteration if the total value is already exceeding N. This is pruning. We can use 3 largest denomination, and decide whether the we can make N with the smallest coin. This approach is having complexity: O(B*C*D)
	- The alternative solution is to precompute the 2 smallest denomination, we iterate all possibilities and we use map / array to maintain the count. Then we can iterate using 2 nested for loops for the 2 largest denomination, then we use the count array. Complexity: O(max(A*B), max(C*D)). This is a better solution.
		