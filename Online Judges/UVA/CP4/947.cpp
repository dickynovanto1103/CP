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

ii getRes(string expected, string guess) {
	int len = expected.size();
	assert(len == guess.size());
	bool isSame[len + 1] = {false};

	vector<int> v[10];
	int correct = 0, wrongPlace = 0;
	for(int i=0;i<len;i++){
		if(expected[i] == guess[i]) {
			isSame[i] = true;
			correct++;
		}else{
			int num = expected[i] - '0';
			v[num].pb(i);
		}
	}

	for(int i=0;i<len;i++){
		if(isSame[i]) {
			continue;
		}

		int num = guess[i] - '0';
		if(v[num].size()) {
			v[num].pop_back();
			wrongPlace++;
		}
	}

	return ii(correct, wrongPlace);
}

bool isContain0(int num) {
	while(num) {
		int digit = num % 10;
		if(digit == 0) {
			return true;
		}
		num /= 10;
	}

	return false;
}

int getNumber(int len, int num) {
	int ans = 0;
	for(int i=0;i<len;i++){
		ans *= 10;
		ans += num;
	}

	return ans;
}

void solve(){
	string s;
	int correct, wrongPlace;
	cin>>s>>correct>>wrongPlace;
	int len = s.size();
	int firstNum = getNumber(len, 1), lastNum = getNumber(len, 9);
	// cout<<s<<" ";
	// printf("firstNum: %d, lastNum: %d\n", firstNum, lastNum);
	int cnt = 0;
	for(int i=firstNum; i <= lastNum;i++) {
		if(isContain0(i)){
			continue;
		}
		
		ii res = getRes(s, to_string(i));
		if(res.first == correct && res.second == wrongPlace) {
			// printf("i: %d, res: %d %d\n", i, res.first, res.second);
			cnt++;
		}
	}

	printf("%d\n", cnt);
}

int main(){
	int tc = 1;
	scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};