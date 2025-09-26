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

//123876347837482735872834782748273847283748274872387428748274 60 2 1 1
// 42 2 1
int numDigit(int num) {
	if(num == 0) {return 1;}
	int cnt = 0;
	while(num) {
		num /= 10;
		cnt++;
	}

	return cnt;
}

void solve(){
	string s;
	while(cin>>s && s != "END") {
		if(s.size() == 1) {
			if(s == "1") {
				puts("1");
			}else{
				puts("2");
			}
			continue;
		}
		int prevNumDigits = s.size();
		int idx = 2;
		int numDigits = numDigit(prevNumDigits);
		while(numDigits != prevNumDigits) {
			prevNumDigits = numDigits;
			numDigits = numDigit(numDigits);
			idx++;
		}
		printf("%d\n", idx);
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