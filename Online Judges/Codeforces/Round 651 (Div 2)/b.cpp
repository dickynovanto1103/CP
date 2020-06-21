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
	int tc,i,j,n;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		vi gn, gj;
		for(i=0;i<2*n;i++){
			int bil;
			scanf("%d",&bil);
			if(bil % 2 == 1){
				gj.pb(i+1);
			}else{
				gn.pb(i+1);
			}
		}
		if(gn.size() % 2 == 1){
			gn.pop_back();
			gj.pop_back();
		}else{
			if(gn.size() > 0){
				gn.pop_back();
				gn.pop_back();
			}else{
				gj.pop_back();
				gj.pop_back();
			}
		}
		for(i=0;i<gn.size();i+=2){
			printf("%d %d\n",gn[i], gn[i+1]);
		}
		for(i=0;i<gj.size();i+=2){
			printf("%d %d\n",gj[i], gj[i+1]);
		}
	}
	
	return 0;
};