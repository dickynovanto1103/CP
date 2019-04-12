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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1e5 + 5;

ii a[maxn];

bool cmp(ii a, ii b){
	if(a.first == b.first){return a.second > b.second;}
	return a.first < b.first;
}

ii intersect(ii a, ii b){
	int x = max(a.first, b.first);
	int y = min(a.second, b.second);
	if(x > y){return ii(-1,-1);}
	return ii(x,y);
}

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	while(tc--){
		int n;
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d %d",&a[i].first, &a[i].second);	
		}
		sort(a,a+n, cmp);
		vii listBil;
		for(i=0;i<n;i++){
			if(listBil.empty()){
				listBil.pb(a[i]);
			}else{
				ii back = listBil.back();
				ii baru = intersect(back, a[i]);

				if(baru == ii(-1,-1)){
					listBil.pb(a[i]);
				}else{
					listBil.pop_back();
					listBil.pb(baru);
				}
			}
		}
		printf("%d\n",(int)listBil.size());
	}
	return 0;
};