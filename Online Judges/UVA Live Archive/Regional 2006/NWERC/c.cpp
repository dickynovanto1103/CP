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

const int maxn = 1e4 + 4;

double luas[maxn];
int n,f;

bool isValid(double ambil){
	int cnt = 0;
	for(int i=0;i<n;i++){
		if(luas[i] >= ambil){
			cnt += floor(luas[i]/ambil);
			if(cnt >=f){return true;}
		}
	}
	return false;
}

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	int r[maxn];
	while(tc--){
		scanf("%d %d",&n,&f);
		f++;
		for(i=0;i<n;i++){
			scanf("%d",&r[i]);
			luas[i] = pi*(double)r[i]*(double)r[i];
			// printf("luas[%d]: %lf\n", i,luas[i]);
		}
		double kiri = 0.00001, kanan = inf, ans;
		for(i=0;i<100;i++){
			double mid = (kiri+kanan)/2.0;
			if(isValid(mid)){
				ans = mid;
				kiri = mid;
			}else{
				kanan = mid;
			}
		}
		printf("%.9lf\n",ans);
	}
	return 0;
};