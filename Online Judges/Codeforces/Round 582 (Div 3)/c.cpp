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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	while(tc--){
		ll n,m;
		scanf("%lld %lld",&n,&m);
		ll tot = n/m;
		ll last = m%10;
		ll temp = last;
		int cnt;
		ll sum = temp;
		for(cnt=1;;cnt++){
			last += m;
			last %= 10;
			if(last == temp){break;}
			sum += last;
		}
		ll loop = tot / cnt;
		// printf("tot: %lld cnt: %lld\n",tot, cnt);
		// printf("loop: %lld\n",loop);
		ll ans = sum * loop;
		ll sisa = tot % cnt;
		// printf("sisa: %lld ans: %lld\n",sisa, ans);
		for(i=0;i<sisa;i++){
			ans += temp;
			temp += m;
			temp %= 10;
			
		}
		printf("%lld\n",ans);
	}
	return 0;
};