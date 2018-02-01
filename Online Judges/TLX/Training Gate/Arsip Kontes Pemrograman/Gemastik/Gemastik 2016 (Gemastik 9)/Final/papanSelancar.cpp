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

const int maxn = 5e4 + 4;
ll tot[maxn], cntR[maxn], cntL[maxn], banyakL[maxn], banyakR[maxn];

int main(){
	int tc,n,m,i,j;
	scanf("%d",&tc);
	while(tc--){
		memset(tot, 0, sizeof tot); memset(cntR, 0, sizeof cntR); memset(cntL, 0, sizeof cntL); memset(banyakR, 0, sizeof banyakR); memset(banyakL, 0, sizeof banyakL); 
		scanf("%d %d",&n,&m);
		for(i=0;i<m;i++){
			int x, k;
			scanf("%d %d",&x,&k);
			cntR[x]++;
			banyakR[x]+=k;

			if((x-1)>=1){
				cntL[x-1]++;
				banyakL[x-1]+=(k-1);
			}

			if((x+k)<=n){cntR[x+k]--;}
			if((x-k)>=1){cntL[x-k]--;}
		}

		ll banyak = 0, cnt = 0;
		// printf("pertama\n");
		for(i=1;i<=n;i++){
			banyak+=banyakR[i];

			tot[i]+=banyak;
			cnt+=cntR[i];
			banyak-=cnt;
		}
		banyak = 0; cnt = 0;
		// printf("kedua\n");
		for(i=n;i>=1;i--){
			banyak+=banyakL[i];

			tot[i]+=banyak;
			cnt+=cntL[i];
			banyak-=cnt;
		}
		for(i=1;i<=n;i++){
			if(i>1){printf(" ");}
			printf("%lld",tot[i]);
		}
		printf("\n");
	}
	return 0;
};