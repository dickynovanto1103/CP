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
	freopen("looking.in", "r", stdin);
	int tc,i,j;
	scanf("%d",&tc);
	int a[maxn];

	while(tc--){
		int n,m;
		scanf("%d %d",&n,&m);
		int atau = 0;
		for(i=0;i<n;i++){scanf("%d",&a[i]); atau |= a[i];}
		printf("%d\n",atau);
	}

	return 0;
};