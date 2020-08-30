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

const int maxn = 1e6 + 3;

ll s[maxn], x[maxn], y[maxn];

int main(){
	int tc,i,j,n,k;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		ll as,bs,cs,ds;
		ll ax,bx,cx,dx;
		ll ay,by,cy,dy;
		printf("Case #%d: ",tt);
		scanf("%d %d",&n,&k);
		ll totCustomer = 0;
		for(i=0;i<k;i++){
			scanf("%lld",&s[i]);
			totCustomer += s[i];
		}
		scanf("%lld %lld %lld %lld",&as,&bs,&cs,&ds);
		
		for(i=k;i<n;i++){
			s[i] = (as * s[i-2] + bs * s[i-1] + cs);
			s[i] %= ds;
			totCustomer += s[i];
		}

		for(i=0;i<k;i++){
			scanf("%lld",&x[i]);
		}
		scanf("%lld %lld %lld %lld",&ax,&bx,&cx,&dx);
		for(i=k;i<n;i++){
			x[i] = (ax * x[i-2] + bx * x[i-1] + cx);
			x[i] %= dx;
		}
		for(i=0;i<k;i++){
			scanf("%lld",&y[i]);
		}
		scanf("%lld %lld %lld %lld",&ay,&by,&cy,&dy);
		for(i=k;i<n;i++){
			y[i] = (ay * y[i-2] + by * y[i-1] + cy);
			y[i] %= dy;
		}
		
		ll minCustomer = 0, maxCustomer = 0;
		for(i=0;i<n;i++){
			minCustomer += x[i];
			maxCustomer += (x[i] + y[i]);
		}
		if(minCustomer > totCustomer){
			printf("-1\n");
			continue;
		}else if(maxCustomer < totCustomer) {
			printf("-1\n");
			continue;
		}

		ll totButuh = 0, totOverload = 0, totKursiKosong = 0, totBisaPindah = 0;
		for(i=0;i<n;i++){
			ll minimKursi = x[i];
			ll maksKursi = x[i] + y[i];
			if(s[i] < minimKursi) {
				totButuh += (x[i] - s[i]);
			} else if (s[i] <= maksKursi) {
				totKursiKosong += (maksKursi - s[i]);
				totBisaPindah += (s[i] - x[i]);
			} else {
				assert(s[i] > maksKursi);
				totOverload += (s[i] - maksKursi);
			}
		}
		ll minim = min(totButuh, totOverload);
		ll ans = minim;
		totButuh -= minim; totOverload -= minim;
		ans += totButuh; ans += totOverload;
		printf("%lld\n",ans);
	}
	
	return 0;
};