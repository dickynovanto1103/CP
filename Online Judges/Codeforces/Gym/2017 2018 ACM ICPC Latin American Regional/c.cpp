#include <bits/stdc++.h>

using namespace std;

bool check(vector<pair<int, int>> &cnt) {
	bool valid = true;
	for (int i = 2; i <= cnt.size() - 1; i++) {
		if (cnt[i].first != cnt[i - 1].first) {
			valid = false;
		}
	}
	return valid;
}

int main() {
	int k, n;
	scanf("%d %d", &k, &n);

	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}

	vector<pair<int, int>> cnt(k + 1);
	for (int i = 1; i <= k; i++) {
		cnt[i] = {0, i};
	}
	for (int i = 0; i < n; i++) {
		int v = cnt[a[i]].first;
		cnt[a[i]] = {v + 1, a[i]};
	}
	sort(cnt.begin(), cnt.end());

	cnt[1].first += 1;
	if (check(cnt)) {
		printf("+%d\n", cnt[1].second);
		return 0;
	}
	cnt[1].first -= 1;

	cnt[k].first -= 1;
	if (check(cnt)) {
		printf("-%d\n", cnt[k].second);
		return 0;
	}
	cnt[k].first += 1;

	cnt[k].first -= 1;
	cnt[1].first += 1;
	if (check(cnt)) {
		printf("-%d +%d\n", cnt[k].second, cnt[1].second);
		return 0;
	}

	printf("*\n");

	return 0;
}