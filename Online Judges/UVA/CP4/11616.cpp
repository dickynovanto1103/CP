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

map<int, string> intToRoman = {
	{1000, "M"},
	{900, "CM"},
	{500, "D"},
	{400, "CD"},
	{100, "C"},
	{90, "XC"},
	{50, "L"},
	{40, "XL"},
	{10, "X"},
	{9, "IX"},
	{5, "V"},
	{4, "IV"},
	{1, "I"},
};

map<char, int> romanToValue = {
	{'M', 1000},
	{'D', 500},
	{'C', 100},
	{'L', 50},
	{'X', 10},
	{'V', 5},
	{'I', 1},
};

int numbers[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

bool isDigit(char c) {
	return c >= '1' && c <= '9';
}

int convertStringToInt(string s) {
	int value = 0;
	for(int i=0;i<s.size();i++){
		value *= 10;
		value += s[i] - '0';
	}

	return value;
}

string convertIntToRoman(int n) {
	int numbersLen = sizeof(numbers) / sizeof(numbers[0]);
	int value = n;
	string res = "";
	for(int i = 0;i < numbersLen;i++){
		while(value >= numbers[i]) {
			value -= numbers[i];
			res += intToRoman[numbers[i]];
		}
	}

	return res;
}

int convertRomanToInt(string s) {
	int res = 0;
	int i;
	for(i=0;i<s.size() - 1;i++){
		if(romanToValue[s[i]] < romanToValue[s[i+1]]) {
			res += (romanToValue[s[i+1]] - romanToValue[s[i]]);
			i++;
		}else{
			res += romanToValue[s[i]];
		}
	}

	if(i < s.size()) {
		res += romanToValue[s[i]];
	}
	return res;
}

void solve(){
	string s;
	while(cin>>s){
		if(isDigit(s[0])) {
			cout<<convertIntToRoman(convertStringToInt(s))<<endl;
		}else{
			cout<<convertRomanToInt(s)<<endl;
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