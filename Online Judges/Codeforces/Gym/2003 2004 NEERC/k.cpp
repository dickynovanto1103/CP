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
#define fi first
#define se second

int n,m,i,j,k;
set<pair<ii, int>> wew;
map<int, int> mep;
int a[200000];

int main(){
	scanf("%d %d", &n, &m);
	for(i=0;i<n;++i){
		scanf("%d", a+i);
		wew.insert({{a[i], mep[a[i]]--}, i});
	}
	int now = 1;
	for(const pair<ii, int> &x : wew){
		while(now<x.fi.fi){
			printf("0 ");
			now++;
		}
		printf("%d ", x.se);
		if(now==x.fi.fi)
			now++;
	}
	return 0;
};