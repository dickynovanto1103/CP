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

const int maxn = 1e5 +5;

int main(){
	int n,i,j;
	int a[maxn];
	int minim = inf;
	scanf("%d",&n);

	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		minim = min(minim,a[i]);
	}
	vi listIdxMin;
	for(i=0;i<n;i++){
		if(a[i]==minim){listIdxMin.pb(i);}
	}
	int ans = inf;
	for(i=0;i<listIdxMin.size()-1;i++){
		ans = min(ans,listIdxMin[i+1]-listIdxMin[i]);
	}
	printf("%d\n",ans);
	return 0;
};