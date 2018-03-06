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
	int tc,n,g,i,j;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&g);
		int stateAwal,q;
		int cnt[3];
		while(g--){
			scanf("%d %d %d",&stateAwal,&n,&q);
			memset(cnt,0,sizeof cnt);
			cnt[1] = n/2;
			cnt[2] = n/2;
			if(n%2==0){printf("%d\n",cnt[q]); continue;}
			if(stateAwal==1){cnt[2]++;}
			else{cnt[1]++;}
			printf("%d\n",cnt[q]);
		}
	}
	return 0;
};