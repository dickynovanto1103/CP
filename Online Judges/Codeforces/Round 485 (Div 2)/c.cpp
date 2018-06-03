#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000000000LL
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

const int maxn = 3e3 + 3;

struct board{
	int ukuran, harga;
};

multiset<int> AdjList[maxn];


int main(){
	int n,i,j;
	scanf("%d",&n);
	int ukuran[maxn], harga[maxn];
	for(i=0;i<n;i++){
		scanf("%d",&ukuran[i]);
	}
	for(i=0;i<n;i++){
		scanf("%d",&harga[i]);
	}


	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(ukuran[j] > ukuran[i]) {
				AdjList[i].insert(harga[j]);
			}
		}
	}

	ll ans = inf;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(ukuran[j] > ukuran[i]) {
				if(AdjList[j].size()) {
					ll pertama = *AdjList[j].begin();
					ans = min(ans, pertama + harga[j] + harga[i]);	
				}
				
			}
		}
	}

	if(ans==inf){
		printf("-1\n");
	}else{
		printf("%lld\n",ans);	
	}
	
	return 0;
};