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
		ll minEdge = n-1;
		ll maksEdge = (ll)n*(n-1)/2LL;
		if(m < minEdge || m > maksEdge){printf("NO\n");continue;}
		//jumlah edge valid
		
		int maksDiameter = k-2;
		if(maksDiameter < 0){printf("NO\n"); continue;}
		else if(maksDiameter == 0){
			if(n == 1){printf("YES\n"); continue;}
			else{printf("NO\n");}
		}else if(maksDiameter == 1) {
			if(n <= 2){printf("YES\n");}
			else {
				if(m < maksEdge){printf("NO\n");}
				else{printf("YES\n");}
			}
		}else{
			printf("YES\n");
		}
		// if(n == 1 && maksDiameter >= 0){printf("YES\n"); continue;}
		// if(n == 2 && maksDiameter >= 1){printf("YES\n"); continue;}
		// if(maksDiameter == 1 && m < maksEdge)
	}
	
	return 0;
};