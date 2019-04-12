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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1e5 + 5;

int main(){
	int tc,n,p,i,j;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		scanf("%d %d",&n,&p);
		int a[maxn];
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		sort(a, a+n);
		int maks = a[p-1];
		int sum = 0;
		int minim = inf;
		for(i=0;i<p;i++){
			sum += (maks - a[i]);
		}
		minim = sum;
		int kiri = 0, kanan = p-1;
		while(kanan < (n-1)){
			sum -= (a[kanan] - a[kiri]);
			kiri++;
			kanan++;
			int selisih = a[kanan] - a[kanan-1];
			// printf("selisih: %d\n",selisih);
			sum += ((p-1)*selisih);
			minim = min(minim, sum);
			// printf("kiri: %d kanan: %d sum: %d minim: %d\n",kiri, kanan, sum, minim);
		}
		printf("Case #%d: %d\n",tt,minim);
	}
	return 0;
};