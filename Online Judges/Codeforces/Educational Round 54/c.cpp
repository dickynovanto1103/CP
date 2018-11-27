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
	int tc,i,j;
	int n;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		double bagi2 = (double)n/2.0;
		if(bagi2*bagi2 < (double)n){printf("N\n"); continue;}
		double kiri = 0, kanan = bagi2, mid;
		for(i=0;i<500;i++){
			mid = (kiri+kanan)/2.0;
			double sisa = n-mid;
			if(mid*sisa < (double)n){
				kiri = mid;
			}else{
				kanan = mid;
			}
		}
		printf("Y %.9lf %.9lf\n", (double)n - kiri,kiri);
	}
	return 0;
};