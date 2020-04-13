### Editorial
1. [ABC Swap](https://atcoder.jp/contests/abc161/tasks/abc161_a)
	- just swap
2. [Popular Vote](https://atcoder.jp/contests/abc161/tasks/abc161_b)
	- compute total, compute 1/4m, consider the floor operation correctly, then just iterate
3. [Replacing Integer](https://atcoder.jp/contests/abc161/tasks/abc161_c)
	- Just compute n%k, then compare n%k with abs(n%k - k), find minimum
4. [Lunlun Number](https://atcoder.jp/contests/abc161/tasks/abc161_d)
5. [Yutori](https://atcoder.jp/contests/abc161/tasks/abc161_e)
	- This is an interesting problem
	- To know which day is the must working day, we must know the definition of must working day
	- Definition of must working day is that the x-th working day cannot be later dan the day or earlier than the day
	- So we must know the earliest[x] = the earliest day of the x-th working day, and latest[x] = the latest day of the x-th working day
	- we can get the 2 values by greedy approach from beginning and from the end of the array. Then just print the result that satisfy this: earliest[x] == latest[x]
6. [Division or Subtraction](https://atcoder.jp/contests/abc161/tasks/abc161_f)
	- The observation here is to divide the problem into 2.
		- for k divides N, we must find the divisors of N, O(sqrt(N)). If at the end it does not equal to 1, then we just need to do mod the remaining N after each divison with k, if it can result in 1, then it is the answer.
		- for k does not divide N, and N is replaced with N-k, then we know that N-k congruency is still the same no matter how many operations is done. Hence, to know the number of k that can make N become 1, we have this formula:
			- n - xk = 1 is the same with:
			- n - 1 = xk
			- so we got n, and we can get all the divisors of n-1,

