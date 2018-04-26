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

int main(){
	int tc,i,j,n;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		ll counter[4010];
		memset(counter,0,sizeof counter);
		for(i=0;i<n;i++){
			int bil;
			scanf("%d",&bil);
			bil+=1000;
			counter[bil]++;
		}
		// for(i=1000;i<=1010;i++){
		// 	printf("counter[%d]: %d\n", i,counter[i]);
		// }
		ll cnt = 0;
		for(i=0;i<=4000;i+=2){
			//cari
			if(counter[i/2]==0){continue;}
			for(j=0;j<=i/2;j++){
				ll cnt1 = counter[j], cnt2 = counter[i-j];
				if(j==(i-j)){
					cnt+=((cnt1*(cnt1-1LL))/2LL);
					break;
				}else{

					cnt+=(cnt1*cnt2);	
					// if(cnt1!=0 && cnt2!=0){
					// 	printf("cnt1: %lld cnt2: %lld i: %d j: %d\n",cnt1,cnt2,i,j);
					// }
				}
			}
		}
		printf("%lld\n",cnt);
	}
	return 0;
};