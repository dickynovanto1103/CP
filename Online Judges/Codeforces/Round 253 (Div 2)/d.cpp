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

const int maxn = 1e2 + 2;

bool cmp(double a, double b){
	return a > b;
}

int main(){
	int n,i,j;
	double a[maxn];

	scanf("%d",&n);
	for(i=0;i<n;i++){scanf("%lf",&a[i]); }
	sort(a,a+n,cmp);
	double ans = 0;
	for(i=0;i<n;i++){
		double jawab;
		for(j=0;j<=i;j++){
			if(i==0 && j==0){
				ans = a[i];
				// printf("ans: %lf\n",ans);
			}else{
				double peluangTidakKasih = 1.0;
				for(int k=0;k<=i;k++){
					peluangTidakKasih*=(1.0 - a[k]);
				}
				jawab = 0;
				for(int k=0;k<=i;k++){
					double peluangKasih = a[k];
					double peluangLainTidakKasih = peluangTidakKasih / (1.0 - a[k]);
					jawab += (peluangKasih*peluangLainTidakKasih);
				}
				ans = max(ans, jawab);
			}
		}
		
	}
	printf("%.9lf\n",ans);
	return 0;
};