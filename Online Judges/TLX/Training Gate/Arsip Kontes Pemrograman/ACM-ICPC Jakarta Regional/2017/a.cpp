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
	int n,m,test[110], lolos[110][110],i,j, banyakAc[110];
	scanf("%d %d",&n,&m);
	memset(banyakAc,0,sizeof banyakAc);
	for(i=0;i<m;i++){scanf("%d",&test[i]);}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&lolos[i][j]);	
			if(lolos[i][j]==test[j]){banyakAc[i]++;}
		}
	}
	int idx = 0, maks = -inf;
	for(i=0;i<n;i++){
		if(maks < banyakAc[i]){
			maks = banyakAc[i];
			idx = i;
		}
	}
	printf("%d\n",idx+1);
	return 0;
};