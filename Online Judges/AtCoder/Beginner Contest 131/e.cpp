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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	int i,j;
	int maks = (n-1) * (n-2) / 2;
	vii edge;
	if(k > maks){
		printf("-1\n");
	}else{
		for(i=2;i<=n;i++){
			edge.pb(ii(1,i));
		}
		if(maks == k){goto here;}
		for(i=2;i<=n;i++){
			for(j=i+1;j<=n;j++){
				edge.pb(ii(i,j));
				maks--;
				if(maks == k){goto here;}
			}
		}
		here:;
		printf("%d\n",(int)edge.size());
		for(i=0;i<edge.size();i++){
			printf("%d %d\n",edge[i].first, edge[i].second);
		}
		
	}
	return 0;
};