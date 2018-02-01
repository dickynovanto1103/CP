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

int main(){
	int a,b,c,tc,i,j;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d %d",&a,&b,&c);
		//if(c==a || c==b){printf("YES\n");continue;}
		if(c>a && c>b){printf("NO\n"); continue;}

		int gcd = __gcd(a,b);
		if(c%gcd==0){printf("YES\n");}
		else{printf("NO\n");}
	}
	
	return 0;
};