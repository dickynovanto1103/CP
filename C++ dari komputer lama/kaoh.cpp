#include <bits/stdc++.h>

using namespace std;

int cnt[105][105];
int dp[105][105];

int find(int i, int j) {
  if (i == 0 || j == 0) return 0;
  if (dp[i][j] != -1) return dp[i][j];
  return dp[i][j] = max(find(i, j - 1), find(i - 1, j)) + cnt[i][j];
}

int main() {
  int n;
  scanf("%d", &n);
  while (n) {
    memset(cnt, 0, sizeof(cnt));
    
    for (int i = 0; i < n; i++) {
      int a, b;
      scanf("%d %d", &a, &b);
      cnt[a][b]++;
    }
    memset(dp, -1, sizeof(dp));
    int ans = 0;
    for (int i = 0; i <= 100; i++) {
      for (int j = 0; j <= 100; j++) {
        ans = max(ans, find(i, j));
      }
    }
    printf("%d\n", ans);
    
    scanf("%d", &n);
  }
  puts("*");
  return 0;
}