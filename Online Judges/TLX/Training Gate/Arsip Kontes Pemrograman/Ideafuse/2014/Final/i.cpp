#include <bits/stdc++.h>

using namespace std;

int main() {
	int t, tc = 0;
	scanf("%d", &t);

	while (t--) {
		long long sum = 0;

		int a, b;
		scanf("%d %d", &a, &b);

		vector<int> as, bs;
		while (a > 0) {
			as.push_back(a);
			a /= 2;
		}
		while (b > 0) {
			bs.push_back(b);
			b /= 2;
		}

		int i = as.size() - 1;
		int j = bs.size() - 1;

		bool pass = false;
		while (i >= 0 && j >= 0 && as[i] == bs[j]) {
			i--;
			j--;
			pass = true;
		}
		if (pass) {
			sum += as[i + 1];
		}

		while (i >= 0) {
			sum += as[i];
			i--;
		}
		while (j >= 0) {
			sum += bs[j];
			j--;
		}


		printf("Case #%d: %lld\n", ++tc, sum);
	}
}