### Editorial
1. Problem A (Allocation)
	- Just a very simple greedy problem: we need to build as many building as possible (N building with each building cost is provided), we have B budget
	- Just sort and buy from the cheapest and count++
2. Problem B (Plates)
	- This problem is picking plates in a stack, with condition if we pick one of the plate in the middle / bottom, we must pick all of the plates on top of the plate picked. We must pick exactly P plates. Each plate has a beauty. We want to maximize the beauty.
	- This is DP Problem. dp[i][j][remP] is the max beauty if we consider picking plates until row i and col j, and the remaining P is remP
	- dp[i][j][remP] = max(a[i][j] + dp[i][j+1][remP - 1], dp[i+1][0][remP]) --> either we pick the plate or we stop picking and move to the next row
3. Problem C (Workout)
	- The problem is that there is a strictly increasing array containing N elements, and we can fill the array with up to K positive integer numbers such that the N + (up to) K elements in the array is still strictly increasing. We want to minimize the max difference between each 2 consecutive elements in the array
	- First Approach (AC small TC, WA big TC):
		- Put the diffs in priority queue with the largest element is on top
		- In each element on the top of the priority queue...just divide by 2...get ceil(diff/2) and floor(diff/2), push the 2 elements back to pq and after k operations, just print pq.top()
		- This is correct for K = 1, for K > 1, it is wrong, e.g. k=2, N=2, arr=[1,10], if using the approach, the ans = 5, should be able to produce 3 -->[1, 4, 7, 10] instead of [1, 3, 5, 10]
	- Second Approach (more correct, however still AC small TC, WA big TC):
		- Realizing that if k=2, N=2, arr = [1,10] can result ans = 3 instead of 5, then the way to approach this problem must be changed.
		- Idea:
			1. If pq.size() == 1, we do our best by add k elements inside the 2 elements in array --> optimal
			2. else, then we should compare diff1 and diff2 with diff1 >= diff2. We want to separate diff1 to be smaller than diff2 and then we do this until k = 0. We can divide it using dividing a number. e.g. 4 divided by 3 --> [2, 1, 1]
		- The problem with the idea is: if we divide the diff1 until smaller than diff2, then it could be too much of division and all k left will not be sufficient to produce the optimal solution.
	- Third Approach (AC):
		- We can binary search the answer. We divide the diff to produce vector / array that contains elements <= the answer (mid). 
		- If we can do this, try smaller answer. else try bigger number
		- This is correct because we can guarantee that in each guessing the answer, we will not over-dividing the diff number as the only goal is to get to the answer (mid).
4. Problem D (Bundling)
	- The problem is that we need to group N strings into N/K groups with each group having K strings. We need to maximize the score of longest matching prefix in total from each group.
	- This problem is solved after the contest time, during the contest time, I tried a bunch of ideas, but none seems to work as I always thought how to assign a particular string into a group and something like maxflow surely doesn't work
	- The solution for this problem turns out to be quite simple. We just need to count how many prefix Pi is in the string list and then just increase the answer with floor(count(Pi) / k) as we only want to group with k elements.
	- Important observation:
		- Let's say we have string A: DICKY and string B: DIKI, the longest prefix is DI and it brings value 2. 
		- Instead of directly determining value 2 (thus directly determining that string A and B should be on a same group which is still undeterministic), we just count D and DI separately. 
		- The value 2 comes from 1 + 1 anyway, so we can just count the number of strings that contains D as prefix, and the number strings that have DI as their prefix.
	- For small constraint: we can directly put the string prefixes into hash map (space complexity: O(N * 5 * 5))
	- For big constraint: 
		- we can hash the prefix of the string and add counter using map
		- we can create trie and maintain the count in each node for further query.
	