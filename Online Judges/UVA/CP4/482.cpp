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

bool isDigit(char c) {
	return c >= '0' && c <= '9';
}

vi parseStrToIntegers(string s) {
	vi res;
	int v = 0;
	for(char c: s) {
		if(isDigit(c)) {
			v *= 10;
			v += c - '0';
		}else{
			res.pb(v - 1);
			v = 0;
		}
	}
	if(v > 0) {
		res.pb(v - 1);
	}
	return res;
}

vector<string> parseStrToArrayOfString(string s) {
	vector<string> res;
	string temp;
	for(char c: s) {
		if(c == ' ') {
			res.pb(temp);
			temp = "";
		}else{
			temp += c;
		}
	}

	if(temp.size() > 0) {
		res.pb(temp);
	}

	return res;
}

void solve(){
	string s;
	vi idxs;
	while(s.size() == 0) {
		getline(cin, s);
		idxs = parseStrToIntegers(s);
	}
	string arrStr;
	getline(cin, arrStr);
	vector<string> arr = parseStrToArrayOfString(arrStr);
	vector<is> pairs;
	assert(idxs.size() == arr.size());
	for(int i=0;i<idxs.size();i++){
		pairs.pb(is(idxs[i], arr[i]));
	}

	sort(pairs.begin(), pairs.end());
	for(int i=0;i<pairs.size();i++) {
		cout<<pairs[i].second<<endl;
	}
}

int main(){
	int tc = 1;
	scanf("%d",&tc);
	while(tc--){
		solve();
		if(tc) {puts("");}
	}

	return 0;
};