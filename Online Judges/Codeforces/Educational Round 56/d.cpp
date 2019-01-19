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

vector<vi> AdjList;

const int maxn = 3e5 + 5;
const ll mod = 998244353;

bool isVisited[maxn];
int color[maxn];

int ganjil, genap;

bool isBipartite(int idx, int warna){
	int i;
	color[idx] = warna;
	queue<int> q;
	q.push(idx);
	while(!q.empty()){
		int front = q.front(); q.pop();
		for(i=0;i<AdjList[front].size();i++){
			int v = AdjList[front][i];
			if(color[v] == -1){
				color[v] = 1 - color[front];
				q.push(v);
			}else{
				if(color[v] == color[front]){return false;}
			}
		}	
	}
	return true;
	
}

void getUkuran(int idx, int par){
	if(par == 1){ganjil++;}
	else{genap++;}
	isVisited[idx] = true;
	for(int i=0;i<AdjList[idx].size();i++){
		int v = AdjList[idx][i];
		if(isVisited[v]){continue;}
		getUkuran(v, 1-par);
	}

}

ll modPow(ll a, ll b){
	if(b == 0){return 1;}
	else{
		if(b %2 == 1){return a*modPow(a,b-1)%mod;}
		else{
			ll temp = modPow(a,b/2);
			return temp*temp%mod;
		}
	}
}

ll arr[maxn];

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	memset(color, -1, sizeof color);

	while(tc--){

		int n,m;
		
		scanf("%d %d",&n,&m);
		
		// printf("n: %d m: %d\n",n,m);
		for(i=0;i<=n;i++){
			arr[i] = 0;
			isVisited[i] = false;
			color[i] = -1;
		}
		
		AdjList.assign(n+1,vi());
		for(i=0;i<m;i++){
			int a,b;
			scanf("%d %d",&a,&b);
			AdjList[a].pb(b); AdjList[b].pb(a);
		}
		bool apakahBipartite = true;

		for(i=1;i<=n;i++){
			if(color[i] == -1){
				if(!isBipartite(i,0)){apakahBipartite = false; break;}
			}
		}

		if(!apakahBipartite){printf("0\n");}
		else{
			int cnt = 0;
			for(i=1;i<=n;i++){
				if(isVisited[i]){continue;}
				ganjil = 0, genap = 0;
				getUkuran(i,0);
				arr[cnt] = modPow(2, ganjil);
				arr[cnt] += modPow(2, genap);
				arr[cnt] %= mod;
				cnt++;
			}
			// printf("cnt: %d\n",cnt);
			// printf("arr[0]: %lld\n",arr[0]);

			ll ans = 1;
			for(i=0;i<cnt;i++){ans *= arr[i]; ans %= mod;}
			
			printf("%lld\n",ans);
			
		}


		
		AdjList.clear();
	}
	return 0;
};