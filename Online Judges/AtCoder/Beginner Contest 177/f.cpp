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
typedef pair<ii,int> iii;
typedef vector<ii> vii;
typedef vector<iii> viii;

int minLevel[200002];
int a[200002], b[200002];

bool cmp(iii a, iii b){
	if(a.first.first == b.first.first){
		return a.second < b.second;
	}
	return a.first.first < b.first.first;
}

int main(){
	int h,w,i,j;
	scanf("%d %d",&h,&w);
	viii v;
	for(i=1;i<=w;i++){
		minLevel[i] = inf;
	}
	for(i=1;i<=h;i++){
		scanf("%d %d",&a[i],&b[i]);
		v.pb(iii(ii(a[i], b[i]), i));
	}
	sort(v.begin(), v.end());
	int last = -1;
	for(i=0;i<h;i++){
		ii pas = v[i].first;
		int level = v[i].second;
		for(j=last+1;j<=pas.second;j++){
			minLevel[j] = min(minLevel[j], level);
			last = j;
		}
	}

	for(i=1;i<=w;i++){
		//coba satu2
		int minimLevel = minLevel[i];
		//simulasi?
		
	}
	
	return 0;
};