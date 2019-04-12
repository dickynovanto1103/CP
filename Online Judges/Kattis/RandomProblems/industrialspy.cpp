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

const int maxn = 1e7;
bool isprime[maxn+12];
int prime[6500000];
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
	memset(isprime, true, sizeof isprime);
	sieve(maxn);
	int cnt = 0;
	int i,j;
	for(i=2;i<=maxn;i++){
		if(isprime[i]){
			prime[cnt++] = i;
			// printf("cnt: %d i: %d\n",cnt,i);
		}
	}

	int n;
	scanf("%d",&n);
	while(n--){
		string bil;
		cin>>bil;
		// printf("bil: %d\n",bil);
		int cnt1[10], cnt2[10];
		memset(cnt1, 0, sizeof cnt1);
		

		for(i=0;i<bil.size();i++){
			int ang = bil[i] - '0';
			cnt1[ang]++;
			// printf("cnt1[%d]: %d\n",ang,cnt1[ang]);
		}

		int ans = 0;
		for(i=0;i<cnt;i++){
			int bilprima = prime[i];
			bool valid = true;
			int awal = bilprima;
			memset(cnt2, 0, sizeof cnt2);	
			while(bilprima>0){
				int ang = bilprima%10;
				bilprima/=10;
				cnt2[ang]++;
				if(cnt2[ang] > cnt1[ang]){
					// if(awal == 101)
					// 	printf("awal: %d ga valid pas cnt2[%d]: %d\n",awal, ang, cnt2[ang]);
					valid = false;break;
				}
			}
			if(valid){
				// printf("angka: %d\n",awal);
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
};