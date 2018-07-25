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

const int maxn = 1e6 + 6;

int counter[maxn];
int a[maxn];

int main(){
	int tc,i,j,n,k;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&n,&k);
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		memset(counter, 0, sizeof counter);
		ll ans = 0;
		for(i=0;i<k;i++){
			if(a[i] > 1e6){continue;}
			counter[a[i]]++;
		}

		int cntPas = 0;

		for(i=1;i<=1e6;i++){
			if(counter[i] == i){
				cntPas++;
			}
		}
		ans+=cntPas;
		// printf("ans: %lld\n",ans);

		int kiri = 0, kanan = k-1;
		while(kanan<(n-1)){
			int bil1 = a[kiri];
			if(bil1<=1e6){
				counter[bil1]--;
				
				if(counter[bil1] == bil1){
					cntPas++;
				}else{
					if(counter[bil1] == (bil1-1)){
						cntPas--;
					}
				}	
			}
			kiri++;
			
			kanan++;
			int bil2 = a[kanan];
			if(bil2<=1e6){
				counter[bil2]++;
			
				if(counter[bil2] == bil2){
					cntPas++;
				}else{
					if(counter[bil2] == (bil2+1)){
						cntPas--;
					}
				}	
			}
			

			ans+=(ll)cntPas;
			// printf("cntPas jd: %d dan ans jd; %lld\n",cntPas,ans);
		}
		printf("%lld\n",ans);
	}
	return 0;
};