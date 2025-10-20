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

vi splitInt(int n) {
	vi res;
	int multiplier = 1;
	while(n) {
		int digit = n % 10;
		digit *= multiplier;
		multiplier *= 10;
		n /= 10;
		res.pb(digit);
	}
	reverse(res.begin(), res.end());

	return res;
}

map<int, string> intToRoman = {
	{1, "i"},
	{4, "iv"},
	{5, "v"},
	{9, "ix"},
	{10, "x"},
	{40, "xl"},
	{50, "l"},
	{90, "xc"},
	{100, "c"},
	{400, "cd"},
	{500, "d"},
	{900, "cm"},
	{1000, "m"},
};

int steps[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

string convertIntToRomanNumeral(int n) {
	string res;
	for(int i=0;i<13;i++) {
		int step = steps[i];
		while(n >= step) {
			n -= step;
			res += intToRoman[step];
		}
	}

	return res;
}

void solve(){
	int n;
	char chars[] = {'i', 'v', 'x', 'l', 'c'};
	while(scanf("%d",&n), n) {
		map<char, int> resMap;
		for(int i=1;i<=n;i++){
			string rom = convertIntToRomanNumeral(i);
			// cout<<"i: "<<i<<" "<<rom<<endl;
			for(char c: rom) {
				resMap[c]++;
			}
		}

		printf("%d:", n);
		for(int i=0;i<5;i++){
			int cnt = resMap[chars[i]];
			printf(" %d %c", cnt, chars[i]);
			if(i < 4) {printf(",");}
		}
		puts("");
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
