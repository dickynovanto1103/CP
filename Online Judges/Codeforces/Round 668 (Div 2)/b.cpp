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
	int tc,i,j;
	int n;
	int a[100001];
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		ll totPos = 0;
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			if(a[i] < 0){
				ll minim = min(totPos, (ll)-a[i]);
				totPos -= minim;
			}else{
				totPos += a[i];
			}
		}
		printf("%lld\n",totPos);
	}
	
	return 0;
};