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

int getNum(string s) {
	int val = 0;
	for(int i=0;i<s.size();i++){
		val *= 10;
		val += s[i] - '0';
	}

	return val;
}

ii getPecahan(string s) {
	int pembilang = 0;
	int penyebut = 1;
	bool startPenyebut = false;
	for(int i=0;i<s.size();i++){
		if(s[i] == '.'){
			startPenyebut = true;
			continue;
		}

		pembilang *= 10;
		pembilang += s[i] - '0';

		if(startPenyebut) {
			penyebut *= 10;
		}
	}

	// printf("before gcd, pembilang: %d, penyebut: %d\n", pembilang, penyebut);
	int gcd = __gcd(pembilang, penyebut);
	return ii(pembilang / gcd, penyebut / gcd);
}

void solve(){
	string s;
	while(cin>>s){
		int l, r;
		scanf("%d %d",&l,&r);

		ii pecahan = getPecahan(s);
		int minSum = l * pecahan.second, maksSum = r * pecahan.second;
		if(pecahan.first > maksSum || pecahan.first < minSum) {
			puts("-1");
			return;
		}

		int floor = pecahan.first / pecahan.second;
		int ceiling = (pecahan.first + pecahan.second - 1) / pecahan.second;

		printf("%d\n", pecahan.second);
		int remaining = pecahan.first;
		if(floor == ceiling) {
			for(int i=0;i<pecahan.second;i++){
				if(i) {printf(" ");}
				printf("%d", floor);
			}	
			puts("");
		}else{
			ll numFloor = ((ll)pecahan.first - (ll)ceiling * (ll)pecahan.second) / (floor - ceiling);
			ll numCeil = pecahan.second - numFloor;
			vi res;
			for(int i=0;i<numFloor;i++){
				res.pb(floor);
			}

			for(int i=0;i<numCeil;i++){
				res.pb(ceiling);
			}

			for(int i=0;i<pecahan.second;i++){
				if(i) {printf(" ");}
				printf("%d", res[i]);
			}
			puts("");
		}
		
	}
}

int main(){
	int tc = 1;
	// scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};