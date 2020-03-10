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
	int tc,n,i;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		int ans = 0;
		for(i=1;i*i<=n;i++){
			if(n % i == 0){
				int satu = i;
				int dua = n/i;
				if(satu == dua){
					if(satu % 2 == 0){
						ans++;
					}
				}else{
					if(satu % 2 == 0){
						ans++;
					}
					if(dua % 2 == 0){
						ans++;
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
};