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
typedef vector<ll> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1e5 + 5;

struct pasangan{
	int power;
	ll coin;
};

bool cmp(pasangan a, pasangan b) {
	return a.power < b.power;
}

int main(){
	int n,k,i,j;
	pasangan pas[maxn];
	
	map<int,int> mapper;
	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++){
		int power;
		scanf("%d",&power); mapper[power] = i;
		pas[i].power = power;
	}
	for(i=0;i<n;i++){
		scanf("%lld",&pas[i].coin);
	}
	sort(pas, pas+n, cmp);
	priority_queue<ll> pq;
	
	ll jawaban[maxn];

	for(i=0;i<n;i++){
		int power = pas[i].power;
		//ambil sebanyak k
		vi tempPower;
		ll ans = 0;
		int maksAmbil = k;
		while(!pq.empty()){
			// printf("test\n");
			if(maksAmbil==0){
				break;}
			ll front = pq.top(); pq.pop();
			tempPower.pb(front);
			ans+=front;
			maksAmbil--;
			if(maksAmbil==0){break;}
		}
		for(j=0;j<tempPower.size();j++){
			pq.push(tempPower[j]);
		}

		ans+=pas[i].coin;
		// printf("ans jd: %lld\n",ans);
		int idx = mapper[power];
		jawaban[idx] = ans;
		pq.push(pas[i].coin);
	}
	for(i=0;i<n;i++){
		if(i){printf(" ");}
		printf("%lld",jawaban[i]);
	}
	printf("\n");

	return 0;
};