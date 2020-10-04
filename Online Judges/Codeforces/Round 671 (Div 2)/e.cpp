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
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int prime[10001];
bool isprime[100001];

void sieve(int n){
	isprime[0] = isprime[1] = false;
	for(int i=2;i*i<=n;i++){
		if(isprime[i]){
			for(int j=i*i;j<=n;j+=i){
				isprime[j] = false;
			}
		}
	}
}

vi getPrimeFactors(ll n) {
	vi ans;
	ll pf_idx = 0, pf = prime[pf_idx];
	while(pf * pf <= n){
		if(n % pf == 0){
			ans.pb(pf);
			while(n % pf == 0){
				n /= pf;
			}
		}
		pf = prime[++pf_idx];
	}
	if(n != 1){
		ans.pb(n);
	}

	return ans;
}

int main(){
	memset(isprime, true, sizeof isprime);
	sieve(100000);


	int tc,i,j,n;
	int cnt = 0;
	for(i=1;i<=100000;i++){
		if(isprime[i]){
			prime[cnt++] = i;
		}
	}

	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		vi pfs = getPrimeFactors(n);
		set<int> div;
		set<int>::iterator it;
		for(i=1;i*i<=n;i++){
			if(n % i == 0){
				int div1 = n / i;
				int div2 = i;
				if(div1 == div2){
					div.insert(div1);
					// printf("insert %d\n",div1);
				}else{
					div.insert(div1);
					div.insert(div2);
					// printf("insert %d %d\n",div1, div2);
				}
			}
		}
		div.erase(1);
		if(div.size() == 1){
			//prime
			printf("%d\n0\n",n);

		}else if(div.size() <= 3){
			vi ans;
			for(it=div.begin();it!=div.end();it++){
				ans.pb(*it);
			}

			int sz = ans.size();
			int needLcm = 0;
			for(i=0;i<sz;i++){
				int next = (i + 1) % sz;
				if(__gcd(ans[i], ans[next]) == 1){
					needLcm++;
				}
				if(i){printf(" ");}
				printf("%d",ans[i]);
			}

			printf("\n");
			printf("%d\n",needLcm);
		}else{
			vector<vi> adj;
			adj.assign(pfs.size(), vi());
			int sz = pfs.size();
			for(i=0;i<sz;i++){
				int pf = pfs[i];
				adj[i].pb(pf);
				div.erase(pf);
				// printf("erase pf %d\n",pf);
				if(i < (sz - 1)){
					div.erase(pfs[i] * pfs[i+1]);
					// printf("erase %d\n",pfs[i]*pfs[i+1]);
				}
			}
			div.erase(n);
			// printf("erase n: %d\n",n);
			
			for(it=div.begin();it!=div.end();it++){
				int bil = *it;
				// printf("bil: %d\n",bil);
				for(i=0;i<pfs.size();i++){
					int pf = pfs[i];
					if(bil % pf == 0){
						adj[i].pb(bil);
						break;
					}
				}
			}
			
			vi ans;
			sz = adj.size();
			// printf("sz: %d\n",sz);
			for(i=0;i<sz;i++){
				for(j=0;j<adj[i].size();j++){
					ans.pb(adj[i][j]);
					// printf("push: adj[%d][%d]: %d\n",i,j,adj[i][j]);
				}
				if(i == (sz - 1)){
					ans.pb(n);
				}else if(i < (sz - 1)){
					ans.pb(pfs[i] * pfs[i+1]);
					// printf("push kali: pfs[%d] %d * pfs[%d] %d = %d\n",i, pfs[i], i+1, pfs[i+1], pfs[i] * pfs[i+1]);
				}
			}

			bool first = true;
			for(int jawab: ans){
				if(!first){printf(" ");}
				printf("%d",jawab);
				first = false;
			}
			printf("\n");
			printf("0\n");
		}

	}
	
	return 0;
};