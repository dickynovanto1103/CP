#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

ll nextGenap(ll a, ll batas){
	if(a==batas){return 2;}
	return a+2;
}

ll a[500010];

int main() {
	
	int i;
	a[1] = 1; a[2] = 2; a[3] = 2;
	//printf("cout\n");
	for(i=4;i<=500000;i++){
		if(i%2==0){
			a[i] = 2*a[i/2];
		}else{
			ll maks = i-1;
			ll bil = 2*a[i/2];
			a[i] = nextGenap(bil,maks);
		}
	}
	//for(i=1;i<=17;i++){printf("i: %d a: %lld\n",i,a[i]);}
	int bil;
	while(scanf("%d",&bil),bil){
		printf("%lld\n",a[bil]);
	}
	return 0;
}