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
		int a[101];
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		sort(a, a+n);
		vi list[2];
		if(a[0] != 0){printf("0\n");}
		else{
			
			for(i=0;i<n;i++){
				bool found = false;
				// printf("i: %d\n",i);
				for(j=0;j<2;j++){
					if(list[j].size()) {
						int last = list[j].back();
						int expected = last + 1;
						if(a[i] == expected){
							found = true;
							list[j].pb(a[i]);
							// printf("push ke %d a[%d]: %d\n",j, i, a[i]);
							break;
						}
					}else{
						list[j].pb(a[i]);
						// printf("push ke %d a[%d]: %d\n",j, i, a[i]);
						break;
					}
				}
				if(!found){
					list[0].pb(a[i]);
					// printf("push ke 0: %d\n",a[i]);
				}
			}
			int mex = 0;
			for(j=0;j<2;j++){
				int m = 0;
				set<int> s;
				for(i=0;i<list[j].size();i++){
					s.insert(list[j][i]);
				}
				for(i=0;i<=101;i++){
					if(s.find(i) == s.end()){
						m = i;
						break;
					}
				}
				// printf("m: %d\n",m);
				mex += m;
			}
			printf("%d\n",mex);
		}
		
	}
	
	return 0;
};