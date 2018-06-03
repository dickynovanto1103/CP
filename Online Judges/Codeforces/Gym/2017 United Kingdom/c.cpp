#include <bits/stdc++.h>

using namespace std;

map<string, int> cv;

int main() {
	int n;
	scanf("%d", &n);

	cv["black"] = 7;
	cv["pink"] = 6;
	cv["blue"] = 5;
	cv["brown"] = 4;
	cv["green"] = 3;
	cv["yellow"] = 2;

	int red = 0;
	vector<int> colors;
	while (n--) {
		string color;
		cin >> color;

		if (color == "red") {
			red++;
		} else {
			colors.push_back(cv[color]);
		}
	}

	sort(colors.rbegin(), colors.rend());

	int result = red;

	if (colors.size() > 0) {
		result += (red + 1) * colors[0];
	} else{
		printf("1\n");
		return 0;
	}

	for (size_t i = 1; i < colors.size(); i++) {
		result += colors[i];
	}

	printf("%d\n", result);
}