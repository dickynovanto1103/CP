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

vector<is> pairs = {
	{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
	{100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, 
	{10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"},
};

string aToR(int n) {
	string res = "";
	for(auto const&[value, str]: pairs) {
		while(n >= value) {
			res += str;
			n -= value;
		}
	}

	return res;
}

void printPairs() {
	for(auto &[value, str]: pairs) {
		cout<<value<<" "<<str<<endl;
	}
}

unordered_map<char, int> countMap = {
	{'I', 1}, 
	{'V', 2}, 
	{'X', 2}, 
	{'L', 2}, 
	{'C', 2}, 
	{'D', 3}, 
	{'M', 4},
};

int getMatches(string s) {
	int res = 0;
	for(char c: s) {
		res += countMap[c];
	}

	return res;
}

void solve(){
	int n;
	while(scanf("%d",&n) != EOF) {
		string roman = aToR(n);
		printPairs();
		printf("%d\n", getMatches(roman));
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