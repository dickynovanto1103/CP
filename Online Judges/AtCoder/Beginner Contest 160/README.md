### Editorial
1. [Coffee](https://atcoder.jp/contests/abc160/tasks/abc160_a)
	- Simple if
2. [Golden Coins](https://atcoder.jp/contests/abc160/tasks/abc160_b)
	- Because of the ratio: 1000 happiness per 500 coins, and 5 happiness per 5 coins, then the greedy approach to subtract by 500 coins first should be true
	- Just divide by 500, then divide by 5
3. [Traveling Salesman around Lake](https://atcoder.jp/contests/abc160/tasks/abc160_c)
	- Need to know the shortest way to visit all house starting from a certain house
	- Obvious: we can do N^2 algo, from a certain house, do iteration until n houses is visited. But certainly, it will be TLE
	- We can find diff for each consecutive, and we find the max diff, then subtract the perimeter with the diff
4. [Line++](https://atcoder.jp/contests/abc160/tasks/abc160_d)
	- Just BFS for each vertex to the other vertices
5. [Red and Green Apples](https://atcoder.jp/contests/abc160/tasks/abc160_e)
	- Since we need to pick X red apple and Y green apple and maximizing the value, then we must examine each of the uncolored apple to replace the red / green apples
	- We can use priority queue, we compare the min(min(red), min(blue)) with the value of uncolored apple, if the value of uncolored apple is greater, then we can replace the min value in either red / green apple
	- This way, we can maximize the total value in the end, because we have already replaced the minimum value with the greater value.
6. [Distributing Integers](https://atcoder.jp/contests/abc160/tasks/abc160_f)
	- This is a rather complex problem. The problem is, for each vertex, we need to get the number of way to write number from 1 to N in N vertices, started from number 1 in vertex i, then one of the neighbor randomly, an so on until number N is written
	- Let's approach this problem step by step
	- Let's say we want to solve this problem for each vertex. So we expect a solution with a complexity of O(N^2), because we do full tree traversal for each initial vertex
		- Let's say we focus on vertex 1, the number of way to write N number with vertex 1 is numbered 1 is ((subtreeSize[1]-1)! / mul(subtreeSize(son[1]))) * mul(dp[son[1]])
		- Let's disect this formula
		- ((subtreeSize[i] - 1))! / mul(subtreeSize(son[i])) 
			- This formula depicts how many way to arrange subtreeSize[i] - 1 objects with the number of unique object is the number of son of node i. 
			- It's like how many ways to merge K lists into 1 list of objects and in each of the list contains the same kind of object, and in total there is K unique kind of objects
			- xxxoooeee --> how many ways to arrange this = 9! / 3! 3! 3!
			- Each list represents ONE way to do valid arrangement of number with the root of subtree is son[i]
			- So this part is to calculate the number of valid interleaving number for K lists
		- mul(dp[son[i]])
			- Because in each son[i], there can be dp[son[i]] way to do number arrangement, then we must multiply each possibility of arrangement with the other possibility arrangement of the other son of i.
		- We can say that we can solve this for one root. How can we solve it if the N = 1e5?
	- Observation:
		- We can do rerooting from root to its neighbor, as doing rerooting to its neighbor will only affect 2 DP values and 2 subtreeSize values (initial root and new root).
		- Why only 2 values that change? Notice that when we root at node i, the parent of i is null (we can define it as -1), when we reroot to its neighbor, let's say j, then the dp[j] will change as j initially has parent i but now it should be -1, and the parent of i becomes j because j is now the root, and the value of DP and subtreeSize of the other nodes remain the same. This way we can do O(1) operation in each rerooting operation hence we can get O(N) complexity
		- We must get the value of the dp[i][j] first --> the number of way of number arrangement with i as the root and the parent of i is j.
		- We notice the transition formula of dp[i][j] = (dp[i][-1] / dp[j][i]) * ((sz[i]-sz[j]-1)! / (sz[i]-1)!) * sz[j]!
			- We can get the formula since we don't need dp[j][i] anymore from dp[i][-1] and when we do rerooting, we know that the value of sz[i] is substracted with sz[j] when we do rerooting, and -1 since we will disregard i as the root of the subtree, and we divide by (sz[i]-1)! since we don't need this value from the dp[i][-1] and we need to multiply the value with sz[j]! since in dp[i][-1], we divide with sz[j]!, so we need to multiply this value to cancel the division
		- Then the dp[j][-1] becomes easier to compute since dp[i][j] has been computed, and the other dp values of j's neighbors hasn't been changed
		- So the total complexity: O(V + E)


