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
#define debug if(true)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	int minim = inf;
	for(i=0;i<=n/2;i++){
		int step = i;
		int cnt = step*2;
		int sisa = n-cnt;
		if((step + sisa) % m == 0){
			minim = min(minim, step + sisa);
		}
	}

	printf("%d\n",(minim == inf ? -1 : minim));
	return 0;
};