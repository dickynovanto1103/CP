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

const int maxn = 3e5 + 5;

int n,k;
int a[maxn];

bool can(double avg){
	double temp[maxn];
	double pref[maxn];
	int i;
	for(i=0;i<n;i++){
		temp[i] = (double)a[i] - avg;
		pref[i] = temp[i];
	}
	
	pref[0] = temp[0];
	for(i=1;i<n;i++){
		pref[i] += pref[i-1];
	}
	double ans = pref[k-1];
	if(ans >= eps){return true;}
	double minim = inf;
	for(i=k;i<n;i++){
		minim = min(minim, pref[i-k]);

		double jawab = pref[i] - minim;
		if(jawab >= eps){return true;}
	}
	return false;
}

int main(){
	int i,j;
	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++){scanf("%d",&a[i]);}
	double kiri = 1, kanan = inf, mid, ans;
	for(int iterasi = 0; iterasi < 100; iterasi++){
		mid = (kiri + kanan)/2.0;
		// printf("mid: %lf\n",mid);
		if(can(mid)){
			kiri = mid;
			ans = mid;
		}else{
			kanan = mid;
		}
	}
	printf("%.9lf\n",ans);
	return 0;
};