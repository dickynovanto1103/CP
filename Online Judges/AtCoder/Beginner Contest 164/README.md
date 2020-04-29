# Editorial
1. [A - Sheep and Wolves](https://atcoder.jp/contests/abc164/tasks/abc164_a)
	- Just if
2. [B - Battle](https://atcoder.jp/contests/abc164/tasks/abc164_b)
	- Simulation
3. [C - gacha](https://atcoder.jp/contests/abc164/tasks/abc164_c)
	- Use map and increment if the string is not found
4. [D - Multiple of 2019](https://atcoder.jp/contests/abc164/tasks/abc164_d)
	- This is an interesting problem
	- The important observation that we need to get is 2019 % 2 != 0 and 2019 % 5 != 0. So from this property, we know that for an integer x, if x * 10^y = 0 (mod 2019), then x = 0 (mod 2019) as well.
	- How to get the value of (x * 10^y) % 2019 = 0? Mod[i] = the value constructed from digit i to n-1 then mod 2019, so when we encounter Mod[i] == Mod[j] with i < j, then we can subtract the val[i] - val[j] to get x * 10^y, then x * 10^y % 2019 must be 0 since they have same Mod.
	- So for this, we keep the frequency of Mod[i], and we just sum the count with the handshake combination property (n * (n-1)) / 2.