#include <bits/stdc++.h>

using namespace std;

vector<int> reverse(vector<int> v) {
	vector<int> result;
	
	for(int i=v.size() - 1; i >= 0; i--) {
		result.push_back(v[i]);
	}
	return result;
}

int main() {
	vector<int> v = {1, 2, 3, 4, 5};

	vector<int> reversedVector = reverse(v);
	for (int i = 0; i < reversedVector.size(); i++) {
		printf("%d ", reversedVector[i]);
	}
	printf("\n");
	return 0;
}