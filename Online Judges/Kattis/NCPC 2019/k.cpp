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
	int n,m,s,d,i,j;
	scanf("%d %d %d %d",&n,&m,&s,&d);
	ii a[101];
	int temp[101];
	for(i=0;i<s;i++){
		scanf("%d",&a[i].first);
		a[i].second = i;
		temp[i] = a[i].first;
	}
	sort(a, a+s);
	int now = n;
	int ans[101];
	memset(ans, 0, sizeof ans);
	for(i=0;i<s;i++){
		int sisa = d - a[i].first;
		int idx = a[i].second;
		ans[idx] += min(now, sisa);
		now -= min(now, sisa);
	}
	int sum = 0;
	for(i=0;i<s;i++){
		if(ans[i] == 0){
			sum += temp[i];
		}
	}
	if(sum < m){printf("impossible\n");}
	else{
		for(i=0;i<s;i++){
			if(i){printf(" ");}
			printf("%d",ans[i]);
		}
		printf("\n");
	}
	return 0;
};