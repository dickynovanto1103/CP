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
	int tc,i,j,n,x,y;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d %d",&n,&x,&y);
		bool found = false;
		vi ans;
		for(j=y;j<=2450;j++){
			for(i=1;i<=x;i++) {
				int selisih = j - i;
				//check if it is divisible by n-1
				if(selisih % (n-1) == 0) {
					//check if x exist and y exist
					int delta = selisih / (n-1);
					if((x - i) % delta == 0 && (y - i) % delta == 0){
						found = true;
						for(int k=i;k<=j;k+=delta){
							ans.pb(k);
						}
						break;
					}
				}
			}
			if(found){break;}
		}
		
		assert(ans.size() == n);
		for(i=0;i<ans.size();i++){
			if(i){printf(" ");}
			printf("%d",ans[i]);
		}
		printf("\n");
	}
	
	return 0;
};