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

const ll mod = 1e9 + 7;
const int maxn = 1e5 + 5;

vector<vi> AdjList;
vector<vi> counterFaktor;
map<ll,ll> mapper[maxn];

ll t[maxn], divisor[maxn];
ll a[maxn];
ll hitung(int n) {
	if(AdjList[n].size() == 0){return t[n] = a[n];}
	ll ans = 1;
	for(int i=0;i<AdjList[n].size();i++){
		int v = AdjList[n][i];
		ans *= hitung(v);
		ans %= mod;
	}
	ans*=a[n];
	ans %= mod;
	return t[n] = ans;
}

int prime[] = {2,3,5,7,11,13};

int main(){
	int n,i,j;
	memset(isprime,true,sizeof isprime);
	
	int tc;
	scanf("%d",&tc);
	while(tc--) {
		scanf("%d",&n);
		for(i=0;i<(n-1);i++){
			int u,v;
			scanf("%d %d",&u,&v);
			AdjList[u].pb(v);
		}
		for(i=0;i<n;i++){scanf("%lld",&a[i]);}
		int q;
		scanf("%d",&q);
		while(q--){
			string com;
			int u,x;
			cin>>com;
			if(com[0] == 'R'){
				scanf("%d",&u);
				//jawab

			}else{
				scanf("%d %d",&u,&x);
			}
		}
	}
	return 0;
};