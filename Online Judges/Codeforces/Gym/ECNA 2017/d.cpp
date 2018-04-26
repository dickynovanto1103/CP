#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k;
	scanf("%d %d", &n, &k);

	string s;
	stack<int> st;
	st.push(0);
	for (int i = 0; i < k; i++) {
		cin >> s;
		if (s == "undo") {
			int m;
			cin >> m;

			while (m--) {
				st.pop();
			}
		} else {
			int m = stoi(s);

			int x = (st.top() + m) % n;
			if (x < 0) {
				x += n;
			}
			st.push(x);
		}
	}

	cout << st.top() << '\n';
}