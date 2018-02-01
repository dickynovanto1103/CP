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
	int tc,n,i,j;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		int a[1001], b[1010];
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		for(i=0;i<=n;i++){
			if(i==0 || i==n){
				if(i==0){b[i] = a[i];}
				else{b[i] = a[i-1];}
			}else{
				b[i] = a[i]*(a[i-1]/__gcd(a[i],a[i-1]));
			}
		}
		for(i=0;i<=n;i++){
			if(i){printf(" ");}
			printf("%d",b[i]);
		}
		printf("\n");
	}
	
	return 0;
};