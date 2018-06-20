n = input()
k = input()

dp = [[-1 for x in range(2)] for y in range(1801)]
dp[int(n)][1] = int(k)-1;
dp[int(n)][0] = int(k);

for i in range(int(n)-1, 0, -1):
	dp[i][1] = (int(k)-1)*dp[i+1][0]
	dp[i][0] = (int(k)-1)*dp[i+1][0] + dp[i+1][1]

print(dp[1][1])