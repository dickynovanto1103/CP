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

const int maxn = 1e4;
bool isprime[maxn + 4];
int prime[1230];
void sieve(int n){
	int i,j;
	isprime[0] = isprime[1] = false;
	for(i=2;i*i<=n;i++){
		if(isprime[i]){
			for(j=i*2;j<=n;j+=i){
				isprime[j] = false;
			}
		}
	}
}

vector<vi> AdjList;

bool isDiffer1Digit(int bil1, int bil2) {
	int diff = 0;
	while(bil1>0){
		int angka1 = bil1%10; bil1/=10;
		int angka2 = bil2%10; bil2/=10;
		if(angka2 != angka1){
			diff++;
			if(diff==2){return false;}
		}
	}
	return true;
}

int main(){
	memset(isprime,true,sizeof isprime);
	sieve(maxn);
	AdjList.assign(maxn,vi());
	int cnt = 0;
	int i,j;
	for(i=0;i<maxn;i++){
		if(isprime[i]){
			prime[cnt] = i;

			cnt++;
		}
	}
	int idx = lower_bound(prime,prime+cnt,1000) - prime;
	for(i=idx;i<cnt;i++){
		for(j=idx+1;j<cnt;j++){
			if(isDiffer1Digit(prime[i], prime[j])){
				AdjList[prime[i]].pb(prime[j]);
				AdjList[prime[j]].pb(prime[i]);
			}
		}
	}

	int tc;
	scanf("%d",&tc);
	while(tc--){
		
		int dist[maxn];
		fill(dist, dist+maxn,inf);
		int a,b;
		scanf("%d %d",&a,&b);
		queue<int> q;
		q.push(a); dist[a] = 0;

		while(!q.empty()){
			int front = q.front(); q.pop();
			for(i=0;i<AdjList[front].size();i++){
				int v = AdjList[front][i];
				if(dist[v]==inf){
					dist[v] = dist[front] + 1;
					q.push(v);
				}
			}
		}
		if(dist[b]==inf){printf("Impossible\n");}
		else{printf("%d\n",dist[b]);}
	}

	

	return 0;
};