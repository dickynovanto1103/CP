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

bool found;

void printVector(vi v) {
	for(int x: v){
		printf("%d ", x);
	}
	puts("");
}

bool isAllZero(vi v) {
	// printVector(v);
	for(auto x: v) {
		if(x != 0){return false;}
	}
	return true;
}

void search(int n, vi v, vi ans = {}, int pangkat = 0) {
	if(found) return;
	int range = 1<<pangkat;
	if(range > n){return;}
	int i,j;
	// printf("pangkat: %d ans length: %d\n", pangkat, ans.size());
	for(i=0;i<n;i++){
		if(i + range - 1 >= n) {
			break;
		}
		ans.pb(i);
		// printf("push idx: %d ke pangkat: %d\n", i, pangkat + 1);
		vi temp = v;
		for(j=i;j<i+range;j++){
			v[j] = 1 - v[j];
		}
		if(isAllZero(v)){
			found = true;
			printf("found, length: %d\n", ans.size());
			for(auto x: ans){
				printf("%d ", x + 1);
			}
			puts("");
			return;
		}
		
		search(n, v, ans, pangkat+1);
		v = temp;
		ans.pop_back();
	}
}

int main(){
	int n;
	scanf("%d",&n);
	vi v(n);
	found = false;
	for(int i=0;i<n;i++){
		v[i] = 1;
	}

	search(n, v);
	
	return 0;
};