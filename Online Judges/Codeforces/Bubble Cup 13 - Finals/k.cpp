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

bool isprime[1000001];
int pref[1000001];

void sieve(int n) {
	isprime[0] = isprime[1] = false;
	int i,j;
	for(i=2;i*i<=n;i++){
		if(isprime[i]){
			for(j=i*i;j<=n;j+=i){
				isprime[j] = false;
			}
		}
	}
}

int main(){
	int tc,n,i,j,k;
	memset(isprime, true, sizeof isprime);
	sieve(1000000);
	int cnt = 0;
	for(i=1;i<=1000000;i++){
		pref[i] = pref[i-1];
		if(isprime[i]){
			pref[i]++;
		}
	}

	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		int ans = pref[n] - pref[(int)sqrt(n)] + 1;
		printf("%d\n",ans);
	}
	
	return 0;
};