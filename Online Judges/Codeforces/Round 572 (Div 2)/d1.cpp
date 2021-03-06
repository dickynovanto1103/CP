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

int deg[100010];

int main(){
	int n,i,j;
	scanf("%d",&n);
	for(i=0;i<n-1;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		deg[a]++; deg[b]++;
	}
	ll cnt = 0;
	for(i=1;i<=n;i++){
		if(deg[i] == 1){cnt++;}
	}
	if((cnt*(cnt-1LL))/2LL >= (n-1)){printf("YES\n");}
	else{printf("NO\n");}
	return 0;
};