#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;

	// <pos, <index, begin?>>
	vector<pair<int, pair<int, bool>>> minions;
	for (int i = 0; i < n; ++i) {
		int begin, end;
		cin >> begin >> end;

		minions.push_back({begin, {i, true}});
		minions.push_back({end + 1, {i, false}});
	}
	sort(minions.begin(), minions.end());

	set<int> alive;
	for (int i = 0; i < n; i++) {
		alive.insert(i);
	}

	int ans = 0;
	
	while (!alive.empty()) {
		int maxi = 0;
		set<int> current, maxs;

		for (int i = 0; i < 2 * n; i++) {
			int pos = minions[i].first;
			int id = minions[i].second.first;
			bool begin = minions[i].second.second;

			if (alive.count(id) == 0) {
				continue;
			}

			if (begin) {
				current.insert(id);
			} else {
				current.erase(id);
			}

			// if (i + 1 < 2 * n && minions[i + 1].first == pos) {
			// 	continue;
			// }

			if (current.size() > maxi) {
				maxi = current.size();
				maxs = current;
			}
		}

		ans++;
		for (auto it = maxs.begin(); it != maxs.end(); it++) {
			alive.erase(*it);
		}
	}

	cout << ans << endl;
}