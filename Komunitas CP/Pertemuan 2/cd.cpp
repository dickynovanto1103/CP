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

set<int> a;

int main(){
	int n,m;
	while(scanf("%d %d",&n,&m),(n||m)){
		//printf("n: %d m: %d\n",n,m);
		int i,j,bil;
		for(i=0;i<n;i++){scanf("%d",&bil); a.insert(bil);}
		int cnt = 0;
		for(i=0;i<m;i++){
			scanf("%d",&bil);
			if(a.find(bil)!=a.end()){cnt++;}
		}
		printf("%d\n",cnt);
		a.clear();
	}
	return 0;
};