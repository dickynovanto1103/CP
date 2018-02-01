#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main() {
	int n,k,i,j,tc;
	double m, a[100010];
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d %lf",&n,&k,&m);
		for(i=1;i<=n;i++){scanf("%lf",&a[i]);}
		
		bool found = false;
		double kiri = 0, kanan = inf, mid,ans;
		//printf("kiri: %lf kanan: %lf\n",kiri,kanan);
		for(int tt = 0;tt<=500;tt++){
			double cur = m;
			mid = (kiri+kanan)/2.0;
			//printf("cur awal:%lf\n",cur);
			for(i=1;i<=n;i++){
				cur+=a[i];
				//printf("cur:%lf\n",cur);
				if(cur>mid){
					cur-=mid;
					//printf("cur jd: %lld\n",cur);
				}
				else{
					cur = 0;
					//printf("cur jd 0 wkatu i: %d\n",i);
				}
				if(cur==0){break;}
			}
			//printf("i: %d\n",i);
			if(i==k){ans = mid; found = true; kanan = mid;}
			else{
				if(i<k){kanan = mid;}
				else{kiri = mid;}
			}
		}
		if(found){printf("%.15lf\n",ans);}
		else{printf("-1\n");}
	}
	return 0;
}