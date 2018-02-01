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

const int maxn = 5e4 + 10;

ll lef[maxn], rig[maxn];
ll clef[maxn], crig[maxn];
ll tot[maxn];
int main(){
	int n,m,tc,i,j;
	scanf("%d",&tc);
	int test = 1;
	while(tc--){
		printf("test: %d\n",test++);
		memset(lef,0,sizeof lef); memset(rig,0,sizeof rig);
		memset(clef,0,sizeof clef); memset(crig,0,sizeof crig);
		memset(tot,0,sizeof tot);

		scanf("%d %d",&n,&m);
		while (m--) {
	      	long long x, k;
	     	scanf("%lld %lld", &x, &k);
	      	if (x -1 >= 0) lef[x - 1] += k - 1;
	      	rig[x] += k;
	       
	      	crig[x]++;
	      	if (x + k < n) crig[x + k]--;

	      	if (x - 1 >= 0) clef[x - 1]++;
	      	if (x - k >= 0) clef[x - k]--;

	      	printf("lef:\n");
	      	for(i=0;i<=n;i++){
	      		if(i){printf(" ");}
	      		printf("%lld",lef[i]);
	      	}
	      	printf("\n");
	      	printf("rig:\n");
	      	for(i=0;i<=n;i++){
	      		if(i){printf(" ");}
	      		printf("%lld",rig[i]);
	      	}
	      	printf("\n");
	      	printf("clef:\n");
	      	for(i=0;i<=n;i++){
	      		if(i){printf(" ");}
	      		printf("%lld",clef[i]);
	      	}
	      	printf("\n");
	      	printf("crig:\n");
	      	for(i=0;i<=n;i++){
	      		if(i){printf(" ");}
	      		printf("%lld",crig[i]);
	      	}
	      	printf("\n");

	    }
	    printf("\n");
	}
	return 0;
};