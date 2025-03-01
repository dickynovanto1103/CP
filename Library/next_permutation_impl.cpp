#include <bits/stdc++.h>

using namespace std;

void printVector(vector<int> v) {
	for(int el: v) {
		printf("%d ", el);
	}
	puts("");
}

int findIdxSmaller(vector<int> v) {
	int idxSmaller = -1;
	int len = v.size();
	for(int i=len-2;i >= 0; i--) {
		if(v[i] >= v[i+1]) {
			continue;
		}
			
		idxSmaller = i;
		break;
	}

	return idxSmaller;
}

bool hasNextPermutation(int idxSmaller) {
	return idxSmaller != -1;
}

int findNextSmallestIdx(int idxSmaller, vector<int> v) {
	int valBenchmark = v[idxSmaller];
	int len = v.size();
	int nextMinVal;
	int nextSmallestIdx = -1;
	for(int i=idxSmaller + 1; i < len; i++) {
		if(valBenchmark >= v[i]) {
			break;
		}

		nextMinVal = v[i];
		nextSmallestIdx = i;
	}

	return nextSmallestIdx;
}

void generateAllPermutations(vector<int> v) {
	//assume the vector v is already sorted

	int len = v.size();
	while(true) {
		printVector(v);
		//find first idx = i from right in which v[i] < v[i+1];
		//after finding this, it means that the right of v[i+1], v[i+2], ..., v[len-1] is monotonically decreasing.
		int idxSmaller = findIdxSmaller(v);

		if (!hasNextPermutation(idxSmaller)) {break;} //no more next permutation
		//find idx in which v[idxSmaller] < v[j], idxSmaller + 1 <= j < len, and v[j] is the smallest but still v[j] > v[idxSmaller]
		int nextSmallestIdx = findNextSmallestIdx(idxSmaller, v);

		//just asserting for debugging purpose, to make sure this condition is fulfilled
		assert(nextSmallestIdx >= 0 && nextSmallestIdx < len);

		//swap
		swap(v[idxSmaller], v[nextSmallestIdx]);

		//from v[idxSmaller + 1] to v[len-1], it is still monotonically decreasing. So we reverse it to get the smallest 
		reverse(v.begin() + idxSmaller + 1, v.end());
	}
}

int main() {
	int n;
	while(scanf("%d",&n) != EOF) {
		vector<int> v(n);
		for(int i=0;i<n;i++){
			scanf("%d",&v[i]);
		}

		printf("generate all permutations\n");
		generateAllPermutations(v);
	}

	return 0;
}
