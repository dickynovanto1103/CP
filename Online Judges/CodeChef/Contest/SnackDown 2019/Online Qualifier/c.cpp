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

const int maxn = 1e5 + 5;

int main(){
	int tc,i,j;
	int n,a[maxn];
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		for(i=0;i<n;i++){scanf("%d",&a[i]);}
		int ans = 0;
		ll cur = a[0];
		ll sisa = n-1;
		int idx = 0;

		while(sisa > 0){
			ll tempCur = cur;
			for(i=idx+1;i<=(idx+tempCur);i++){
				if(i >= n){break;}
				cur+=a[i];
				sisa--;
			}
			idx = i-1;
			ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
};