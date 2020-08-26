# Editorial
1. Problem C
	- Interesting problem
	- Important observation, this item should be removed if e[i] + r[i] > SUM, SUM = sum of all e[i]
	- When we are given task to determine the min number of removed item to satisfy something..consider DP / greedy approach
	- In this approach, we can try to insert the toy one by one from the beginning, if in an index there is a violation, then we can try to remove the toys that has biggest e[i] + r[i] first.
		- Reason: if we remove toys with smaller e[i] + r[i], then it might not be optimal and the toy with biggest e[i] + r[i] will still be violated if we remove the smaller one
	- If in the end, we still have >= 1 toy, then we can play it indefinitely, else we can only play it finitely.
	- We can use priority queue
	- We can track the current time now, cur sum, number of toys removed..keep track..when we got the cur sum maxed, we note the answer and the cnt needed