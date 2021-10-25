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
#define debug if(true)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int tc,i,j,n;
	scanf("%d",&tc);
	int a[1010][6];
	while(tc--){
		scanf("%d",&n);
		for(i=0;i<n;i++){
			for(j=0;j<5;j++){
				scanf("%d",&a[i][j]);
			}
		}

		bool found = false;
		for(i=0;i<5;i++){
			int bisa[1010];
			memset(bisa, false, sizeof bisa);
			int c = 0;
			for(j=0;j<n;j++){
				if(a[j][i]){
					bisa[j] = true;	
					c++;
				}
			}
			if(c < n/2) {continue;}
			
			for(j=i+1;j<5;j++){
				int shared = 0;
				int cnt = 0;
				for(int k=0;k<n;k++){
					if(a[k][j]) {
						cnt++;
						if(bisa[k]) shared++;
					}
				}
				if(cnt < n/2){continue;}
				//tujuan: cari students yang bs semua di 2 hari i dan j
				int only2 = cnt - shared;
				int only1 = c - shared;
				
				bool bisa = n - only1 - only2 - shared <= 0;
				// printf("i: %d j: %d only1: %d only2: %d shared: %d bisa: %d\n", i,j,only1,only2, shared, bisa);
				if(bisa){found = true; break;}
			}
			if(found) break;
		}

		found ? puts("YES"): puts("NO");
	}
	
	return 0;
};