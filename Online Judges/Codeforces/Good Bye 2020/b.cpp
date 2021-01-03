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
	int cnt[200010];
	while(tc--){
		scanf("%d",&n);
		int a[100010];
		for(i=1;i<=2*n+2;i++){
			cnt[i] = 0;
		}
		int ans = 0;
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			cnt[a[i]]++;
			if(cnt[a[i]] == 1){ans++;}
		}
		for(i=n-1;i>=0;i--){
			//move up this num
			int tempAns = ans;
			cnt[a[i]]--;
			if(cnt[a[i]] == 0){tempAns--;}
			cnt[a[i]+1]++;
			if(cnt[a[i] + 1] == 1){tempAns++;}
			if(tempAns < ans){
				//rollback
				cnt[a[i]]++;
				cnt[a[i] + 1]--;
			}else{
				ans = tempAns;
			}
		}
		printf("%d\n",ans);
	}
	
	return 0;
};