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

