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

const int maxn = 2e3;

ll cntx[maxn+4];
ll cnty[maxn+4];

int main(){
	int tc,n;
	ll k,i,j;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %lld",&n,&k);
		int x,y;
		memset(cntx,0,sizeof cntx); memset(cnty,0,sizeof cnty);
		for(i=0;i<n;i++){scanf("%d %d",&x,&y); cntx[x]++; cnty[y]++;}
		ll totalx = 0, totaly=0;
		for(i=0;i<=maxn;i++){
			for(j=i+1;j<=maxn;j++){
				totalx+=((j-i)*(cntx[i]*cntx[j]));
				totaly+=((j-i)*(cnty[i]*cnty[j]));
			}
		}
		ll total = totalx+totaly;
		//printf("total: %lld totalx: %lld totaly: %lld\n",total,totalx,totaly);
		if(total>k){printf("-1 -1\n"); continue;}
		ll sisa = k-total;
		ll jarakX[maxn+4];
		ll jarakY[maxn+4];
		set<ll> s;
		for(i=0;i<=maxn;i++){
			jarakX[i] = 0;
			jarakY[i] = 0;
			for(j=0;j<=maxn;j++){
				jarakX[i]+=((abs(j-i))*cntx[j]);
				jarakY[i]+=((abs(j-i))*cnty[j]);
			}
			//printf("jarakX[%lld]: %lld jarakY[%lld]: %lld\n",i,jarakX[i], i,jarakY[i]);
			s.insert(jarakY[i]);
		}
		bool found = false;
		int ansX, ansY;
		for(i=0;i<=maxn;i++){
			ll sisaPanjang = sisa-jarakX[i];
			if(s.count(sisaPanjang)){
				for(j=0;j<=maxn;j++){
					if(jarakY[j]==sisaPanjang){
						ansX = i; ansY = j;
						found = true;
						break;
					}
				}
			}
			if(found){break;}
		}
		
		if(!found){printf("-1 -1\n");}
		else{printf("%d %d\n",ansX,ansY);}
		
	}
	return 0;
};