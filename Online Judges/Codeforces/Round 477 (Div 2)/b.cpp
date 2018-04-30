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

const int maxn = 1e5 + 5;

int main(){
	int n,a,b;
	int s[maxn],i,j;
	scanf("%d %d %d",&n,&a,&b);
	ll tot = 0;
	for(i=0;i<n;i++){
		scanf("%d",&s[i]);
		tot += s[i];
	}

	sort(s+1,s+n);
	double ans1 = ((double)s[0]*(double)a) / (double)tot;
	if(fabs(ans1-b)<eps || (ans1-b) > eps){
		printf("0\n"); return 0;
	}

	int cnt = 1;
	for(i=n-1;i>=1;i--){
		tot-=s[i];
		ans1 = ((double)s[0]*(double)a) / (double)tot;
		if(fabs(ans1-b)<eps || (ans1-b) > eps){
			printf("%d\n",cnt); return 0;
		}		
		cnt++;
	}
	printf("%d\n",cnt);
	return 0;
};