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

int numDigit(int n){
	int cnt = 0;
	while(n){
		n/=10;
		cnt++;
	}
	return cnt;
}

ll power(ll a, ll b){
	if(b == 0){return 1;}
	else{
		if(b%2 == 1){return a*power(a,b-1);}
		else{
			ll temp = power(a,b/2);
			return temp*temp;
		}
	}
}

int main(){
	int q;
	ll k;
	scanf("%d",&q);
	ll numDigit[123];
	numDigit[1] = 9;
	int i;
	ll pangkat10 = 10;
	for(i=2;i<=19;i++){
		pangkat10*=10;
		numDigit[i] = ((pangkat10-1) - (pangkat10/10)+1)*(ll)i;
	}
	while(q--){
		scanf("%lld",&k);
		int digit = 1;
		ll tot = k;
		ll banyak = 0;
		for(i=1;i<=100000;i++){
			int banyakDigit = numDigit[i];
			ll temp = banyak + banyakDigit;
			if(tot > temp){
				tot -= temp;
				banyak = temp;
			}else{
				break;
			}
		}
		banyak = 0;
		int ans = -1;
		for(i=1;i<=17;i++){
			banyak += numDigit[i];
			if(tot > banyak){
				tot -= banyak;
			}else{
				int bil = (tot+i-1) / i;

				bil += power(10,i);
				bil--;
				printf("bil: %d\n",bil);
				int sisa = tot % i;
				while(bil){
					int angka = bil % 10;
					if(sisa == 0){
						ans = angka;
						break;
					}
					bil /= 10;
					sisa--;

				}
				if(ans != -1){
					break;
				}
			}
		}

		printf("%d\n",ans);
	}
	return 0;
};