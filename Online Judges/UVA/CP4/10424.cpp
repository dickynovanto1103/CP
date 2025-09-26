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

int sumDigits(int num) {
	int sum = 0;
	while(num) {
		int digit = num % 10;
		sum += digit;
		num /= 10;
	}

	return sum;
}

int numDigits(int num) {
	if(num == 0) {return 1;}
	int cnt = 0;
	while(num) {
		cnt++;
		num /= 10;
	}

	return cnt;
}

int getResult(string name) {
	int sum = 0;
	for(int i=0;i<name.size();i++){
		char c = name[i];
		
		if(c >= 'A' && c <= 'Z') {
			sum += (c - 'A' + 1);
		}else if(c >= 'a' && c <= 'z') {
			sum += (c - 'a' + 1);
		}
	}

	while(numDigits(sum) > 1) {
		sum = sumDigits(sum);
	}

	return sum;
}

void solve(){
	string name1;
	while(getline(cin, name1)) {
		string name2;
		getline(cin, name2);
		int res1 = getResult(name1);
		int res2 = getResult(name2);
		if(res1 > res2) {
			swap(res1, res2);
		}

		printf("%.2lf %%\n", (double)res1 / res2 * 100);
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