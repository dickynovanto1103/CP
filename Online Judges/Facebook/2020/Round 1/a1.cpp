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
typedef pair<ii,int> iii;
typedef vector<ii> vii;

ll l[1000001], h[1000001];
ll p[1000001];

const ll mod = 1e9 + 7;

int main(){
	int n,k,i,j,tc;
	ll w;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		scanf("%d %d %lld",&n,&k,&w);
		for(i=0;i<k;i++){
			scanf("%lld",&l[i]);
		}
		ll al, bl, cl, dl;
		scanf("%lld %lld %lld %lld",&al,&bl,&cl,&dl);
		for(i=k;i<n;i++){
			l[i] = al*l[i-2]; l[i] %= dl;
			l[i] += bl*l[i-1]; l[i] %= dl;
			l[i] += cl; l[i] %= dl;
			l[i]++;
		}
		// for(i=0;i<n;i++){
		// 	printf("l[%d]: %lld\n",i, l[i]);
		// }

		for(i=0;i<k;i++){
			scanf("%lld",&h[i]);
		}
		scanf("%lld %lld %lld %lld",&al,&bl,&cl,&dl);
		for(i=k;i<n;i++){
			h[i] = al*h[i-2]; h[i] %= dl;
			h[i] += bl*h[i-1]; h[i] %= dl;
			h[i] += cl; h[i] %= dl;
			h[i]++;
		}
		// for(i=0;i<n;i++){
		// 	printf("h[%d]: %lld\n",i, h[i]);
		// }

		set<iii> s;
		set<iii>::iterator it, itLow;
		set<iii>::reverse_iterator itRev;
		iii last = iii(ii(-1,-1), -1);
		for(i=0;i<n;i++){
			ll kel = 0;
			int start = l[i], end = l[i] + w;
			int height = h[i];
			// printf("start: %d end: %d height: %d\n",start,end,height);
			if(s.empty()){
				kel = 2LL*(end - start + height);
				s.insert(iii(ii(start+1,end), height));
				// printf("inserted %d %d %d\n", start + 1, end, height);
				last = iii(ii(start, end), height);
				p[0] = kel;
				p[0] %= mod;
				// printf("p[0]: %lld\n",p[0]);
				continue;
			}
			if(start <= last.first.second){
				itLow = s.lower_bound(iii(ii(start, start), 0));
				if(itLow == s.end()){
					itLow--;
				}
				iii pas = *itLow;
				if(pas.first.first > start){
					itLow--;
				}
				pas = *itLow;	
				int curHeight = pas.second;
				// printf("curHeight: %d\n",curHeight);
				if(curHeight > height) {
					//di end pasti blm ada segment, insert new segment in set, ((last.end + 1,end), height)
					kel += 2LL*(end - last.first.second);
					kel %= mod;
				}else{
					kel += 2LL*(height-curHeight); kel %= mod;
					kel += 2LL*(end - last.first.second); kel %= mod;

				}
				//benerkah harus remove"
				vector<iii> toRemove;
				iii bener;
				for(itRev = s.rbegin(); itRev!=s.rend(); itRev++){
					iii pas = *itRev;
					// printf("halo pas: %d %d %d\n",pas.first.first, pas.first.second, pas.second);
					if(pas.second < height) {
						toRemove.pb(pas);
					}else{
						bener = pas;
						break;
					}
				}
				for(j=0;j<toRemove.size();j++){
					iii pas = toRemove[j];
					// printf("erased: %d %d %d\n",pas.first.first, pas.first.second, pas.second);
					s.erase(pas);
				}
				// printf("bener: %d %d %d\n",bener.first.first, bener.first.second, bener.second);

				if(bener.first.second >= start){
					s.insert(iii(ii(bener.first.second + 1, end), height));	
				}else{
					s.insert(iii(ii(start + 1, end), height));
					// printf("inserted: %d %d %d\n",start + 1, end, height);
				}
				
			}else{
				kel = 2LL*(end - start + height);
				s.clear();
				s.insert(iii(ii(start+1,end), height));
			}
			last = iii(ii(start, end), height);
			p[i] = kel + p[i-1];
			p[i] %= mod;
			// printf("p[%d]: %lld kel: %lld\n",i, p[i], kel);
			
			
		}

		ll ans = 1;
		for(i=0;i<n;i++){
			ans *= p[i];
			ans %= mod;
		}
		printf("Case #%d: %lld\n",tt,ans);
	}
	
	return 0;
};