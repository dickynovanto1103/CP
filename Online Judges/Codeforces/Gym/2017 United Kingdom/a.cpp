#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define mp make_pair
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

typedef struct {
	int length;
	int sunrise;
	int sunset;
} day;

int main() {
	int n;
	scanf("%d", &n);

	vector<day> planets(n);
	int maxlength = INT_MIN;
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &planets[i].length, &planets[i].sunrise, &planets[i].sunset);
		maxlength = max(maxlength, planets[i].length);
	}

	vector<vector<bool>> hours(n, vector<bool>(1825 * maxlength));

	for (int j = 0; j < n; j++) {
		int length = planets[j].length;
		int sunrise = planets[j].sunrise;
		int sunset = planets[j].sunset;

		bool night = sunrise < sunset;

		for (size_t i = 0; i < hours[j].size(); i++) {
			if (i % length == sunset) {
				night = true;
			}

			hours[j][i] = night;

			if (i % length == sunrise) {
				night = false;
			}
		}
	}

	// for (int j = 0; j < n; j++) {
	// 	for (size_t i = 0; i < 20; i++) {
	// 		if (hours[j][i]) {
	// 			printf("1 ");
	// 		} else {
	// 			printf("0 ");
	// 		}
	// 	}
	// 	printf("\n");
	// }

	for (size_t i = 0; i < hours[0].size(); i++) {
		int allnight = true;

		for (int j = 0; j < n; j++) {
			if (!hours[j][i]) {
				allnight = false;
				break;
			}
		}

		if (allnight) {
			printf("%lu\n", i);
			return 0;
		}
	}

	printf("impossible\n");

	return 0;
}