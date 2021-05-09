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

ll strToInt(string s) {
	ll bil = 0;
	int sz = s.size();
	for(int i=0;i<sz;i++){
		int angka = s[i] - '0';
		bil *= 10;
		bil += angka;
	}
	return bil;
}

string intToStr(ll a) {
	string s;
	while(a) {
		int mod = a % 10LL;
		a /= 10LL;
		s += (mod + '0');
	}
	reverse(s.begin(), s.end());
	return s;
}

string trimLeadingZero(string s) {
	int n = s.size();
	string ans;
	bool cukup = false;
	for(int i=0;i<n;i++){
		if(s[i] != '0' || cukup) {
			cukup = true;
			ans += s[i];
		}
	}
	if(ans.size() == 0){
		return "0";
	}
	return ans;
}

bool isBilStrBigger(string a, string b) {
	a = trimLeadingZero(a);
	b = trimLeadingZero(b);
	// printf("a: %s b: %s\n", a.c_str(), b.c_str());
	if(a.size() > b.size()) {
		return true;
	} else if(a.size() < b.size()) {
		return false;
	}
	int sz = a.size();
	for(int i=0;i<sz;i++){
		if(a[i] > b[i]) {
			return true;
		}else if(a[i] < b[i]) {
			return false;
		}
	}
	return false;
}

bool hasLeadingZero(string s) {
	if(s.size() == 0){
		return false;
	}
	return s[0] == '0';
}

bool isRoar(string s) {
	int n = s.size();
	for(int i=0;i<n;i++){
		int pjg = i + 1;
		string strUntilIdx = s.substr(0, pjg);
		string cur = strUntilIdx;

		ll angka = strToInt(strUntilIdx);
		int len = 1;
		while(cur.size() < s.size()) {
			angka++;
			cur += intToStr(angka);
			len++;
		}
		if(len == 1) {return false;}
		if(cur == s){
			return true;
		}
	}
	return false;
}

string solve(string s) {
	int n = s.size();
	int i,j;
	vector<string> list;
	for(i=0;i<n;i++){
		int pjg = i + 1;
		string strUntilIdx = s.substr(0, pjg);
		// printf("sub str pjg: %d: %s\n", pjg, strUntilIdx.c_str());
		for(int tambah = 0;tambah <= 20;tambah++){
			ll angka = strToInt(strUntilIdx);
			angka += tambah;
			ll curAngka = angka;
			string curStr = intToStr(curAngka);
			int steps = 1;
			// printf("first curStr: %s\n", curStr.c_str());
			while(!(isBilStrBigger(curStr, s)) || steps <= 1) {
				curAngka++;
				string newStr = intToStr(curAngka);
				curStr += newStr;
				steps++;
				// printf("curAngka: %d curStr: %s s: %s is curstr bigger: %d\n", curAngka, curStr.c_str(), s.c_str(), isBilStrBigger(curStr, s));
			}
			// printf("tambah: %d final string: %s\n", tambah, curStr.c_str());
			list.pb(curStr);
		}
		for(int tambah = 0;tambah <= 20;tambah++){
			ll angka = strToInt(strUntilIdx);
			angka -= tambah;
			if(angka <= 0){
				break;
			}
			ll curAngka = angka;
			string curStr = intToStr(curAngka);
			int steps = 1;
			// printf("first curStr: %s\n", curStr.c_str());
			while(!(isBilStrBigger(curStr, s)) || steps <= 1) {
				curAngka++;
				string newStr = intToStr(curAngka);
				curStr += newStr;
				steps++;
				// printf("curAngka: %d curStr: %s s: %s is curstr bigger: %d\n", curAngka, curStr.c_str(), s.c_str(), isBilStrBigger(curStr, s));
			}
			// printf("tambah: %d final string: %s\n", tambah, curStr.c_str());
			list.pb(curStr);
		}
	}
	assert(list.size() >= 1);
	sort(list.begin(), list.end(), isBilStrBigger);
	string terakhir = list[list.size() - 1];
	string temp = terakhir;
	assert(temp == trimLeadingZero(terakhir));
	return terakhir;
}

void stressTest() {
	int i,j;

	ll maks = 1000000000000000000;
	for(i=1000000;i<=maks;i++) {
		printf("i: %d\n", i);
		string s = intToStr(i);
		string ans1 = solve(s);
		string ans2;
		for(j=i+1;;j++){
			string str = intToStr(j);
			// printf("j: %d str: %s\n",j, str.c_str());
			if(isRoar(str)){
				// printf("roar at j: %d\n", j);
				ans2 = str;
				break;
			}
		}
		if(ans1 != ans2) {
			printf("wrong answer for i: %d ans1: %s ans2: %s\n", i, ans1.c_str(), ans2.c_str());
		}
	}
}

int main(){
	int tc,i,j,n;

	// printf("intToStr: %s\n", intToStr(123).c_str());
	// printf("intToStr: %s\n", intToStr(1).c_str());
	// printf("strToInt: %lld\n", strToInt("456"));
	// printf("isBigger: %d\n", isBilStrBigger("1", "0"));
	// printf("isBigger: %d\n", isBilStrBigger("1", "1"));
	// printf("isBigger: %d\n", isBilStrBigger("1", "2"));
	// printf("hasLeadingZero: %d\n", hasLeadingZero("01"));
	// printf("hasLeadingZero: %d\n", hasLeadingZero("1"));
	// printf("trimLeadingZero: %s\n", trimLeadingZero("0").c_str());
	// printf("trimLeadingZero: %s\n", trimLeadingZero("001").c_str());
	// printf("trimLeadingZero: %s\n", trimLeadingZero("123").c_str());
	// printf("trimLeadingZero: %s\n", trimLeadingZero("2020").c_str());
	// printf("intToStr: %s\n", intToStr(0).c_str());
	// printf("isRoar: %d\n", isRoar("12"));
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ", tt);
		string s;
		cin>>s;
		printf("%s\n", solve(s).c_str());
	}

	// stressTest();
	
	return 0;
};