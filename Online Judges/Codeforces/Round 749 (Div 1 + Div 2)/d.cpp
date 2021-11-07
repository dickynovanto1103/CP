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

int getLastElement(int n) {
	int cnt = 0;
	int i,j;
	for(i=n;i>=2;i--){
		printf("?");
		for(j=0;j<n-1;j++){
			printf(" %d", 1);
		}
		printf(" %d\n", i);
		fflush(stdout);
		int ans;
		scanf("%d",&ans);
		if(ans != 0) {
			cnt++;
		}
	}
	return n - cnt;
}

int getIdxOfIWithLastQuery(int awal, int lastQuery, int n) {
	printf("?");
	for(int i=0;i<n-1;i++){
		printf(" %d", awal);
	}
	printf(" %d\n", lastQuery);
	fflush(stdout);
	int idx;
	scanf("%d",&idx);
	assert(idx > 0);
	return idx;
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	int lastElement = getLastElement(n);
	vi ans(n+1);
	ans[n] = lastElement;
	for(i=1;i<=n;i++){
		if(i == lastElement){continue;}
		//cari element i;
		int lastQuery = n + 1 - lastElement;
		int awal = n + 1 - i;
		// printf("find element: %d, lastElement: %d lastQuery: %d awal: %d\n", i, lastElement, lastQuery, awal);
		assert(lastQuery >= 1 && lastQuery <= n);
		int idx = getIdxOfIWithLastQuery(awal, lastQuery, n);
		ans[idx] = i;
	}

	printf("!");
	for(i=1;i<=n;i++){
		printf(" %d",ans[i]);
	}
	printf("\n");
	fflush(stdout);
	
	return 0;
};