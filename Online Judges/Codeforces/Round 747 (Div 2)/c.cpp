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

const int maxn = 3e5 + 5;

bitset<maxn> vis;

int main(){
	int tc,i,j,n;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		char c;
		cin>>c;
		string s;
		cin>>s;

		for(i=1;i<=n;i++){
			vis[i] = false;
			if(s[i-1] != c) vis[i] = true;
		}

		if(vis.count() == 0) {
			puts("0");
			continue;
		}else if(!vis[n]) {
			puts("1");
			printf("%d\n", n);
			continue;
		}

		//find what index will be the best..find that can result in one step
		int ans = -1;
		for(i=2;i<n;i++){
			bool can = true;
			for(j=i;j<=n;j+=i){
				if(vis[j]) can = false; break;
			}
			if(can){
				ans = i;
				break;
			}
		}
		if(ans != -1) {
			puts("1");
			printf("%d\n", i);
		}else{
			puts("2");
			printf("%d %d\n", n, n-1);
		}

	}
	
	return 0;
};