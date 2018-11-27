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
	int n,i,j;
	int a[101];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	vector<int> v;
	int cur = a[0];
	v.pb(cur);
	int ans = 0;
	for(i=1;i<n;i++){
		if(a[i] - cur == 1){
			v.pb(a[i]);
			cur = a[i];
		}else{
			if(v.size() >= 2){
				if(v[0] == 1){ans = max(ans, (int)v.size() - 1);}
				else{ans = max(ans, (int)v.size() - 2);}	
			}
			
			v.clear();
			v.pb(a[i]);
			cur = a[i];
		}
	}
	if(!v.empty()){
		int pertama = v[0];
		int akhir = v[v.size() - 1];
		if(v.size() >= 2){
			if(pertama == 1){
				ans = max(ans, (int)v.size() - 1);
			}else if(akhir == 1000){
				if(v.size() == n){
					ans = max(ans, (int)v.size() - 1);
				}else{
					ans = max(ans, (int)v.size() - 1);	
				}
				
			}else{
				ans = max(ans, (int)v.size() - 2);
			}	
		}
		
		
	}
	printf("%d\n",ans);
	return 0;
};