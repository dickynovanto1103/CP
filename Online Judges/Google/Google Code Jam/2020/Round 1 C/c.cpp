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
	int tc,n,d,i,j;
	ll a[100001];
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		scanf("%d %d",&n,&d);
		map<ll, int> mapper;
		multiset<ll> s;
		multiset<ll>::iterator it;
		for(i=0;i<n;i++){scanf("%lld",&a[i]); mapper[a[i]]++;}
		sort(a, a+n);

		if(d == 2){
			int ans = 1;
			for(i=0;i<n;i++){
				int cnt = mapper[a[i]];
				if(cnt >= 2){ans = 0; break;}
			}
			printf("%d\n",ans);
		}else{
			int ans = 2;
			for(i=0;i<n;i++){
				int cnt = mapper[a[i]];
				if(cnt >= 3){ans = 0; break;}
			}
			if(ans == 0){printf("0\n"); continue;}
			for(i=0;i<n;i++){
				int cnt = mapper[a[i]];
				if(cnt == 2){
					if(a[n-1] > a[i]){
						ans = 1;
						break;
					}
				}
			}
			if(ans == 1){printf("1\n"); continue;}
			for(i=0;i<n;i++){
				int cnt = mapper[a[i]];

				if(cnt == 1){
					int cnt1 = mapper[2LL*a[i]];
					if(cnt1){
						ans = 1;
						break;
					}
				}
			}
			if(ans == 1){printf("1\n"); continue;}
			printf("2\n");
		}

	}
	
	return 0;
};