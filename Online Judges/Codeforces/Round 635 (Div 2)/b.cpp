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
	int tc,x,n,m,i;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d %d",&x,&n,&m);
		bool bisa = false;
		for(i=0;i<n;i++){
			int akhir = (x / 2) + 10;
			if(akhir >= x){break;}
			x = akhir;
			if(x <= 0){bisa = true; break;}
		}

		for(i=0;i<m;i++){
			x -= 10;
			if(x <= 0){bisa = true; break;}
		}
		if(bisa){printf("YES\n");}
		else{printf("NO\n");}
	}
	return 0;
};