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
	int tc,i,j,n,k;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		scanf("%d %d",&n,&k);
		vii a;
		for(i=0;i<n;i++){
			int x,y;
			scanf("%d %d",&x,&y);
			a.pb(ii(x,y));
		}
		sort(a.begin(), a.end());
		ll curTime = a[0].first;
		int idx = 0;
		ll ans = 0;
		while(idx < n){
			int idx = lower_bound(a.begin(), a.end(), ii(curTime, 0)) - a.begin();
			//this is the start time;
			// printf("idx: %d curTime: %lld\n",idx, curTime);
			bool janganBerubah = false;
			if(idx > 0 && idx <= n){
				//cek sebelum
				idx--;
				ii interval = a[idx];
				if(interval.first <= curTime && curTime < interval.second){
					janganBerubah = true;
				}else{
					idx++;
				}
			}
			//sudah dicek dan sudah selesai
			if(idx == n){
				break;
			}
			if(!janganBerubah){
				curTime = a[idx].first;	
			}
			
			ii interval = a[idx];
			int waktu = interval.second - curTime;
			int banyakRobot = (waktu + k - 1) / k;
			ans += banyakRobot;
			curTime += (ll)banyakRobot * k;
		}
		printf("%lld\n",ans);
	}
	
	return 0;
};