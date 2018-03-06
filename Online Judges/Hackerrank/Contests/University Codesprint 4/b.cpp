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

const int maxn = 510;

int main(){
	int n,m,i,j;
	int s[maxn], k[maxn], r[maxn], c[maxn];
	double maksSisi[maxn];
	scanf("%d %d",&n,&m);
	double maks = -1.0;
	for(i=0;i<n;i++){scanf("%d",&s[i]);}
	for(i=0;i<n;i++){scanf("%d",&k[i]);}
	for(i=0;i<m;i++){scanf("%d",&r[i]);}
	sort(r,r+m);
	for(i=0;i<m;i++){
		maksSisi[i] = ((double)r[i]*sqrt(2)); maks = max(maks, maksSisi[i]);
	}
	
	for(i=0;i<m;i++){scanf("%d",&c[i]);}


	ll cnt = 0;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(k[i]==0){break;}
			double selisih = (double)s[i] - maksSisi[j];
			// printf("maks: %.3lf selisih: %.3lf\n",maks,selisih);
			if(selisih>=eps){continue;}
			if(fabs(selisih)<eps){continue;}
			//s[i] lebih kecil daripada maksSisi
			if(c[j]==0){continue;}
			if(c[j] < k[i]) {
				cnt+=(ll)c[j];
                k[i]-=c[j];
				c[j] = 0;
				
			}else{
				cnt+=(ll)k[i];	
				c[j]-=k[i];
				k[i]= 0;
			}
			
		}
		
	}
	printf("%lld\n",cnt);
	return 0;
};