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

const int maxn = 2e5 + 5;

bool cmp(ii a, ii b){
	return a.second < b.second;
}

int main(){
	int n,i,j;
	ii pas[maxn];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d %d",&pas[i].first, &pas[i].second);
	}
	sort(pas, pas+n, cmp);
	ll time = 0;
	for(i=0;i<n;i++){
		time += pas[i].first;
		if(time > pas[i].second){printf("No\n"); return 0;}
	}
	printf("Yes\n");
	return 0;
};