### Things learnt
1. Merge List
	- Firstly, I tried to approach this problem using Math. But I couldn't find a way because there are no math tricks and the number of combination of events is so huge and it is impossible to approach it with a single math equation
	- Then, looking at the constraint of N and M, the highest value is only 100, then DP approach come to mind as this problem has characteristic: have subproblem to solve.
	- Formula: dp[i][j] = dp[i-1][j] + dp[i][j-1]. That is the formula because in one action, we can take one element from first list or second list, and we can sum the events from 2 actions here.
	- The second solution: it turns out that it is indeed a basic combin problem. The problem can be simplify as how many arrangement for N + M objects with N objects is different with the M objects. The solution is C(N+M, N) or C(N+M, M)