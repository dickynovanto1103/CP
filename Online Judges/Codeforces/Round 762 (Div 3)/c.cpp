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
// typedef __int128_t lll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int tc,i,j;
	ll a, s;
	scanf("%d",&tc);
	while(tc--){
		scanf("%lld %lld",&a,&s);
		ll b = 0;
		ll kali = 1;
		bool valid = true;
		while(s) {
			// printf("s: %lld\n", s);
			int lastA = a%10;
			int lastS = s%10;
			// printf("a: %lld s: %lld b: %lld\n", a, s, b);
			if(lastA > lastS) {//berarti perlu bagi lagi
				s /= 10;
				int lastSAgain = s % 10;
				if(lastSAgain != 1){
					valid = false;
					b = -1;
					break;
				}
				int angka = 10 + lastS;
				int selisih = angka - lastA;
				b += kali * selisih;
			}else{
				int selisih = lastS - lastA;
				b += kali * selisih;
			}
			a /= 10;
			s /= 10;
			kali *= 10;
		}
		if(a != 0){b = -1;}

		printf("%lld\n", b);
	}
	
	return 0;
};