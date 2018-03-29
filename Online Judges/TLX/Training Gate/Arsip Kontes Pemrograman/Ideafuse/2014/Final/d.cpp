#include <bits/stdc++.h>

using namespace std;

bool isVowel(int c) {
	return c == 'A' || c == 'I' || c == 'U' || c == 'E' || c == 'O';
}

bool isConsonant(int c) {
	return !isVowel(c);
}

int main() {
	int t, tc = 0;
	cin >> t;

	while (t--) {
		string s;
		cin >> s;

		int hardness = 0;

		for (int i = 0; (i + 1) < s.size(); i++) {
			// NT
			if (isConsonant(s[i]) && isConsonant(s[i + 1])) {
				hardness += 1;
			}
		}

		for (int i = 0; (i + 2) < s.size(); i++) {
			// AIA
			if (isVowel(s[i]) && isVowel(s[i + 1]) && isVowel(s[i + 2])) {
				hardness += 1;
			}
		}

		if (hardness) {
			printf("Case #%d: %d\n", ++tc, hardness);
		} else {
			printf("Case #%d: EASY\n", ++tc);
		}
	}
}