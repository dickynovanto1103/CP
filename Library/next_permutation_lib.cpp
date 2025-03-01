#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	scanf("%d",&n);

	vector<int> v(n);
	for(int i=0;i<n;i++){
		v[i] = i;
	}

	do {
		for(int el: v) {
			printf("%d ", el);
		}
		puts("");
	}while(next_permutation(v.begin(), v.end()));

	return 0;
}