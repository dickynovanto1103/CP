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

int d, m, y;


int convertMonthStringToInt(string s) {
	switch(s) {
	case "January":
		return 1;
	case "February":
		return 2;
	case "March":
		return 3;
	}
} 

void parse(string s) {
	int idx;
	int yy = 0;
	for(int i=0;i<s.size();i++){
		if(s[i] == '-') {
			idx = i;
			break;
		}
		yy *= 10;
		yy += (s[i] - '0');
	}

	string month;
	for(int i=idx+1;i<s.size();i++){
		if(s[i] == '-') {
			idx = i;
			break;
		}
		month += s[i];
	}

	int dd;
	for(int i=idx+1;i<s.size();i++){

	}
}


void solve(){
	string s;
	cin>>s;
	int add;

	scanf("%d",&add);
	cout<<s<<" add: "<<add<<endl;
}

int main(){
	int tc = 1;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case %d: ", tt);
		solve();
	}

	return 0;
};