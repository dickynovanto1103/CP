#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main() {
	int n,a[15],i;
	while(scanf("%d",&n),n){
		for(i=0;i<=n;i++){scanf("%d",&a[i]);}
		double kiri = -1.0, kanan = inf*1.0, mid;
		bool found = false;
		while(fabs(kanan-kiri)>eps){
			mid = (kiri+kanan)/2.0;
			//printf("kiri: %lf kanan: %lf mid: %lf\n",kiri,kanan,mid);
			double sum = a[0]*1.0;
			for(i=1;i<=n;i++){
				sum+=((double)a[i]/pow((1+mid),i));
			}
			//printf("sum: %lf\n",sum);
			if(fabs(sum-0)<=eps){found = true; printf("%.2lf\n",mid); break;}
			else{
				if(sum<0){kanan = mid;}
				else if(sum>0){kiri = mid;}	
			}
		}
		if(!found){printf("%.2lf\n",mid);}
		
	}
	return 0;
}