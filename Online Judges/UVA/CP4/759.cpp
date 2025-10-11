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

unordered_map<char, int> value = {
	{'M', 1000},
	{'D', 500},
	{'C', 100},
	{'L', 50},
	{'X', 10},
	{'V', 5},
	{'I', 1},
};

unordered_map<int, bool> isValueValid = {
	{1000, true},
	{900, true},
	{500, true},
	{400, true},
	{100, true},
	{90, true},
	{50, true},
	{40, true},
	{10, true},
	{9, true},
	{5, true},
	{4, true},
	{1, true},
};

//checks:
/*
1. if got any characters being there more than 3 times consecutively -> IIII
2. there is any character in which previous value < value now -> CCM -> 100, 900, IIV
3. If there are character in which like this -> IVIII, so basically if minus operation exist, the next character should be lower digit number, cannot be same digit or bigger digit number.
4. If there are invalid minus operation like: IC -> should check if less, should only be CD, CM, XC, XL, IV, IX, other pair cannot be there -> can be checked
//these checks should be added:
5. Multiple 5, 50, and 500 are not allowed...so VV, LL, DD
6. 500+400 should not be allowed
//better to form a vector of integer, then evaluate from this...
IIII
CCM, IIV
IVIII
XM
*/

bool isAnyNumberExceeds3Times(vi breakdowns) {
	unordered_map<int, int> cnt;
	for(int v: breakdowns) {
		cnt[v]++;
		if(cnt[v] > 3) {
			return true;
		}
	}

	return false;
}

bool isValidMinus(vi breakdowns) {
	int shouldBeSmallerThan = inf;
	for(int i=0;i<breakdowns.size();i++){
		int cur = breakdowns[i];
		// printf("cur: %d i: %d shouldBeSmallerThan: %d\n", cur, i, shouldBeSmallerThan);
		if(cur >= shouldBeSmallerThan) {
			return false;
		}

		if(cur == 900 || cur == 400) {shouldBeSmallerThan = 100;}
		else if(cur == 500){shouldBeSmallerThan = 400;}
		else if(cur == 90 || cur == 40) {shouldBeSmallerThan = 10;}
		else if(cur == 50){shouldBeSmallerThan = 40;}
		else if(cur == 9 || cur == 4) {shouldBeSmallerThan = 1;}
		else if(cur == 5){shouldBeSmallerThan = 4;}
	}

	return true;
}

bool isValidRomanNumeral(string s) {
	vi breakdowns;
	//it's safe to do so because s[s.size()] == '\0', which translate to false
	for(int i=0; s[i]; i++){
		if(s[i+1] && value[s[i+1]] > value[s[i]]) {
			breakdowns.pb(value[s[i+1]] - value[s[i]]);
			i++;
		}else{
			breakdowns.pb(value[s[i]]);
		}
	}

	for(int i=0;i<breakdowns.size();i++){
		if(!isValueValid[breakdowns[i]]) {
			return false;
		}
	}

	if(isAnyNumberExceeds3Times(breakdowns)) {
		return false;
	}

	for(int i=0;i<breakdowns.size()-1;i++){
		if(breakdowns[i] < breakdowns[i+1]) {
			return false;
		}
	}

	if(!isValidMinus(breakdowns)) {
		return false;
	}


	return true;
}

int rToA(string s) {
	int res = 0;
	for(int i=0;s[i];i++){
		if(s[i+1] && value[s[i+1]] > value[s[i]]) {
			res += (value[s[i+1]] - value[s[i]]);
			i++;
		}else{
			res += value[s[i]];
		}
	}

	return res;
}

void solve(){
	string s;
	while(cin>>s) {
		if(!isValidRomanNumeral(s)) {
			puts("This is not a valid number");
			continue;
		}

		int res = rToA(s);
		printf("%d\n", res);
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