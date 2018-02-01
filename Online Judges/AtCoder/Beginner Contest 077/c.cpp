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

int main(){
	int n,i,j;
	vi a,b,c;
	scanf("%d",&n);
	int bil;
	for(i=0;i<n;i++){scanf("%d",&bil); a.pb(bil);}
	for(i=0;i<n;i++){scanf("%d",&bil); b.pb(bil);}
	for(i=0;i<n;i++){scanf("%d",&bil); c.pb(bil);}
	sort(a.begin(),a.end()); sort(b.begin(),b.end()); sort(c.begin(),c.end());
	vi listIdxB,listBanyakCaraC;
	for(i=0;i<n;i++){
		// if(i){printf(" ");}
		// printf("i: %d\n",i);
		int idxB = lower_bound(b.begin(),b.end(), a[i]+1) - b.begin();
		if(idxB!=n){
			if(b[idxB]==a[i]){
				//cari sampe ketemu lebih besar
				int j = lower_bound(b.begin(),b.end(),a[i]+1) - b.begin();
				
				listIdxB.pb(j);
			}else{
				listIdxB.pb(idxB);
			}
		}else{
			listIdxB.pb(idxB);
	//		printf("masuk idxB: %d\n",idxB);
		}
		//printf("%d(idxB: %d)",a[i],idxB);

	}
	
	for(i=0;i<n;i++){
		//if(i){printf(" ");}
		int idxC = lower_bound(c.begin(),c.end(), b[i]+1) - c.begin();
		if(idxC!=n){
			if(c[idxC]==b[i]){
				int j = lower_bound(c.begin(),c.end(),b[i]+1) - c.begin();
				listBanyakCaraC.pb((ll)n-((ll)j));
			}
			else{listBanyakCaraC.pb((ll)n-idxC);}
		}else{
			listBanyakCaraC.pb((ll)n-idxC);
		}
		//printf("%d(idxC: %d banyakCara: %d)",b[i],idxC,n-idxC);
	}
	// printf("\n");
	// printf("listIdxB\n");
	// for(i=0;i<n;i++){
	// 	if(i){printf(" ");}
	// 	printf("%d",listIdxB[i]);
	// }
	// printf("\n");
	// printf("listBanyakCaraC size: %d\n",listBanyakCaraC.size());
	// for(i=0;i<n;i++){
	// 	if(i){printf(" ");}
	// 	printf("%d",listBanyakCaraC[i]);
	// }
	// printf("\n");
	vector<ll> listPrefixSum;
	listPrefixSum.assign(n+1,0);
	for(i=0;i<n;i++){
		if(i==0){listPrefixSum[i] = (ll)listBanyakCaraC[i];}
		else{listPrefixSum[i] = (ll)listBanyakCaraC[i] + (ll)listPrefixSum[i-1];}
	}
	ll sum = listPrefixSum[n-1];
	ll ans = 0;
	for(i=0;i<n;i++){
		int idx = listIdxB[i];
		if(idx-1<0){ans+=sum;}
		else{ans+=(sum-listPrefixSum[idx-1]);}
	}
	printf("%lld\n",ans);
	
	return 0;
};