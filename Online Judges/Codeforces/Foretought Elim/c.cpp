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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	while(tc--){
		int n;
		scanf("%d",&n);
		int bagian = n/2;

		int kiri = 1, kanan = bagian;

		
		int ans = 0;
		while(kiri <= n){
			int banyakKiri = kanan - kiri + 1;
			int l = 1, r = n - banyakKiri;
			int banyakKanan = r - l + 1;
			while(l <= n){
				banyakKiri = kanan - kiri + 1;
				banyakKanan = r - l + 1;
				printf("%d %d",banyakKiri, banyakKanan);
				for(i=kiri;i<=kanan;i++){printf(" %d",i);}
				for(i=l;i<=r;i++){printf(" %d",i);}
				printf("\n");
				fflush(stdout);	
				int jawab;
				scanf("%d",&jawab);
				if(jawab == -1){return 0;}
				ans = max(ans, jawab);
				l = r+1; r += banyakKanan;
				r = min(r, n);
			}

			kiri = kanan + 1; kanan += banyakKiri;
			kanan = min(kanan, n);
		}
		printf("-1 %d\n",ans);
		fflush(stdout);
	}
	return 0;
};