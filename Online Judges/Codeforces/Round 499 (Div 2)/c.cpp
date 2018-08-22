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

const int maxn = 1e3 + 3;

int main(){
	int n,m,i,j;
	int a[maxn], b[maxn];
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(a[i] == 1){
			printf("-1\n");
			return 0;
		}
	}
	a[n] = a[0];
	for(i=0;i<n;i++){
		scanf("%d",&b[i]);
		if(b[i] == 1){
			printf("-1\n");
			return 0;
		}
	}
	b[n] = b[0];

	long double kiri = 0.0, kanan = 1000000008.0, mid, ans;

	while(fabs(kiri-kanan) >= eps){
		mid = (kiri+kanan)/2.0;
		long double bensin = mid;
		bool isValid = true;
		for(i=0;i<n;i++){
			long double total = (long double)m + bensin;

			long double bensinDibutuhkan = total / (long double)a[i];
			bensin -= bensinDibutuhkan;

			if(bensin < 0.0){isValid = false; break;}

			total = (long double)m + bensin;
			bensinDibutuhkan = total / (long double)b[i+1];
			bensin -= bensinDibutuhkan;

			if(bensin < 0.0){isValid = false; break;}
		}

		if(isValid){
			ans = mid;
			kanan = mid;
		}else{
			kiri = mid;
		}
	}
	
	printf("%.9Lf\n",ans);

	return 0;
};