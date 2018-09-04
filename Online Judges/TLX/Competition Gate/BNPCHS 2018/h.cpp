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

bool cmp(ii a, ii b){
	return a.first < b.first;
}

ii intersect(ii a, ii b){
	return ii(max(a.first, b.first), min(a.second,b.second));
}

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	
	for(int tt=1;tt<=tc;tt++){
		printf("Kasus #%d: ",tt);
		int n;
		scanf("%d",&n);
		vii listBil;
		for(i=0;i<n;i++){
			int x,y;
			scanf("%d %d",&x,&y);
			listBil.pb(ii(x-y, x+y));	
			// printf("dipush ke listBil: %d %d\n",x-y,x+y);
		}
		sort(listBil.begin(), listBil.end(),cmp);
		vii ans;
		for(i=0;i<listBil.size();i++){
			if(ans.empty()){
				ans.pb(listBil[i]);
				// printf("dipush %d %d\n",listBil[i].first, listBil[i].second);
			}else{
				ii belakang = ans.back();
				ii jawab = intersect(belakang, listBil[i]);
				if(jawab.first > jawab.second){
					ans.pb(listBil[i]);
					// printf("yang dipush: %d %d\n",listBil[i].first, listBil[i].second);
				}else{
					// printf("dipop dulu yang belakang: %d %d\n",belakang.first, belakang.second);
					ans.pop_back();
					ans.pb(ii(jawab.first, jawab.second));
					// printf("yang dipush: %d %d\n",jawab.first, jawab.second);
				}
			}
		}
		printf("%d\n",(int)ans.size());	
	}
	
	return 0;
};