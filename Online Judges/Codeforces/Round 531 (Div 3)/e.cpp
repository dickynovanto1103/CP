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

const int maxn = 2e5 + 5;

const ll mod = 998244353;

ll modPow(ll a, ll b){
	if(b == 0){return 1;}
	else{
		if(b % 2 == 1){return a*modPow(a,b-1)%mod;}
		else{
			ll temp = modPow(a,b/2);
			return temp*temp%mod;
		}
	}
}
vector<vi> AdjList;

int main(){
	int n,m,i,j;
	scanf("%d",&n);
	int a[maxn];
	map<int,int> mapper;
	int cnt = 0;
	AdjList.assign(maxn, vi());
	for(i=0;i<n;i++){
		int bil;
		scanf("%d",&bil);
		if(mapper.find(bil) != mapper.end()){
			a[i] = mapper[bil];
		}else{
			mapper[bil] = cnt;
			a[i] = cnt;
			cnt++;
		}
		AdjList[a[i]].pb(i);
	}
	int area = 0;
	int maks = 0;
	bool isVisited[maxn];
	memset(isVisited, false, sizeof isVisited);
	for(i=0;i<n;i++){

		if(i > maks){area++;}
		if(isVisited[i]){continue;}
		int bil = a[i];
		for(j=0;j<AdjList[bil].size();j++){
			int idx = AdjList[bil][j];
			if(idx > maks){
				maks = idx;
			}
			isVisited[idx] = true;
		}
	}
	// printf("area: %d\n",area);

	ll ans = modPow(2, area);
	printf("%lld\n",ans);


	return 0;
};