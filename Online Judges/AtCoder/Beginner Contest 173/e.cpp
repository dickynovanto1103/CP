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

bool cmp(int a, int b){
	return a > b;
}

const ll mod = 1e9 + 7;

vi neg, pos;
int cnt0 = 0;

int main(){
	int n,k,i,j;
	scanf("%d %d",&n,&k);
	ll a[200001];
	
	for(i=0;i<n;i++){
		int bil;
		scanf("%d",&bil);
		a[i] = bil;
		if(bil == 0){cnt0++;}
		else if(bil < 0){
			neg.pb(bil);
		}else{
			pos.pb(bil);
		}
	}

	sort(neg.begin(), neg.end(), cmp);
	sort(pos.begin(), pos.end());

	ll ans = 1;

	if(n == k){
		for(i=0;i<n;i++){
			ans *= a[i];
			ans %= mod;
		}
		if(ans < 0){ans += mod;}
		printf("%lld\n",ans);
		return 0;
	}

	if(k % 2 == 0){ //greedy
		while(k){
			//greedy, pilih terbaik
			ll posKali = 1, negKali = 1;
			int pos1, pos2, neg1, neg2;
			int cnt = 0;
			if(pos.size() >= 2) {
				// printf("halo\n");
				cnt |= 1;
				pos1 = pos.back();
				posKali *= pos.back(); pos.pop_back();
				pos2 = pos.back();
				posKali *= pos.back(); pos.pop_back();
			}

			if(neg.size() >= 2){
				cnt |= 2;
				neg1 = neg.back();
				negKali *= neg.back(); neg.pop_back();
				neg2 = neg.back();
				negKali *= neg.back(); neg.pop_back();
			}
			// printf("cnt: %d\n",cnt);

			if(cnt == 0){
				//berarti 0
				printf("0\n");
				return 0;
			}

			// printf("%lld %lld\n",posKali, negKali);

			if(posKali >= negKali){
				if(cnt & 2) {
					neg.pb(neg2); neg.pb(neg1); //balikin neg	
				}
				
				posKali %= mod;
				ans *= posKali;
			}else{
				if(cnt & 1) {
					pos.pb(pos2); pos.pb(pos1); //balikin pos	
				}
				
				negKali %= mod;
				ans *= negKali;
			}

			ans %= mod;
			k-=2;
		}
	}else{
		if(pos.size() == 0){
			if(cnt0){printf("0\n"); return 0;}
			else{
				ans = 1;
				for(i=0;i<k;i++){
					ans *= neg[i];
					ans %= mod;
				}
				if(ans < 0){ans += mod;}
			}
		}else{
			//ambil bil pertama
			ans = pos.back();
			pos.pop_back();
			k--;
			while(k){
				//greedy, pilih terbaik
				ll posKali = 1, negKali = 1;
				int pos1, pos2, neg1, neg2;
				int cnt = 0;
				if(pos.size() >= 2) {
					// printf("halo\n");
					cnt |= 1;
					pos1 = pos.back();
					posKali *= pos.back(); pos.pop_back();
					pos2 = pos.back();
					posKali *= pos.back(); pos.pop_back();
				}

				if(neg.size() >= 2){
					cnt |= 2;
					neg1 = neg.back();
					negKali *= neg.back(); neg.pop_back();
					neg2 = neg.back();
					negKali *= neg.back(); neg.pop_back();
				}
				// printf("cnt: %d\n",cnt);

				if(cnt == 0){
					//berarti 0
					printf("0\n");
					return 0;
				}

				// printf("%lld %lld\n",posKali, negKali);

				if(posKali >= negKali){
					if(cnt & 2) {
						neg.pb(neg2); neg.pb(neg1); //balikin neg	
					}
					
					posKali %= mod;
					ans *= posKali;
				}else{
					if(cnt & 1) {
						pos.pb(pos2); pos.pb(pos1); //balikin pos	
					}
					
					negKali %= mod;
					ans *= negKali;
				}

				ans %= mod;
				k-=2;
			}
		}
	}
	
	printf("%lld\n",ans);
	return 0;
};
