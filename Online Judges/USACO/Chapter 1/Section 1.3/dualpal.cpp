/*
ID: dickyno1
LANG: C++14
TASK: dualpal
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

string convertToBase(int num, int base) {
	string s;
	char c[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
	while(num) {
		int mod = num % base;
		if(mod <= 9) {
			s += mod + '0';
		}else{
			mod -= 10;
			char kar = c[mod];
			s += kar;
		}
		num /= base;
	}
	reverse(s.begin(), s.end());
	// cout<<s<<endl;
	return s;
}

bool isPalindrome(string s) {
	int n = s.size();
	for(int i=0;i<n/2;i++) {
		if(s[i] != s[n - 1 - i]) return false;
	}
	return true;
}

int main(){
	freopen("dualpal.in", "r", stdin);
	freopen("dualpal.out", "w", stdout);

	int n, num;
	scanf("%d %d",&n, &num);
	int cnt = 0;
	for(int i=num+1;;i++){
		int cntPalin = 0;
		for(int b=2; b<=10;b++){
			string s = convertToBase(i, b);
			if(isPalindrome(s)) {
				cntPalin++;
				if(cntPalin >= 2){break;}
			}
		}
		if(cntPalin == 2) {
			printf("%d\n", i);
			cnt++;
		}
		if(cnt == n){
			break;
		}
	}
	
	return 0;
};