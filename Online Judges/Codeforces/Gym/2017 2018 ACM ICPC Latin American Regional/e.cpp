#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define ll long long
#define ve vector
#define pq priority_queue
#define um unordered_map
#define us unordered_set

#define pii pair<int, int>
#define pll pair<ll, ll>

int modz(int d, int e, int n) {
	int res = d % n;
	for (int i = 0; i < e; i++) {
		res = (res * 10) % n;
	}
	return res;
}

int main() {
	string s;
	int n;
	cin >> s >> n;


	if (s.size() == 1) {
		if (s[0] == '?' && n < 10) {
			printf("%d\n", n);
		} else {
			if ((s[0] - '0') % n == 0 && n < 10) {
				printf("%d\n", s[0] - '0');
			} else {
				printf("*\n");
			}
		}
		return 0;
	}

	reverse(s.begin(), s.end());

	ve<ve<int>> dg(s.size(), ve<int>(n, INT_MAX));
	ve<ve<int>> pr(s.size(), ve<int>(n));

	ve<ve<bool>> dp(s.size(), ve<bool>(n, false));
	if (s[0] == '?') {
		for (int i = 0; i < min(10, n); i++) {
			dp[0][i] = true;
			dg[0][i] = i;
		}
	} else {
		dp[0][(s[0] - '0') % n] = true;
		dg[0][(s[0] - '0') % n] = s[0] - '0';
	}

	for (int i = 1; i < s.size(); i++) {
		bool cont = true;
		for (int d = (i == s.size() - 1 ? 1 : 0); d < 10 && cont; d++) {
			if (s[i] != '?' && (s[i] - '0' != d)) {
				continue;
			}

			int rem = modz(d, i, n);
			for (int j = 0; j < n; j++) {
				if (dp[i - 1][j]) {
					int remm = (rem + j) % n;
					dp[i][remm] = true;

					if (d < dg[i][remm]) {
						dg[i][remm] = d;
						pr[i][remm] = j;
					}

					// cont = false;
					// break;
				}
			}
		}
	}

	if (!dp[s.size() - 1][0]) {
		cout << '*' << endl;
		return 0;
	}


	printf("%d", dg[s.size() - 1][0]);
	int j = pr[s.size() - 1][0];
	for (int i = s.size() - 1; i >= 1; i--) {
		printf("%d", dg[i - 1][j]);
		j = pr[i - 1][j];
	}
	printf("\n");

	return 0;
}