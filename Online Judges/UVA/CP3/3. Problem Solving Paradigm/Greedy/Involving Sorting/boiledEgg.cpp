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

int main() {
	int tc,n,p,q,i,a[35];
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case %d: ",tt);
		scanf("%d %d %d",&n,&p,&q);
		for(i=0;i<n;i++){scanf("%d",&a[i]);}
		int cnt = 0, sum = 0;
		for(i=0;i<n;i++){
			if(i+1 > p){break;}
			sum+=a[i];
			if(sum<=q && i+1<=p){cnt++;}
		}
		printf("%d\n",cnt);
	}
	return 0;
}