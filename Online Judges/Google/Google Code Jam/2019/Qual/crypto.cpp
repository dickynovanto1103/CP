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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1e4;

bool isprime[maxn + 10];
int prime[maxn];

void sieve(int n) {
	int i,j;
	isprime[0] = isprime[1] = false;
	for(i=2;i*i<=n;i++) {
		if(isprime[i]){
			for(j=i*i;j<=n;j+=i){
				isprime[j] =false;
			}
		}
	}
}

ii factorize(int n, int cnt) {
	int i,j;

	ii ans = ii(2,2);
	for(i=0;i<cnt;i++){
		if(n%prime[i] == 0){
			ans =  ii(n/prime[i], prime[i]);
		}
	}
	return ans;
}

int a[maxn];

bool isCan(ii fac, int l) {
	int pembagi = fac.second;
	for(int i=0;i<l-1;i++){
		if(a[i+1]%pembagi == 0) {
			pembagi = a[i+1]/pembagi;
		}else{
			return false;
		}
	}
	return true;
}

int main(){
	memset(isprime, true, sizeof isprime);
	sieve(maxn);
	int cnt = 0;
	int tc,i,j;
	for(i=0;i<maxn;i++){
		if(isprime[i]){
			prime[cnt++] = i;
		}
	}
	// printf("cnt: %d\n",cnt);

	
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		int n,l;
		scanf("%d %d",&n,&l);
		
		for(i=0;i<l;i++){
			scanf("%d",&a[i]);
		}
		ii fac = factorize(a[0], cnt);
		// printf("fac: %d %d\n",fac.first, fac.second);
		char mapper[maxn+10];
		if(isCan(fac,l)) {
		}else{
			swap(fac.first, fac.second);
		}

		vi listPrime;
		listPrime.pb(fac.first);
		listPrime.pb(fac.second);
		int pembagi = fac.second;
		set<int> s;
		set<int>::iterator it;
		s.insert(fac.first); s.insert(fac.second);
		for(i=0;i<l-1;i++){
			if(a[i+1]%pembagi == 0){
				pembagi = a[i + 1] / pembagi;
				listPrime.pb(pembagi);
				s.insert(pembagi);
			}
		}
		char kar = 'A';
		for(it=s.begin();it!=s.end();it++){
			mapper[*it] = kar++;
		}
		printf("Case #%d: ",tt);
		for(i=0;i<l+1;i++){
			printf("%c",mapper[listPrime[i]]);
		}
		printf("\n");
	}
	return 0;
};