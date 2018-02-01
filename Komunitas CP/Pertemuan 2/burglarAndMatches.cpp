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

bool cmp(ii a, ii b){return a.second > b.second;}

int main(){
	int n,m;
	int i;
	scanf("%d %d",&n,&m);
	ii pas[25];
	for(i=0;i<m;i++){
		scanf("%d %d",&pas[i].first,&pas[i].second);
	}
	sort(pas,pas+m,cmp);
	int ans = 0;
	for(i=0;i<m;i++){
		int banyak = pas[i].first, nilai = pas[i].second;
		//printf("banyak: %d nilai: %d\n",banyak,nilai);
		if(n>=banyak){n-=banyak; ans+=(banyak*nilai);}
		else{ans+=(n*nilai); n = 0;  break;}
	}
	printf("%d\n",ans);
	
	
	return 0;
};