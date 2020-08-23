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
	int a[200001];
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		int ans = 2;
		int cur = a[1] - a[0];
		int curAns = 2;
		for(i=2;i<n;i++){
			int diff = a[i] - a[i-1];
			if(diff == cur){
				curAns++;
				ans = max(ans, curAns);
			}else{
				curAns = 2;
				cur = diff;
			}
		}
		printf("%d\n",ans);
	}
	
	return 0;
};