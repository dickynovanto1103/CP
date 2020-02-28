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

const int maxn = 1e6;

bool isprime[maxn + 10];
int prime[78500];
void sieve(int n){
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

int main(){
	int n,i,j;
	memset(isprime, true, sizeof isprime);
	sieve(maxn);
	int cnt = 0;
	for(i=0;i<maxn;i++){
		if(isprime[i]){
			prime[cnt++] = i;
		}
	}
	set<ll> ans;
	for(i=0;i<cnt;i++){
		ans.insert((ll)prime[i]*prime[i]);
	}
	// printf("%d\n",cnt);
	scanf("%d",&n);
	for(i=0;i<n;i++){
		ll a;
		scanf("%lld",&a);
		if(ans.find(a) == ans.end()){
			printf("NO\n");
		}else{
			printf("YES\n");
		}
		
	}
	return 0;
};