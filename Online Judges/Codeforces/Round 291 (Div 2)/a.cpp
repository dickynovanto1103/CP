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

string removeLeadingZeros(string s) {
	bool isZero = true;
	string newS;
	for(int i=0;i<s.size();i++){
		if(s[i] == '0') {
			if(isZero) {
				continue;
			}else{
				newS += s[i];
			}
		}else{
			isZero = false;
			newS += s[i];
		}
		
	}

	if(newS.size() == 0) {
		return "9";
	}
	return newS;
}

void solve(){
	string s;
	while(cin>>s) {
		for(int i=0;i<s.size();i++){
			if(s[i] - '0' > (9 - (s[i] - '0'))) {
				int num = 9 - (s[i] - '0');
				s[i] = num + '0';
			}
		}



		cout<<removeLeadingZeros(s)<<endl;
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