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

void solve(){
	int n;
	scanf("%d",&n);
	int a[100];
	int count[100] = {}, output[100] = {};
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		count[a[i]]++;
		printf("count[%d]: %d\n", a[i], count[a[i]]);
	}

	for(int i=0;i<100;i++){
		count[i] = count[i-1] + count[i];
		printf("count[%d]: %d\n", i, count[i]);
	}

	for(int i=n-1;i>=0;i--){
		output[--count[a[i]]] = a[i];
	}
	
	for(int i=0;i<n;i++){
		printf("%d ",output[i]);
	}
	puts("");
}

int main(){
	int tc = 1;
	// scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};