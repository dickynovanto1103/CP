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

ll l[1000001], h[1000001], w[1000001];
ll p[1000001];

const ll mod = 1e9 + 7;

int main(){
	int n,k,i,j,tc;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		scanf("%d %d",&n,&k);
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

		for(i=0;i<k;i++){scanf("%lld",&w[i]);}

		scanf("%lld %lld %lld %lld",&al,&bl,&cl,&dl);
		for(i=k;i<n;i++){
			w[i] = al*w[i-2]; w[i] %= dl;
			w[i] += bl*w[i-1]; w[i] %= dl;
			w[i] += cl; w[i] %= dl;
			w[i]++;
		}
		// for(i=0;i<n;i++){
		// 	printf("w[%d]: %lld\n",i, w[i]);
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

		//solve
		set<ii> s;
		set<ii>::iterator it;
		s.insert(ii(-1000, 2000000000));
		for(i=0;i<n;i++){
			int start = l[i], end = l[i] + w[i];
			int height = h[i];
			// printf("\n\nstart: %d end: %d height: %d\n",start, end, height);
			set<ii> toInsert, toRemove;
			ll kel = 0;
			set<ii>::iterator itLow = s.lower_bound(ii(start, start));
			if(itLow == s.end()){
				itLow--;
			}
			ii pas = *itLow;
			if(pas.first > start) {
				itLow--;
			}

			for( it = itLow; it!=s.end();it++ ){
				ii pas = *it;
				// printf("pas: %d %d\n",pas.first, pas.second);
				if(pas.first >= end) { //no need to check this
					break;
				}
				if(pas.first < start && pas.second > start && pas.first < end && pas.second > end) {
					toInsert.insert(ii(pas.first, start));
					toInsert.insert(ii(end, pas.second));
					toRemove.insert(pas);
					kel += 2LL*(end - start + height);
					continue;
				}
				if(pas.first < start && pas.second > start) {
					toInsert.insert(ii(pas.first, start));
					toRemove.insert(pas);
					kel += 2LL*(pas.second - start);
					// printf("kel: %d\n",kel);
				}
				if(pas.first < end && pas.second > end) {
					toInsert.insert(ii(end, pas.second));
					toRemove.insert(pas);
					kel += 2LL*(end - pas.first);
					// printf("kel here: %d\n",kel);
				}
				if(pas.first >= start && pas.second <= end) {//di tengah
					toRemove.insert(pas);
					kel += 2LL*(pas.second - pas.first); //karena atas dan bawah
					kel -= 2LL*height;
					// printf("kel total: %d\n",kel);
				}

			}
			for(it = toRemove.begin(); it!=toRemove.end();it++){
				ii pas = *it;
				// printf("remove: %d %d\n",pas.first, pas.second);
				s.erase(pas);
			}
			for(it = toInsert.begin(); it!=toInsert.end();it++){
				ii pas = *it;
				// printf("insert %d %d\n",pas.first, pas.second);
				s.insert(pas);
			}
			if(i == 0){
				p[i] = kel;
			}else{
				p[i] = kel + p[i-1];
			}
			
			p[i] %= mod;
			if(p[i] < 0){p[i] += mod;}
			// printf("p[%d]: %lld\n",i, p[i]);
		}
		ll ans = 1;
		for(i=0;i<n;i++){
			ans *= p[i];
			ans %= mod;
		}
		printf("Case #%d: %lld\n",tt, ans);
		// p[0] = 2LL*(w + h[0]);
		
	}
	
	return 0;
};