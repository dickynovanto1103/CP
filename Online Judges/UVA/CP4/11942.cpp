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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define debug if(true)
typedef long long ll;
// typedef __int128_t lll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

bool isSortedDecreasing(int arr[], int size) {
	for(int i=0;i<size-1;i++){
		if(arr[i] < arr[i+1]) {
			return false;
		}
	}

	return true;
}

bool isSortedIncreasing(int arr[], int size) {
	for(int i=0;i<size-1;i++){
		if(arr[i] > arr[i+1]) {
			return false;
		}
	}

	return true;
}

void solve(){
	int arr[11];
	for(int i=0;i<10;i++){
		scanf("%d",&arr[i]);
	}
		

	if(isSortedDecreasing(arr, 10) || isSortedIncreasing(arr, 10)) {
		puts("Ordered");
	}else{
		puts("Unordered");
	}
}

int main(){
	int tc = 1;
	scanf("%d",&tc);
	puts("Lumberjacks:");
	while(tc--){
		solve();
	}

	return 0;
};