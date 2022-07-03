/*
ID: dickyno1
LANG: C++14
TASK: lamps
*/

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

char swap(char c) {
	return c == '0' ? '1' : '0';
}

string op1(string s) {
	for(int i=0;i<s.size();i++){
		s[i] = swap(s[i]);
	}
	return s;
}

string op2(string s) {
	for(int i=0;i<s.size();i++){
		if(i % 2 == 0){
			s[i] = swap(s[i]);
		}
	}
	return s;
}

string op3(string s) {
	for(int i=0;i<s.size();i++){
		if(i % 2 == 1){
			s[i] = swap(s[i]);
		}
	}
	return s;
}

string op4(string s) {
	for(int i=0;i<s.size();i++){
		if(i % 3 == 0){
			s[i] = swap(s[i]);
		}
	}
	return s;
}


string doOperation(string s, int num) {
	if(num == 1) {
		s = op1(s);
	}else if(num == 2){
		s = op2(s);
	}else if(num == 3) {
		s = op3(s);
	}else if(num == 4){
		s = op4(s);
	}else{
		assert(false);
	}
	return s;
}

map<string, bool> mapper;
vector<string> v;
vector<vector<string> > vs;

void generateAllPossibility(string s, int step) {
	if(step == 0){
		if(mapper.find(s) == mapper.end()) {
			v.pb(s);
			// cout<<"in rec func s:"<<s<<endl;
			mapper[s] = true;
		}
		return;
	}

	for(int i=1;i<=4;i++){
		string newS = doOperation(s, i);
		generateAllPossibility(newS, step - 1);
	}
}

bool fulfilCriteria(string s, vi onList, vi offList) {
	for(int idxOn: onList) {
		if(s[idxOn] == '0'){
			return false;
		}
	}

	for(int idxOff: offList) {
		if(s[idxOff] == '1'){
			return false;
		}
	}

	return true;
}

int main(){
	freopen("lamps.in", "r", stdin);
	freopen("lamps.out", "w", stdout);

	int n, c;
	scanf("%d %d",&n, &c);

	vi onList, offList;
	int num;
	while(scanf("%d",&num) && num != -1) {
		num--;
		onList.pb(num);
	}

	while(scanf("%d",&num) && num != -1) {
		num--;
		offList.pb(num);
	}

	string s;
	for(int i=0;i<n;i++){
		s += '1';
	}

	vs.assign(4, vector<string>());
	for(int i=0;i<=3;i++){
		generateAllPossibility(s, i);
		sort(v.begin(), v.end());
		vs[i] = v;
		v.clear();
		mapper.clear();
	}
	
	c = min(c, 3);
	vector<string> ans;
	for(int i=0;i<vs[c].size();i++){
		string st = vs[c][i];
		// cout<<"st: "<<st<<endl;
		if(fulfilCriteria(st, onList, offList)) {
			ans.pb(st);
		}
	}

	if(ans.size() == 0){puts("IMPOSSIBLE");}
	else{
		for(string s: ans){
			cout<<s<<endl;
		}
	}
	
	return 0;
};