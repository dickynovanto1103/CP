#include <bits/stdc++.h>

using namespace std;

int containers[400][400];

int minSwaps(int arr[], int n)
{
    // Create an array of pairs where first
    // element is array element and second element
    // is position of first element
    pair<int, int> arrPos[n];
    for (int i = 0; i < n; i++)
    {
        arrPos[i].first = arr[i];
        arrPos[i].second = i;
    }
 
    // Sort the array by array element values to
    // get right position of every element as second
    // element of pair.
    sort(arrPos, arrPos + n);
 
    // To keep track of visited elements. Initialize
    // all elements as not visited or false.
    vector<bool> vis(n, false);
 
    // Initialize result
    int ans = 0;
 
    // Traverse array elements
    for (int i = 0; i < n; i++)
    {
        // already swapped and corrected or
        // already present at correct pos
        if (vis[i] || arrPos[i].second == i)
            continue;
 
        // find out the number of  node in
        // this cycle and add in ans
        int cycle_size = 0;
        int j = i;
        while (!vis[j])
        {
            vis[j] = 1;
 
            // move to next node
            j = arrPos[j].second;
            cycle_size++;
        }
 
        // Update answer by adding current cycle.
        ans += (cycle_size - 1);
    }
 
    // Return result
    return ans;
}

bool impossible(int l, int c) {
	for (int j = 0; j < c; j++) {
		int curNomorKolom = containers[0][j] % c;
		for (int i = 1; i < l; i++) {
			int nomorKolom = containers[i][j] % c;
			if(curNomorKolom != nomorKolom) {return true;}
		}
	}

	for(int i = 0; i < l; i++) {
		int curNomorBaris = (containers[i][0]-1) / c;
		for(int j = 1; j < c; j++) {
			int nomorBaris = (containers[i][j] - 1) / c;
			if(curNomorBaris != nomorBaris) {return true;}
		}
	}

	return false;
}

int main() {
	int l, c;
	cin >> l >> c;

	for (int i = 0; i < l; i++) {
		for (int j = 0; j < c; j++) {
			cin >> containers[i][j];
		}
	}

	if (impossible(l, c)) {
		printf("*\n");
		return 0;
	}

	int result = minSwaps(containers[0], c);
	for (int i = 0; i < l; i++) {
		sort(containers[i], containers[i] + c);
	}

	int temp[l];
	for (int i = 0; i < l; i++) {
		temp[i] = containers[i][0];
	}
	result += minSwaps(temp, l);

	printf("%d\n", result);
}

