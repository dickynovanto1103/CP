### Things learnt
1. Merge List
	- Firstly, I tried to approach this problem using Math. But I couldn't find a way because there are no math tricks and the number of combination of events is so huge and it is impossible to approach it with a single math equation
	- Then, looking at the constraint of N and M, the highest value is only 100, then DP approach come to mind as this problem has characteristic: have subproblem to solve.
	- Formula: dp[i][j] = dp[i-1][j] + dp[i][j-1]. That is the formula because in one action, we can take one element from first list or second list, and we can sum the events from 2 actions here.
	- The second solution: it turns out that it is indeed a basic combin problem. The problem can be simplify as how many arrangement for N + M objects with N objects is different with the M objects. The solution is C(N+M, N) or C(N+M, M)
2. Consecutive Subsequences
	- The problem is to find the subarray with sum divisible by k
	- Observation: 
		1. Since k is small (only 100), we will only need to care about the count of prefix sum elements with value of pref[i], and we care about the value pref[i] % k = i. We maintain the count of the element, let's say in array cnt. 
		2. If an element % k = x, and the element is substracted by a number y, then all elements with the modulo operation (element % k == x) will altogether be element % k == (x - y) % k, so the count value is moved to the new index in the array. We can do left shift operation
	- We can substract each element in the front, thus will decrease all the value of the prefix sum, and we do left shift of count array elements based on the observation.
	- The thing that we most care is cnt[0], since we will add the value of this to the answer for each substraction of element in the original array. 