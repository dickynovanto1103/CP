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

char createRandChar() {
	if(rand() % 2 == 0) {
		return '.';
	}else{
		return '-';
	}
}

string createRandStrWithLen(int n) {
	string ans;
	for(int i=0;i<n;i++){
		ans += createRandChar();
	}
	return ans;
}

map<string, bool> existMap;
int specialLen;

void splitStr(string s) {
	//split 10 10
	int sisa = s.size() % 10;
	if(sisa != 0) {
		specialLen = sisa;
	}

	int banyakKali = s.size() / 10;
	int idx = 0;
	while(banyakKali--) {
		string temp = s.substr(idx, 10);
		existMap[temp] = true;
		idx += 10;
	}

	if(specialLen != -1) {
		existMap[s.substr(idx, specialLen)] = true;
	}
}

bool isValidStr(string s) {
	if(existMap.find(s) != existMap.end()) return false;
	if(specialLen != -1) {
		assert(specialLen < 10);
		string temp = s.substr(0, specialLen);
		if(existMap.find(temp) != existMap.end()) return false;
	}

	return true;
}

int main(){
	srand(time(NULL));

	int tc;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		existMap.clear();
		specialLen = -1;

		printf("Case #%d:\n", tt);
		int n;
		scanf("%d",&n);
		string s;
		cin>>s;

		splitStr(s);

		for(int i=0;i<n-1;i++) {
			string cur;
			while(true) {
				cur = createRandStrWithLen(10);
				if(isValidStr(cur)) {
					existMap[cur] = true;
					// printf("i: %d\n", i);
					// cout<<"valid, size of map now: "<<existMap.size()<<endl;
					break;
				}
			}

			cout<<cur<<endl;
		}
	}
	
	return 0;
};