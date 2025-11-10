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
typedef pair<string,int> si;
typedef vector<ii> vii;

int getNumDigits(int num) {
	int cnt = 0;
	while(num) {
		num /= 10;
		cnt++;
	}

	return cnt;
}

void solve(){
	int n;
	string f;

	while(cin>>f>>n) {
		if(f == "0" && n == 0) {
			break;
		}

		set<char> s;
		for(char c: f) {
			s.insert(c);
		}

		// string st = string(12, 's');
		// cout<<"st: "<<st<<endl;

		// cout<<f<<" "<<n<<endl;
		queue<pair<string, int>> q;

		bool isVisited[n+1] = {};
		string ans = "impossible";
		for(char c: s) {
			if(c == '0') {
				continue;
			}
			int mod = (c - '0') % n;
			q.push({string(1, c), mod});
			isVisited[mod] = true;
			if(mod == 0) {
				ans = string(1,c);
				break;
			}
		}

		if(ans != "impossible") {
			cout<<ans<<endl;
			continue;
		}

		while(!q.empty() && ans == "impossible") {
			si front = q.front(); q.pop();
			string st = front.first;
			int modResult = front.second;
			// printf("initial modResult: %d\n", modResult);
			for(char c: s) {
				int newModResult = modResult;
				newModResult *= 10;
				newModResult += (c - '0');
				newModResult %= n;
				if(isVisited[newModResult]) {
					continue;
				}

				// printf("pushing, modResult: %d, ", newModResult);
				// cout<<st<< " " << c << " st now: "<<st + c <<endl;
				q.push({st + c, newModResult});
				isVisited[newModResult] = true;
				if(newModResult == 0) {
					ans = st + c;
					break;
				}
			}
		}
		// puts("here");
		cout<<ans<<endl;
	}
	

}

int main(){
	FastSlowInput;
	int tc = 1;
	// scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};