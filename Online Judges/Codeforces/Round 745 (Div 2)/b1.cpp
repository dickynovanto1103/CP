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
	int tc,i,j,n,m,k;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d %d",&n,&m,&k);
		if(m > (n-1ll)*n>>1 || m < n-1){puts("NO"); continue;}

		int maksDiameter = k-2;
		if(n == 1){
			if(maksDiameter >= 0){puts("YES");}
			else{puts("NO");}
		}else if(m < (n-1ll)*n>>1){
			if(maksDiameter >= 2){puts("YES");}
			else{puts("NO");}
		}else if(maksDiameter >= 1){//complete graph but maksDiameter >= 1
			puts("YES");
		}else{//complete graph but maksDiameter <= 0
			puts("NO");
		}
	}
	
	return 0;
};