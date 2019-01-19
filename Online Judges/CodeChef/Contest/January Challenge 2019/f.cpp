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

const int maxn = 1e5;

bool isprime[maxn + 4];
ll prime[maxn];

vector<vi> AdjList;
vector<vector<bool> > isVisited;
vi ans;

void sieve(int n) {
	int i,j;
	isprime[0] = isprime[1] = false;
	for(i=2;i*i<=n;i++){
		if(isprime[i]){
			for(j=i*i;j<=n;j+=i){
				isprime[j] = false;
			}
		}
	}
}

bool isConstraintSatisfied(int n){
	for(int i=0;i<n;i++){
		int next1 = (i+1) % n;
		int next2 = (i+2) % n;
		ll gcd1 = __gcd(ans[i], ans[next1]);
		ll gcd2 = __gcd(gcd1, ans[next2]);
		if(gcd1 != 1 && gcd2 == 1){continue;}
		else{
			printf("salah di ans[%d]: %lld ans[%d]: %lld ans[%d]: %lld\n",i,ans[i],next1, ans[next1], next2, ans[next2]);
			printf("gcd1: %lld gcd2: %lld\n",gcd1,gcd2);
			return false;
		}
	}
	return true;
}


bool isAllDifferent() {
	set<ll> s;
	for(int i=0;i<ans.size();i++){
		if(s.count(ans[i])){
			printf("ketemu sama di ans[%d]: %lld\n",i,ans[i]);
			return false;
		}
		else{s.insert(ans[i]);}
	}
	return true;
}

int main(){
	int n,i,j;
	memset(isprime, true, sizeof isprime);
	sieve(maxn);
	int cnt = 0;
	for(i=0;i<maxn;i++){
		if(isprime[i]){
			prime[cnt++] = i;
			// printf("i: %d\n",i);
		}
	}
	AdjList.assign(cnt+2, vi());
	// isVisited.assign(cnt+2, vector<bool>(), false);
	for(i=0;i<3500;i++){
		// printf("i: %d\n",i);
		for(j=i+1;j<3500;j++){
			AdjList[i].pb(prime[j]);
		}
	}
	// printf("done\n");
	int indeks = 0;
	for(i=0;i<cnt;i+=2){
		ll bil1 = AdjList[indeks][i], bil2 = AdjList[indeks][i+1];
		printf("awal bil1: %lld bil2: %lld\n",bil1,bil2);
		if(bil2 == 0){break;}
		bil1 *= prime[indeks], bil2 *= prime[indeks];
		if(bil1 <= (ll)inf){
			ans.pb(bil1);
		}
		if(bil2 <= (ll)inf){
			ans.pb(bil2);
		}
		// if(bil1 * bil2 > (ll)inf){break;}
		printf("%lld %lld\n", bil1, bil2);
		bil1 = AdjList[indeks+1][i], bil2 = AdjList[indeks+1][i+1];
		printf("awal bil1: %lld bil2: %lld\n",bil1,bil2);
		if(bil2 == 0){break;}
		bil1 *= prime[indeks+1], bil2 *= prime[indeks+1];
		if(bil1 <= (ll)inf){
			ans.pb(bil1);
		}
		if(bil2 <= (ll)inf){
			ans.pb(bil2);
		}
		printf("%lld %lld\n", bil1, bil2);
	}
	ll temp = 7*32609;
	ans.pb(temp);
	// printf("dipush: %lld\n",);
	indeks+=2;
	for(i=0;i<cnt-1;i+=2){
		ll bil1 = AdjList[indeks][i], bil2 = AdjList[indeks][i+1];
		printf("awal bil1: %lld bil2: %lld\n",bil1,bil2);
		printf("dikali dengan prime: %lld\n",prime[indeks]);
		if(bil2 == 0){break;}
		bil1 *= prime[indeks], bil2 *= prime[indeks];

		if(bil1 <= (ll)inf && bil1 != temp){
			ans.pb(bil1);
		}
		if(bil2 <= (ll)inf && bil2 != temp){
			ans.pb(bil2);
		}
		// if(bil1 * bil2 > (ll)inf){break;}
		printf("%lld %lld\n", bil1, bil2);
		bil1 = AdjList[indeks+1][i], bil2 = AdjList[indeks+1][i+1];
		printf("awal bil1: %lld bil2: %lld\n",bil1,bil2);
		printf("dikali dengan prime: %lld\n",prime[indeks+1]);
		if(bil2 == 0){break;}
		bil1 *= prime[indeks+1], bil2 *= prime[indeks+1];
		if(bil1 <= (ll)inf && bil1 != temp){
			ans.pb(bil1);
		}
		if(bil2 <= (ll)inf && bil2 != temp){
			ans.pb(bil2);

		}
		printf("%lld %lld\n", bil1, bil2);
	}

	temp = 11*32603;
	ans.pb(temp);
	
	indeks+=2;
	for(i=0;i<cnt-1;i+=2){
		ll bil1 = AdjList[indeks][i], bil2 = AdjList[indeks][i+1];
		printf("awal bil1: %lld bil2: %lld\n",bil1,bil2);
		printf("dikali dengan prime: %lld\n",prime[indeks]);
		if(bil2 == 0){break;}
		bil1 *= prime[indeks], bil2 *= prime[indeks];
		if(bil1 <= (ll)inf && bil1 != temp){
			ans.pb(bil1);
		}
		if(bil2 <= (ll)inf && bil2 != temp){
			ans.pb(bil2);
		}
		// if(bil1 * bil2 > (ll)inf){break;}
		printf("%lld %lld\n", bil1, bil2);
		bil1 = AdjList[indeks+1][i], bil2 = AdjList[indeks+1][i+1];
		printf("awal bil1: %lld bil2: %lld\n",bil1,bil2);
		printf("dikali dengan prime: %lld\n",prime[indeks+1]);
		if(bil2 == 0){break;}
		bil1 *= prime[indeks+1], bil2 *= prime[indeks+1];
		if(bil1 <= (ll)inf && bil1 != temp){
			ans.pb(bil1);
		}
		if(bil2 <= (ll)inf && bil2 != temp){
			ans.pb(bil2);

		}
		printf("%lld %lld\n", bil1, bil2);
	}	

	int ukuran = ans.size();
	printf("ukuran: %d\n", ukuran);
	if(isAllDifferent() && isConstraintSatisfied(ans.size())){
		printf("good\n");
	}
	int tc;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		
		
	}
	//2..2*3.. 3*5...5*2
	return 0;
};