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
	int n,k,i,j;
	string kata;
	scanf("%d %d",&n,&k);
	cin>>kata;
	int cnt[27];
	memset(cnt,0,sizeof cnt);
	for(i=0;i<n;i++){
		char kar = kata[i];
		cnt[kar - 'A']++;
	}
	int minim = inf;
	for(i=0;i<k;i++){
		minim = min(minim, cnt[i]);
	}
	printf("%d\n",minim*k);
	return 0;
};