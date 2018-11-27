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
typedef pair<int,ll> ii;
typedef vector<ii> vii;
 
vector<vii> AdjList;
bool vis[40002];
ll mul[40002];
int root[40002];

const int maxn = 40010;
const ll mod = 998244353;
ll modPow(ll a, ll b){
	if(b == 0){return 1;}
	else{
		if(b%2 == 1){return (a*modPow(a,b-1))%mod;}
		else{
			ll temp = modPow(a,b/2);
			return (temp*temp)%mod;
		}
	}
}

ll inv(ll a){
	return modPow(a,mod-2);
}

struct query{
	int awal, akhir, idx;
};

bool cmp(query a, query b){
	return a.awal < b.awal;
}

class UnionFind{
private: 
	vi rank,p,setSize;
	int numset,i;
public:
	UnionFind(int n){
		numset=n; setSize.assign(n,1); rank.assign(n,0); p.assign(n,0);
		for(i=0;i<n;i++){p[i]=i;}
	}

	int findSet(int i){return (p[i]==i) ? i : (p[i]=findSet(p[i]));}
	bool isSameSet(int i, int j){return findSet(i)==findSet(j);}
	void unionSet(int i, int j){
		if(!isSameSet(i,j)){
			numset--;
			int x=findSet(i), y=findSet(j);
			if(rank[x] > rank[y]){p[y]=x; setSize[x]+=setSize[y];}
			else{
				p[x]=y;
				setSize[y]+=setSize[x];
				if(rank[x]==rank[y]){rank[y]++;}
			}
		}
	}
	int numDisjointSet(){return numset;}
	int sizeSetOf(int i){return setSize[findSet(i)];}
};

int main(){
	int n,q,i,j;
	scanf("%d",&n);
	map<string,int> mapper;
	int cnt = 0;
	AdjList.assign(maxn,vii());
	UnionFind UF(maxn);
	for(i=0;i<n;i++){
		string kata1, kata2;
		int rate;
		cin>>kata1>>kata2;
		scanf("%d",&rate);
		if(mapper.find(kata1) == mapper.end()){
			mapper[kata1] = cnt++;
		}
		if(mapper.find(kata2) == mapper.end()){
			mapper[kata2] = cnt++;
		}
		int idx1 = mapper[kata1], idx2 = mapper[kata2];
		AdjList[idx1].pb(ii(idx2, rate));
		AdjList[idx2].pb(ii(idx1, inv(rate)));
		UF.unionSet(idx1,idx2);
	}
	scanf("%d",&q);
	// memset(isAnswered, )
	memset(vis, 0, sizeof vis);
	for(i=0;i<cnt;++i){
		if(vis[i]) continue;
		vis[i] = 1;
		mul[i] = 1;
		queue<int> qq;
		root[i] = i;
		qq.push(i);
		while(!qq.empty()){
			int tmp = qq.front();
			qq.pop();
			for(ii x : AdjList[tmp]){
				if(vis[x.first]) continue;
				root[x.first] = i;
				// cout<<x.first<<" "<<x.second<<endl;
				mul[x.first] = mul[tmp] * x.second % mod;
				vis[x.first] = true;
				qq.push(x.first);
			}
		}
	}
	for(i=0;i<q;i++){
		//proses tiap awal
		string kata1, kata2;
		cin>>kata1>>kata2;
		int awal = mapper[kata1], akhir = mapper[kata2];
		// printf("consider awal: %d akhir: %d idx: %d\n",awal,akhir,idx);
		if(!UF.isSameSet(awal, akhir)){puts("-1"); continue;}
		ll ans = mul[akhir]*inv(mul[awal]) % mod;
		// cout<<mul[awal]<<" "<<mul[akhir]<<endl;
		// cout<<inv(mul[awal])<<" "<<inv(mul[akhir])<<endl;
		printf("%lld\n", ans);
	}
	
	return 0;
};