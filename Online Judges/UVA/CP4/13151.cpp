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

int getBase(string num) {
	assert(num.size() >= 2);
	if(num[0] >= '1' && num[0] <= '9') {
		return 10;
	}else if(num[0] == '0' && num[1] != 'x') {
		return 8;
	}

	return 16;
}

int convertToIntWithBase(string num, int base) {
	string newS = num;
	if(base == 16) {
		newS = num.substr(2);
	}else if(base == 8) {
		newS = num.substr(1);
	}

	int ans = 0;
	for(int i=0;i<newS.size();i++){
		ans *= base;
		
		int number;
		if(newS[i] >= '0' && newS[i] <= '9') {number = newS[i] - '0';}
		else {
			number = newS[i] - 'A' + 10;
		}
		ans += number;
	}

	return ans;
}

int convertToInt(string num) {
	int base = getBase(num);
	return convertToIntWithBase(num, base);
}

void solve(){
	string num;
	int q;
	while(cin>>num>>q) {
		if(num == "0" && q == 0) {
			break;
		}

		int cur = convertToInt(num);
		// cout<<"num: "<<num<<" cur: "<<cur<<endl;
		int correct = 0;
		while(q--){
			string cmd;
			int res;
			cin>>cmd>>res;

			if(cmd == "i++"){
				if(res == cur) {
					correct++;
				}
				res++;
			}else if(cmd == "i--") {
				if(res == cur) {
					correct++;
				}
				res--;
			}else if(cmd == "++i") {
				cur++;
				if(res == cur) {
					correct++;
				}
			}else if(cmd == "--i") {
				cur--;
				if(res == cur) {
					correct++;
				}
			}else if(cmd == "i") {
				if(res == cur) {
					correct++;
				}
			}

			cur = res;
		}

		printf("%d\n", correct);
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