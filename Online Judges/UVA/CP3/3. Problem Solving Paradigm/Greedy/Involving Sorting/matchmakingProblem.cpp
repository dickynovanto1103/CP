#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

bool cmp(int a, int b){return a>b;}

int main() {
	int test=1,n,m,a[10010],i;
	while(scanf("%d %d",&n,&m),(n||m)){
		printf("Case %d: ",test++);
		for(i=0;i<n;i++){scanf("%d",&a[i]);}
		int bil;
		for(i=0;i<m;i++){scanf("%d",&bil);}
		if(n<=m){printf("0\n");}
		else{
			sort(a,a+n,cmp);
			//for(i=0;i<n;i++){printf("%d\n",a[i]);}
			printf("%d %d\n",n-m,a[n-1]);
		}
	}
	return 0;
}