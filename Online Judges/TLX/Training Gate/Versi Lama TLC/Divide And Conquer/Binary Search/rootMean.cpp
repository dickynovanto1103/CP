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

const int maxn = 50010;

int main(){
	int n,i,j;
	double a[maxn];
	scanf("%d",&n);

	for(i=0;i<n;i++){
		scanf("%lf",&a[i]);
	}

	double kiri = -10000.0, kanan = 10000.0, t1,t2, ans;
	for(i=0;i<100;i++){
		// printf("kiri: %.2lf kanan: %.2lf\n",kiri,kanan);
		double selisih = kanan - kiri;
		double sepertiga = selisih/3.0;
		double duakali = sepertiga*2.0;
		t1 = kiri + sepertiga;
		t2 = kiri + duakali;
		// printf("t1: %.2lf t2: %.2lf\n",t1,t2);
		double ans1 = 0, ans2 = 0;
		for(j=0;j<n;j++){
			ans1+=(pow(abs(a[j]-t1),1.5));
			ans2+=(pow(abs(a[j]-t2),1.5));
		}
		// printf("ans1: %.2lf ans2: %.2lf\n", ans1,ans2);
		if(ans1 < ans2) {
			kanan = t2;
			ans = kanan;
			// printf("kanan jadi: %lf\n",kanan);
		}else{
			kiri = t1;
			ans = kiri;
			// printf("kiri jadi: %lf\n",kiri);
		}
	}
	printf("%.2lf\n",ans);
	return 0;
};