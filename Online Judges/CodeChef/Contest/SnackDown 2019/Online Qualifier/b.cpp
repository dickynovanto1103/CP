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

const int maxn = 200;

bitset<maxn+10> isprime;
int prime[maxn];
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
	int tc,n,i,j;
	scanf("%d",&tc);
	isprime.set();
	sieve(maxn);
	int cnt = 0;
	for(i=2;i<=maxn;i++){
		if(isprime[i]){
			prime[cnt] = i;
			cnt++;
		}
	}
	// printf("cnt: %d\n",cnt);
	vi listSemi;
	for(i=0;i<cnt;i++){
		for(j=i+1;j<cnt;j++){
			int kali = prime[i]*prime[j];
			if(kali <= maxn){
				listSemi.pb(kali);	
				// printf("yang dipush: %d\n",kali);
			}
		}
	}
	// sort(listSemi.begin(), listSemi.end());
	int ukuran = listSemi.size();
	// printf("ukuran: %d\n",ukuran);
	vi listJawab;
	for(i=0;i<ukuran;i++){
		for(j=0;j<ukuran;j++){
			listJawab.pb(listSemi[i] + listSemi[j]);
		}
	}
	sort(listJawab.begin(),listJawab.end());
	while(tc--){
		scanf("%d",&n);
		if(binary_search(listJawab.begin(), listJawab.end(), n)){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
};