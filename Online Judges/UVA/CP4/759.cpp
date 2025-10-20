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
typedef pair<int,string> is;
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

bool is5OnlyOnce(string s) {
	int cnt5 = 0, cnt50 = 0, cnt500 = 0;
	for(int i=0;i<s.size();i++){
		if(s[i] == 'V') {cnt5++;}
		else if(s[i] == 'L') {cnt50++;}
		else if(s[i] == 'D') {cnt500++;}
	}

	return cnt5 <= 1 && cnt50 <= 1 && cnt500 <= 1;
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
		else if(cur == 90 || cur == 40) {shouldBeSmallerThan = 10;}
		else if(cur == 9 || cur == 4) {shouldBeSmallerThan = 1;}
	}

	return true;
}

bool isValidMinusCheck(string s, int i) {
	string value = s.substr(i, 2);
	// cout<<"value: "<< value<<endl;
	//CD, CM, XC, XL, IV, IX
	return value == "CD" || value == "CM" || value == "XC" || value == "XL" || value == "IV" || value == "IX";
}

bool isValidRomanNumeral(string s) {
	if(!is5OnlyOnce(s)){
		return false;
	}
	vi breakdowns;
	//it's safe to do so because s[s.size()] == '\0', which translate to false
	for(int i=0; s[i]; i++){
		if(s[i+1] && value[s[i+1]] > value[s[i]]) {
			if(!isValidMinusCheck(s, i)) {
				return false;
			}
			breakdowns.pb(value[s[i+1]] - value[s[i]]);
			i++;
		}else{
			breakdowns.pb(value[s[i]]);
		}
	}

	// printf("breakdowns:");
	// for(int val: breakdowns) {
	// 	printf(" %d", val);
	// }
	// puts("");

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

//MMMDCCCLXXXVIII

char romans[] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};

vector<is> valToRoman = {
	{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
	{100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
	{10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"},
	{1, "I"},
};

string aToR(int n) {
	string res;
	for(auto &[value, str]: valToRoman) {
		while(n >= value) {
			n -= value;
			res += str;
		}
	}

	return res;
}

void validate(string s) {
	int res = rToA(s);
	printf("res: %d\n", res);
	if(res >= 4000) {
		if(isValidRomanNumeral(s)){
			cout<<"res >= 4000, but considered as valid, s: "<<s<<endl;
			assert(false);
		}
		return;
	}
	string expectedRomanStr = aToR(res);
	cout<<"s: "<<s<<" expectedRomanStr: "<<expectedRomanStr<<endl;
	if(s == expectedRomanStr) {
		if(!isValidRomanNumeral(s)) {
			cout<<"SAME but INVALID s: "<<s<<" expectedRomanStr: "<<expectedRomanStr<<" but s is not valid"<<endl;
			assert(false);
		}
	}else {
		if(isValidRomanNumeral(s)) {
			cout<<"NOT SAME but VALID s: "<<s<<" expectedRomanStr: "<<expectedRomanStr<<" but s is valid"<<endl;
			assert(false);
		}
	}
}

void genRomanWithDigit(int numDigit, string curStr) {
	if(curStr.size() == numDigit) {
		// printf("numDigit: %d curStr: ", numDigit); cout<<curStr<<endl;
		validate(curStr);
		return;
	}
	for(int i=0;i<7;i++) {
		genRomanWithDigit(numDigit, curStr + romans[i]);
	}
	
}

void genRomanAndValidate(int numDigit) {
	genRomanWithDigit(numDigit, "");
}

void genAndVerify() {
	for(int numDigit = 1;numDigit <= 15;numDigit++) {
		genRomanAndValidate(numDigit);
	}
}


void solve(){
	string s;
	while(getline(cin, s)) {
		if(s.size() == 0){
			puts("0");
			continue;
		}
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
	// genAndVerify();
	// scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};