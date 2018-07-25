#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-15
#define mp make_pair
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1e5 + 5;

int main(){
	int n,f;
	while(scanf("%d %d",&n,&f)!=EOF){
		double a[maxn];
		for(int i=0;i<n;i++){
			scanf("%lf",&a[i]);
		}
		double waktuTotal = 0.0;
		double rate = (double)f;
		double waktuLowest = a[n-1] / f;
		for(int i=0;i<n;i++){
			double sisa = a[i] - ((double)f*waktuTotal);
			if(sisa < eps){
				
			}else{
				//tambahin ratenya
				double waktu = sisa / rate;
				waktuTotal+=waktu;
			}
			
			if(i==(n-1)){
				waktuLowest = min(waktuLowest, waktuTotal);	
			}
			
			rate += (double)f;
		}
		printf("%.15lf %.15lf\n",waktuLowest, waktuTotal);
		// printf("time: %lf\n",time);
	}
	return 0;
};